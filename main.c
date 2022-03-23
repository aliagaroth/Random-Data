#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{ /*Program to generate random numbers [0.1]*/
    long long A = 16807;
    long long M = 2147483647;;
    long long q = 127773;
    long long r = 2836;

    long long seed=(unsigned)time( NULL );

    int i;

    int size = 10000;

    double k;

    double u[size];

    double low = 0 ;
    double high = 1;
    double y;
    y = high - low;

    long long h= seed/q;
    long long l = seed % q;
    long long t = A*l-r*h;

    if ( t>=0){
          seed=t;
    }  else{
      seed= t + M;
      }

    k=seed;

    u[0] = y*(k/(double)M) + low;

    printf("%f\n", u[0]);

    for(i=1; i<= size; i++){
        h= seed / q;
        l= seed % q;
        t = A*l - r*h;
        if (t >=0) {
            seed = t;
          } else {
              seed= t + M;
        }

        k=seed;
        u[i] = y*(k/(double)M) + low;
    }


    FILE * fpointer = fopen ("Random_numbers.txt", "w");

    for (i = 0; i<(size); i++){
             fprintf(fpointer, "%f\n", u[i]);
             printf("%f\n", u[i]);
         }
    fclose(fpointer);
    return 0;
}
