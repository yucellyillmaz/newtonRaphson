#include<stdio.h>
#include<math.h>

#define EPSILON 0.0001

double func(double x){
    return x*x*x - x*x + 2;
}

double derivFunc(double x){
    return 3*x*x - 2*x;
}
 
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    int noroot = 0;
    while (fabs(h) >= EPSILON)
    {
        h = func(x)/derivFunc(x);
        x = x - h;      
        
		if (x == 0.0)
        {
            noroot++;
            printf("No roots exist!");
        }
    }
    if (noroot == 0)
        printf("\nThe value of the root is : %.1f", x);
}
 
int main()
{
    double x0 = -20; 
    newtonRaphson(x0);
    return 0;
}




/*
x0 = 1 + 2i için; complex sayi hesaplamasi icin gerekli kutuphaneyi cagiriyoruz.
Derleyici GCC 7.1 var suan online editorde, derleyici eski ise calismayacaktir.


#include <stdio.h>
#include <complex.h>
#include <math.h>

#define EPSILON 0.0001

double complex func(double complex x)
{
	return x*x*x - x*x + 2;
}

double complex derivFunc(double complex x)
{
	return 3*x*x - 2*x;
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
	double complex x0 = -20.0 + 1.0 * I;
	newtonRaphson(x0);
	return 0;
}

*/
