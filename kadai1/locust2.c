#include <stdio.h>
#include <math.h>
#include <my.h>

#define TIME 60
#define N 7

void main() {
	double b[N] = {1,0,0,0,0,0,0};
	double out[N] = {0};
	double temp[N] = {0};
	double c = 0.4;
	double s = 0.1;

	for (int j = 0; j < 3; ++j) {
		double a[N][N] = {0};
		InitVec(N, out);
		matrix(N, a, s, c);
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


