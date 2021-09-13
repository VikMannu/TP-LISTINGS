//Listing 4.9 (cxx-exit.cpp) Implementing Safe Thread Exit with C++ Exceptions

#include <pthread.h>
#include <iostream>

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


//Funcion fibonacci para el trabajo a realizar
int fibonacci(int n){
    if(n==1){
        return 1;
    }else if(n==0){
        return 0;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
//hacemos el trabajo
void do_some_work()
{
    int j=1;
    while (1)
    {
        /* Do some useful things here... */
        /* Haz algunas cosas útiles aquí ... */
        int fibo=fibonacci(j);
        std :: cout << "Fibonacci"<< j <<"=" << fibo << "\n";
        if (j==10)
            throw ThreadExitException(/* thread’s return value = */ NULL);
        j++;
    }
}
//funcion del hilo
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

//funcion main
int main(){
	pthread_t hilo;
    //creamos el hilo
	pthread_create(&hilo, NULL, &thread_function, NULL);
    //hacemos el jpom
	pthread_join(hilo, NULL);
	return 0;
}