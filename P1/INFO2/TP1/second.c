#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*date: 30/01
author: Lucas Serrano
pre: trois doubles a,b,c
post: retourne le discriminant
*/
double delta(double a,double b, double c) {
	return (b*b)-(4*a*c);
}
/*date: 30/01
author: Lucas Serrano
pre: 2 pointeurs solutions et trois doubles
*/
void solution(double* s1,double* s2,double a,double b,double d) {
	if (d <0) {
		printf("Aucune solution dans ℝ\n");
		exit(0);
	} else if (d ==0) {
		*s1=-b/(2*a);
		s2=s1;
	}else { // delta >0
		*s1=(-b+sqrt(d))/(2*a);
		*s2=(-b-sqrt(d))/(2*a);
	}
}

int main(){
	double a,b,c,d;
	double z_1=0.0;
	double z_2=0.0;
	double* s1;s1=&z_1;
	double* s2;s2=&z_2;
	printf("entrer trois réels a,b,c");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	printf("a=%lf,b=%lf,c=%lf\n",a,b,c);
	d=delta(a,b,c);
	printf("Δ=%lf\n",d);
	solution(s1,s2,a,b,d);
	printf("Les solutions sont \n x₁=%lf et x₂=%lf\n",*s1,*s2);
	return 0;
}
