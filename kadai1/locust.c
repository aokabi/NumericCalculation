#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <my.h>

#define C 0.5 
#define TIME 60
#define N 7

void matrix(double[N][N], double);

void main(int argc, char *argv[]) {
	double a[N][N] = {0};
	double b[N] = {1,0,0,0,0,0,0};
	double out[N] = {0};
	double temp[N] = {0};
	double s = atof(argv[1]);

	matrix(a, s);

		printf("0,");
		for (int h = 0; h < N; ++h) {
			printf("%g", b[h]);
			if (h != N-1) printf(",");
		}
		printf("\n");
		mat_vec(N, a, b, out);
		for (int i = 0; i < TIME; ++i) {
			cp(N, out, temp);
			InitVec(N, out);
			mat_vec(N, a, temp, out);
			printf("%d,", i+1);
			for (int j = 0; j < N; ++j) {
				printf("%g", out[j]);
				if (j != N-1) printf(",");
			}
			printf("\n");
		}
}

void matrix(double out[N][N], double s) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if ((j == 0 && i == 0) || (j == 6 && i == 6)) {
				out[i][j] += (1-s)*(1-C);
			}
			if (i == j) {
				out[i][j] += s;
			}
			else if (j == i+1) {
				out[i][j] += (1-s)*(1-C);
			}
			else if (i == j+1) {
				out[i][j] += (1-s)*C;
			}
		}
	}
}
