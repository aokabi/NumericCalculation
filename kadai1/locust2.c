#include <stdio.h>
#include <math.h>
#include <my.h>

#define S 0.1 
#define TIME 60
#define N 7

void matrix(double[N][N], double);

void main() {
	double b[N] = {1,0,0,0,0,0,0};
	double out[N] = {0};
	double temp[N] = {0};
	double c = 0.4;

	for (int j = 0; j < 3; ++j) {
		double a[N][N] = {0};
		InitVec(N, out);
		matrix(a, c);
		mat_vec(N, a, b, out);
		//printf("c=%g\n", c);
		for (int i = 0; i < TIME; ++i) {
			cp(N, out, temp);
			InitVec(N, out);
			mat_vec(N, a, temp, out);
		}
		for (int h = 0; h < N; ++h) {
			printf("%d,%g\n", h, out[h]);
		}
		printf("\n");
		c += 0.1;
	}

}

void matrix(double out[N][N], double c) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if ((j == 0 && i == 0) || (j == 6 && i == 6)) {
				out[i][j] += (1-S)*(1-c);
			}
			if (i == j) {
				out[i][j] += S;
			}
			else if (j == i+1) {
				out[i][j] += (1-S)*(1-c);
			}
			else if (i == j+1) {
				out[i][j] += (1-S)*c;
			}
		}
	}
}

