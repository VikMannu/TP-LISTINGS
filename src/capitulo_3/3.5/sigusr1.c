#include <signal.h> 
#include <stdio.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h> 
sig_atomic_t sigusr1_count = 0; 
void handler (int signal_number) 
{ 
 ++sigusr1_count; 
} 
int main () 
{ 
 struct sigaction sa; 
 memset (&sa, 0, sizeof (sa)); 
 sa.sa_handler = &handler; 
 sigaction (SIGUSR1, &sa, NULL); 
 /* Do some lengthy stuff here. */ 
 /* ... */
 int i =0;
 //profe no pude entender en el libro como es que debe enviar la señal al programa para que la funcion handler se dispare
 while(i<999999){
     i++;
     signal(SIGUSR1,handler);
 }
 printf ("SIGUSR1 was raised %d times\n", sigusr1_count); 
 return 0; 
}