#include"newton.h"
#include<stdio.h>
#include<math.h>

void Newton(double (*func)(double), double x){

	x -= (func(x) / deriv(func, x));
	printf("%g\n", x);
	getchar();

	double y = func(x);
	if (fabs(y) < EPS) {
		return;
	}

	Newton(func, x);
}
double f(double x){
	return  1.1*pow(x, 4) - 3.2*pow(x, 3) + 5.3*pow(x, 2) - 8.1*x + 3.3;
}
double g(double x){
	return -2.1*sin(-3*x) + 0.4*exp(x-1) + 0.9*pow(x, 2) - 5.1;
}
double deriv(double (*func)(double), double x){
	double h = 1e-7;
	return (func(x+h)-func(x))/h;
}

