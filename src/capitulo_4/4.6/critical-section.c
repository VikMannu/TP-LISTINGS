//Listing 4.6 (critical-section.c) Protect a Bank Transaction with a Critical Section

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* An array of balances in accounts, indexed by account number. */
/* Una serie de saldos en cuentas, indexados por número de cuenta. */
float *account_balances;

/* Transfer DOLLARS from account FROM_ACCT to account TO_ACCT. Return
0 if the transaction succeeded, or 1 if the balance FROM_ACCT is
too small. */
/* Transferir DÓLARES de la cuenta FROM_ACCT a la cuenta TO_ACCT. 
Devuelve 0 si la transacción se realizó correctamente o 1 si el 
saldo FROM_ACCT es demasiado pequeño. */
int process_transaction(int from_acct, int to_acct, float dollars)
{
	int old_cancel_state;
	/* Check the balance in FROM_ACCT. */
	/* Consulta el saldo en FROM_ACCT. */
	if (account_balances[from_acct] < dollars)
		return 1;
	/* Begin critical section. */
	/* Comienza la sección crítica. */
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);
	/* Move the money. */
	/* Mueve el dinero. */
	account_balances[to_acct] += dollars;
	account_balances[from_acct] -= dollars;
	/* End critical section. */
	/* Fin de la sección crítica. */
	pthread_setcancelstate(old_cancel_state, NULL);
	return 0;
}

int main()
{

	account_balances = (float*) malloc(sizeof(float)*5);
	for(int i = 0; i < 5; i++) {
		account_balances[i] = 10000;
	}

	int resultado = process_transaction(1, 2, 5000);

	if(resultado == 0)
		printf("\nLa transacción se realizó correctamente\n");
	else
		printf("\nLa transacción no pudo realizarse\n");

	return 0;
}