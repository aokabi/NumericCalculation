#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <my.h>
 
#define TIME 60
#define N 7



void main(int argc, char *argv[]) {
	double a[N][N] = {0};
	double b[N] = {1,0,0,0,0,0,0};
	double out[N] = {0};
	double temp[N] = {0};
	double s = atof(argv[1]);
	double c = 0.5;

	matrix(N, a, s, c);

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


