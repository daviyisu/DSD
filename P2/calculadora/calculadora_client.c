/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"
#include "stdlib.h"

void
calcprog_1(char *host, int primer, char operacion, int segundo)
{
	CLIENT *clnt;
	int  *result_1;
	int suma_1_arg1;
	int suma_1_arg2;
	int  *result_2;
	int resta_1_arg1;
	int resta_1_arg2;
	int  *result_3;
	int multiplicacion_1_arg1;
	int multiplicacion_1_arg2;
	int  *result_4;
	int division_1_arg1;
	int division_1_arg2;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCPROG, CALCVER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */


	switch(operacion){
		
		case '+':
		result_1 = suma_1(primer, segundo, clnt);
		if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		printf("El resultado de la suma es: %d\n",*result_1);
		break;
		
		case '-':
		result_2 = resta_1(primer, segundo, clnt);
		if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		printf("El resultado de la resta es: %d\n",*result_2);
		break;

		case '*':
		result_3 = multiplicacion_1(primer, segundo, clnt);
		if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		printf("El resultado de la multiplicacion es: %d\n",*result_3);
		break;

		case '/':
		if(segundo == 0){
			printf("No se puede dividir entre 0\n");
		}else{
		result_4 = division_1(primer, segundo, clnt);
		if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		printf("El resultado de la division es: %d\n",*result_4);
		break;
		}
}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char operacion;
	int primer, segundo, resultado;
	resultado = 0;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	primer = atoi(argv[2]);
	operacion = *argv[3];
	segundo = atoi(argv[4]);
	host = argv[1];
	calcprog_1 (host, primer, operacion, segundo);
}
