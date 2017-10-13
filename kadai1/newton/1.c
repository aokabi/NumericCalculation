#include<stdio.h>
#include<math.h>

#define EPS 0.00001

void Newton(double, int);
double f(double, double);
double f_1(double, double);

void main(int argc, char *argv[]) {
  	
	if (argv[1] == 1) {//1
		double a[5] = {3.3, -8.1, 5.3, -3.2, 1.1};
	
	}
	else if (argv[1] == 2) {//2
		
	}

}

void Newton(double a[5], int x){
	next_x = x - (f(a, x) / f_1(a, x));

	if (fabs(next_x - x) < EPS) {
		return;
	}
	Newton(a[5], next_x);
}

double f(double a[5], double x) {
	double sum = 0;

	for (int i = 0; i < 5; ++i) {
		sum += a[i] * (x ^ i);
	}

	return sum;	
}

double f_1(double a[5], double x) {
	double sum = 0;

	for (int i = 1; i < 5; ++i) {
		sum += i * a[i] * (x ^ (i - 1));
	}

	return sum;
}
