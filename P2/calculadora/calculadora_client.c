#include "stdbool.h"
#include "calculadora.h"

void calcprog_1(char *host, int primer, char operacion, int segundo, mivector v1, mivector v2, int menu)
{
	CLIENT *clnt;
	int *result_1;
	int suma_1_arg1;
	int suma_1_arg2;
	int *result_2;
	int resta_1_arg1;
	int resta_1_arg2;
	int *result_3;
	int multiplicacion_1_arg1;
	int multiplicacion_1_arg2;
	int *result_4;
	int division_1_arg1;
	int division_1_arg2;
	mivector *result_5;
	mivector sumavectores_1_arg1;
	mivector sumavectores_1_arg2;
	mivector *result_6;
	mivector restavectores_1_arg1;
	mivector restavectores_1_arg2;
	int *result_7;
	mivector multiplicacionescalar_1_arg1;
	mivector multiplicacionescalar_1_arg2;
	mivector *result_8;
	mivector multiplicacionvectorial_1_arg1;
	mivector multiplicacionvectorial_1_arg2;

#ifndef DEBUG
	clnt = clnt_create(host, CALCPROG, CALCVER, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */

	if (menu == 1)
	{
		switch (operacion)
		{

		case '+':
			result_1 = suma_1(primer, segundo, clnt);
			if (result_1 == (int *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El resultado de la suma es: %d\n", *result_1);
			break;

		case '-':
			result_2 = resta_1(primer, segundo, clnt);
			if (result_2 == (int *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El resultado de la resta es: %d\n", *result_2);
			break;

		case '*':
			result_3 = multiplicacion_1(primer, segundo, clnt);
			if (result_3 == (int *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El resultado de la multiplicacion es: %d\n", *result_3);
			break;

		case '/':
			if (segundo == 0)
			{
				printf("No se puede dividir entre 0\n");
			}
			else
			{
				result_4 = division_1(primer, segundo, clnt);
				if (result_4 == (int *)NULL)
				{
					clnt_perror(clnt, "call failed");
				}
				printf("El resultado de la division es: %d\n", *result_4);
				break;
			}
		}
	}
	else
	{
		switch (operacion)
		{
		case '+':
			result_5 = sumavectores_1(v1, v2, clnt);
			if (result_5 == (mivector *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El vector suma es: (%d, %d, %d)\n", result_5->a, result_5->b, result_5->c);
			break;

		case '-':
			result_6 = restavectores_1(v1, v2, clnt);
			if (result_6 == (mivector *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El vector resta es: (%d, %d, %d)\n", result_6->a, result_6->b, result_6->c);
			break;

		case '*':
			result_7 = multiplicacionescalar_1(v1, v2, clnt);
			if (result_7 == (int *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El producto escalar es: %d\n", *result_7);
			break;

		case 'x':

			result_8 = multiplicacionvectorial_1(v1, v2, clnt);
			if (result_8 == (mivector *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			printf("El producto vectorial es: (%d, %d, %d)\n", result_8->a, result_8->b, result_8->c);

			break;

		default:
			break;
		}
	}
#ifndef DEBUG
	clnt_destroy(clnt);
#endif /* DEBUG */
}

bool_t comprobarOperacion(char oper)
{
	bool_t found = false;
	char lista[5] = {'+', '-', '*', 'x', '/'};
	for (size_t i = 0; i < 5 && !found; i++)
	{

		if (oper == lista[i])
		{
			found = true;
		}
	}

	return found;
}

int main(int argc, char *argv[])
{
	mivector v1, v2;
	bool_t badOperation;
	char *host;
	char operacion;
	int primer, segundo, resultado, menu;
	resultado = 0;
	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];

	while (menu != 3)
	{
		//menu = -1;
		printf("Elija opción de calculadora\n");
		printf("1.- Operaciones con enteros\n"
			   "2.- Operaciones con vectores\n"
			   "3.- Cerrar programa\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("Ingrese primer operando\n");
			scanf("%d", &primer);
			//fflush(stdin);
			printf("Ingrese segundo operando\n");
			scanf("%d", &segundo);
			//fflush(stdin);
			printf("Ingrese operación ('+','-','*','/')\n");
			scanf(" %c", &operacion);
			//fflush(stdin);
			if (!comprobarOperacion(operacion))
			{
				badOperation = false;
				while (!badOperation)
				{
					printf("Ingrese operación válida('+','-','*','/')\n");
					scanf(" %c", &operacion);
					badOperation = comprobarOperacion(operacion);
					fflush(stdin);
				}
			}
			calcprog_1(host, primer, operacion, segundo, v1, v2, 1);
			break;

		case 2:
			//printf("En proceso\n");

			printf("Ingresa los valores enteros del primer vector separados por un espacio\n");
			scanf("%d"
				  "%d"
				  "%d",
				  &v1.a, &v1.b, &v1.c);
			printf("Ingresa los valores enteros del segundo vector separados por un espacio\n");
			scanf("%d"
				  "%d"
				  "%d",
				  &v2.a, &v2.b, &v2.c);
			//printf("v1: (%d,%d)  v2: (%d,%d)\n", v1.a, v1.b, v2.a, v2.b);
			printf("Ingrese operación ('+','-','*','x')\n");
			scanf(" %c", &operacion);
			//fflush(stdin);
			if (!comprobarOperacion(operacion))
			{
				badOperation = false;
				while (!badOperation)
				{
					printf("Ingrese operación válida('+','-','*','x')\n");
					scanf(" %c", &operacion);
					badOperation = comprobarOperacion(operacion);
					fflush(stdin);
				}
			}
			calcprog_1(host, primer, operacion, segundo, v1, v2, 2);
			break;

		case 3:
			printf("Hasta pronto!\n");
			break;
		default:
			printf("Opción errónea\n");
			break;
		}
		fflush(stdin);
	}
}
