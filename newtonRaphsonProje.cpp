	#include<stdio.h>
#include<math.h>

#define EPSILON 0.000001

double func(double x){
    return x * x + 1;
}

double derivFunc(double x){
    return 2 * x;
}
 
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    int noroot = 0;
    int counter = 0;
    while (fabs(h) >= EPSILON)
    {
        h = func(x)/derivFunc(x);
        x = x - h;      
        
		if (x == 0.0)
        {
            noroot++;
            printf("No roots exist!");
        }
        if (++counter == 100000000)
        {
        	printf("\nAfter 100 million loops, approximate root is: %.1f", x);
		}
    }
    if (noroot == 0)
        printf("\nThe value of the root is : %.1f", x);
}
 
int main()
{
    double x0 = 1.0 + 2.0; 
    newtonRaphson(x0);
    return 0;
}

