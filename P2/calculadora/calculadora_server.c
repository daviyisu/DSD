#include "calculadora.h"

int *
suma_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{
	static int  result;

	result = arg1 + arg2;

	return &result;
}

int *
resta_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{
	static int  result;

	result = arg1 - arg2;

	return &result;
}

int *
multiplicacion_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{
	static int  result;

	result = arg1 * arg2;

	return &result;
}

int *
division_1_svc(int arg1, int arg2,  struct svc_req *rqstp)
{
	static int  result;
	result = 0;
	if(arg2 !=0){
	result = arg1 / arg2;
}

	return &result;
}

mivector *
sumavectores_1_svc(mivector arg1, mivector arg2,  struct svc_req *rqstp)
{
	static mivector  result;

	result.a = arg1.a + arg2.a;
	result.b = arg1.b + arg2.b;
	result.c = arg1.c + arg2.c;

	return &result;
}

mivector *
restavectores_1_svc(mivector arg1, mivector arg2,  struct svc_req *rqstp)
{
	static mivector  result;

	result.a = arg1.a - arg2.a;
	result.b = arg1.b - arg2.b;
	result.c = arg1.c - arg2.c;

	return &result;
}


int *
multiplicacionescalar_1_svc(mivector arg1, mivector arg2,  struct svc_req *rqstp)
{
	static int  result;

	result = (arg1.a * arg2.a) + (arg1.b * arg2.b) + (arg1.c * arg2.c);

	return &result;
}

mivector *
multiplicacionvectorial_1_svc(mivector arg1, mivector arg2,  struct svc_req *rqstp)
{
	static mivector  result;

	result.a = (arg1.b * arg2.c) - (arg1.c * arg2.b);
	result.b = (arg1.c * arg2.a) - (arg1.a * arg2.c);
	result.c = (arg1.a * arg2.b) - (arg1.b * arg2.a);

	return &result;
}
