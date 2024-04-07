#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//Précondition:un nombre d'étape n 
//PostCondition: renvoit une approximation de pi avec pi la méthode de Leibniz 
float Leibniz(int n) {
    float pi=0; 
    for (int i=0; i<n; i++) {
        if (i%1000 ==0) {
        }
        if (i%2==0) {
            pi += 1.0/(2.0*i+1.0);
        }
        else {
            pi -= 1.0/(2.0*i+1.0);
        }
    }
    return 4*pi;
}
/*Précondition:un nombre d'étape n 
PostCondition: renvoit une approximation de pi avec la méthode statistique.
*/
float PIstat(int n) {
    srand((unsigned int)time(NULL));
    float c_x =1;
    float c_y = 1;
    float number_of_point_in_circle;
    for(int i=0;i<n;i++) {
        float x = 2*(float)rand()/RAND_MAX;
        float y = 2*(float)rand()/RAND_MAX; // on choisit un point(x,y) aléatoire
        if (sqrt(pow((c_x-x),2)+pow((c_y-y),2)) <=1)  {/* teste si la distance entre le centre du cercle et le point et inférieur à 1 */
            number_of_point_in_circle++;
        }
    }
    return (4*number_of_point_in_circle/n);
    
}

int main(int argc, char** argv) {
    //printf("pi = %.10f\n",Leibniz(100000000));
    printf("%.16f\n",PIstat(1000000));
    return 0;
}