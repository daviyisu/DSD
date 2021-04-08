/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "calculadora.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

int *
suma_1(int arg1, int arg2,  CLIENT *clnt)
{
	suma_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, suma, (xdrproc_t) xdr_suma_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
resta_1(int arg1, int arg2,  CLIENT *clnt)
{
	resta_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, resta, (xdrproc_t) xdr_resta_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
multiplicacion_1(int arg1, int arg2,  CLIENT *clnt)
{
	multiplicacion_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, multiplicacion, (xdrproc_t) xdr_multiplicacion_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

int *
division_1(int arg1, int arg2,  CLIENT *clnt)
{
	division_1_argument arg;
	static int clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, division, (xdrproc_t) xdr_division_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_int, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

mivector *
sumavectores_1(mivector arg1, mivector arg2,  CLIENT *clnt)
{
	sumavectores_1_argument arg;
	static mivector clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, sumavectores, (xdrproc_t) xdr_sumavectores_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_mivector, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

mivector *
restavectores_1(mivector arg1, mivector arg2,  CLIENT *clnt)
{
	restavectores_1_argument arg;
	static mivector clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, restavectores, (xdrproc_t) xdr_restavectores_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_mivector, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

mivector *
multiplicacionvectores_1(mivector arg1, mivector arg2,  CLIENT *clnt)
{
	multiplicacionvectores_1_argument arg;
	static mivector clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, multiplicacionvectores, (xdrproc_t) xdr_multiplicacionvectores_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_mivector, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

mivector *
divisionvectore_1(mivector arg1, mivector arg2,  CLIENT *clnt)
{
	divisionvectore_1_argument arg;
	static mivector clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	if (clnt_call (clnt, divisionvectore, (xdrproc_t) xdr_divisionvectore_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_mivector, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
