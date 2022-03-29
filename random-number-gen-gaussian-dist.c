#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
    long long A = 16807;
    long long M = 2147483647;;
    long long q = 127773;
    long long r = 2836;

    long long seed_1 = 87641351;
    long long seed_2 = 23116515;

    int size = 10000;

    int i;
    double k_1;
    double k_2;

    double u_1 [size];
    double u_2 [size];

    long long h_1 = seed_1/q ;
    long long l_1 = seed_1% q;
    long long t_1 = A*l_1 - r*h_1;

    if (t_1 >=0) {
        seed_1 = t_1;

    } else {
        seed_1 = t_1 + M;
        }

    k_1 = seed_1 ;

    u_1[0] = k_1/(double)M;

    for (i=1; i<=size ; i++){
         h_1 = seed_1/q;
         l_1 = seed_1 % q;
         t_1 = A*l_1 - r*h_1;

    if ( t_1 >= 0){
        seed_1 = t_1 ;
        } else {
           seed_1 = t_1 + M;
    }

    k_1 = seed_1;
    u_1 [i] = k_1/(double)M;

 }

    long long h_2 = seed_2/q ;
    long long l_2 = seed_2% q;
    long long t_2 = A*l_2 - r*h_2;

    if ( t_2 >= 0){
        seed_2 = t_2 ;
    } else {
           seed_2 = t_2 + M;
           }

     k_2 = seed_2;

     u_2 [0] = k_2/(double)M;

     for (i=1; i <=size; i++){
          h_2 = seed_2/q;
          l_2 = seed_2 % q;
          t_2 = A*l_2 - r*h_2;
          if ( t_2 >= 0){
              seed_2 = t_2;
              } else {
                  seed_2 = t_2 + M;
     }

     k_2 = seed_2;
     u_2[i] = k_2 /(double)M;

    }


  double z_1[size];
  double z_2[size];

  for (i=0; i<size; i++){
           z_1[i] = sqrt(-2*log(u_1[i]))*cos(2*M_PI*u_2[i]);
           z_2[i] = sqrt(-2*log(u_1[i]))*cos(2*M_PI*u_2[i]);
  }

  FILE *fpointer_1 = fopen("Gaussian_Random_numbers_z1.txt", "w");
  for (i = 0; i<(size); i++ ){
           fprintf(fpointer_1, "%f\ln", z_1[i]);
        }
  fclose(fpointer_1);

  FILE*fpointer_2 = fopen ("Gaussian_Random_numbers_z2.txt", "w");
  for (i=0; i<(size); i++){
          fprintf(fpointer_2, "%f\n", z_2[i]);
     }
  fclose(fpointer_2);

  return 0;
}
