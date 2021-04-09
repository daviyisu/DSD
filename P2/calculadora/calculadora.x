typedef struct mivector *v;

struct mivector{  
	int a;
	int b;
	int c;
};


program CALCPROG {
	version CALCVER {
		int suma(int, int) = 1;
		int resta(int, int) = 2;
		int multiplicacion(int, int) = 3;
		int division(int, int) = 4;
		mivector sumavectores(mivector, mivector) = 5;
		mivector restavectores(mivector, mivector) = 6;
		int multiplicacionescalar(mivector, mivector) = 7;
		mivector multiplicacionvectorial(mivector, mivector) = 8;
	} =1;
} = 0x20000001;
