//Listing 4.9 (cxx-exit.cpp) Implementing Safe Thread Exit with C++ Exceptions

#include <pthread.h>

class ThreadExitException
{
    public:
        /* Create an exception-signaling thread exit with RETURN_VALUE. */
        /* Crea una salida de subproceso de señalización de excepción con RETURN_VALUE. */
        ThreadExitException(void *return_value)
            : thread_return_value_(return_value)
        {
        }
        /* Actually exit the thread, using the return value provided in the
        constructor. */
        /* Realmente sale del hilo, usando el valor de retorno provisto en el constructor. */
        void *DoThreadExit()
        {
            pthread_exit(thread_return_value_);
        }

    private:
        /* The return value that will be used when exiting the thread. */
        /* El valor de retorno que se usará al salir del hilo. */
        void *thread_return_value_;
};

void do_some_work()
{
    while (1)
    {
        /* Do some useful things here... */
        /* Haz algunas cosas útiles aquí ... */
        if (should_exit_thread_immediately())
            throw ThreadExitException(/* thread’s return value = */ NULL);
    }
}

void *thread_function(void *)
{
    try
    {
        do_some_work();
    }
    catch (ThreadExitException ex)
    {
        /* Some function indicated that we should exit the thread. */
        /* Alguna función indicó que deberíamos salir del hilo. */
        ex.DoThreadExit();
    }
    return NULL;
}