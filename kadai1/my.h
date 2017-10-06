#include <stdio.h>
#include <math.h>
#include <para.h>

void mat_vec( double in1[N][N], double in2[N], double out [N] ) {
	/* 行列ベクトル積を実行 */
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) {
			out[i] += in1[i][j] * in2[j];
		}
	}
}
void mat_mlt( double in1[N][N], double in2[N][N], double out[N][N] ) {
	/* 行列行列積を実行 */
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			for (int h = 0; h < N; ++h) {
				out[i][j] += in1[i][h] * in2[h][j];
			}
		}
	}
}
void get_A( double mat[N][N] ){
	/* 行列 A の全要素の値を定める */

}

void printMlt(double mat[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j ) {
			printf("%5g ", mat[i][j]);
		}
		printf("\n");
	}
}

void printVec(double vec[N]) {
	for (int i = 0; i < N; ++i) {
		printf("%g\n", vec[i]);
	}
}

