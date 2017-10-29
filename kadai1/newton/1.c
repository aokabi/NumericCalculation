#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.00001

void Newton(double[], double);
void Newton2(double[], double);
double f(double[], double);
double f_1(double[], double);
double g(double[], double);
double g_1(double[], double);


int main(int argc, char *argv[]) {

	if (atoi(argv[1]) == 1) {//1

		double array[5] = {3.3, -8.1, 5.3, -3.2, 1.1};
		Newton(array, atof(argv[2]));	
	}
	else if (atoi(argv[1]) == 2) {//2

    //double array[4] = {-5.1, 0.9, 0.4, -2.1};
		//Newton2(array, atof(argv[2]));
	}
	return 0;
}

void Newton(double in[5], double x){
	double next_x = x - (f(in, x) / f_1(in, x));

	printf("%g\n", x);
	getchar();
	if (fabs(next_x - x) < EPS) {
		return;
	}
	Newton(in, next_x);
}

void Newton2(double in[4], double x) {
	double next_x = x - (g(in, x) / g_1(in, x));

	printf("%g\n", x);
	getchar();
	if (fabs(next_x - x) < EPS) {
		return;
	}
	Newton2(in, next_x);

}

double f(double a[5], double x) {
	double sum = 0;

	for (int i = 0; i < 5; ++i) {
		sum += a[i] * pow(x, i);
	}

	return sum;	
}

double f_1(double a[5], double x) {
	double sum = 0;

	for (int i = 1; i < 5; ++i) {
		sum += i * a[i] * pow(x, (i - 1));
	}

	return sum;
}

double g(double a[4], double x) {
	double sum = 0;
	double b[4] = {sin(-3*x), exp(x-1), pow(x, 2), 1};

	for (int i = 0; i < 4; ++i) {
		sum += a[i] * b[i];
	}

	return sum;
}

double g_1(double a[4], double x) {
	double sum = 0;
	double b[4 - 1] = {-3*cos(-3*x), exp(x-1), 2*x};

	for (int i = 0; i < 3; ++i) {
		sum += a[i] * b[i];
	}

	return sum;
}
