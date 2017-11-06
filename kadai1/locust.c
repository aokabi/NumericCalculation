#include <stdio.h>
#include <math.h>
#include <my.h>

#define C 0.5
#define S 0.03 
#define TIME 60
#define N 7

void matrix(double[N][N]);
void InitVec(double[N]);
void cp(double[N], double[N]);

void main(int argc, char *argv[]) {
	double a[N][N] = {0};
	double b[N] = {1,0,0,0,0,0,0};
	double out[N] = {0};
	double temp[N] = {0};

	matrix(a);

		printf("0,");
		for (int h = 0; h < N; ++h) {
			printf("%g", b[h]);
			if (h != N-1) printf(",");
		}
		printf("\n");
		mat_vec(N, a, b, out);
		for (int i = 0; i < TIME; ++i) {
			cp(out, temp);
			InitVec(out);
			mat_vec(N, a, temp, out);
			printf("%d,", i+1);
			for (int j = 0; j < N; ++j) {
				printf("%g", out[j]);
				if (j != N-1) printf(",");
			}
			printf("\n");
		}
}

void matrix(double out[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if ((j == 0 && i == 0) || (j == 6 && i == 6)) {
				out[i][j] += (1-S)*(1-C);
			}
			if (i == j) {
				out[i][j] += S;
			}
			else if (j == i+1) {
				out[i][j] += (1-S)*(1-C);
			}
			else if (i == j+1) {
				out[i][j] += (1-S)*C;
			}
		}
	}
}

void InitVec(double out[N]) {
	for (int i = 0; i < N; ++i) {
		out[i] = 0;
	}
}

void cp(double in[N], double out[N]) {
	for (int i = 0; i < N; ++i) {
		out[i] = in[i];
	}
}

