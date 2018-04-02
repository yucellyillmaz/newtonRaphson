/*
x0 = 1 + 2i için; complex sayi hesaplamasi icin gerekli kutuphaneyi cagiriyoruz.
Derleyici GCC 7.1 var suan online editorde, derleyici eski ise calismayacaktir.
*/

#include <stdio.h>
#include <complex.h>
#include <math.h>

#define EPSILON 0.000001

double complex func(double complex x)
{
	return x * x + 1;
}

double complex derivFunc(double complex x)
{
	return 2 * x;
}

void newtonRaphson(double complex x)
{
	double complex h = func(creal(x))/derivFunc(creal(x));
	h = func(cimag(x))/derivFunc(cimag(x));
	int noroot = 0;
	while (fabs(creal(h)) >= EPSILON)
	{
	    h = func(x) / derivFunc(x);
		x = creal(x) - creal(h);
		if (x == 0.0)
        {
            noroot++;
            printf("No roots exist!");
        }
	}
	if (noroot == 0)
    printf("The value of the root is : %.1f%+.1fi\n", creal(x), cimag(x));
}

int main()
{
	double complex x0 = 1.0 + 2.0 * I;
	newtonRaphson(x0);
	return 0;
}

