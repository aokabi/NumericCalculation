#include <stdio.h>
#include <math.h>

void mat_vec(int size, double (*in1)[size], double *in2, double *out) {
	/* 行列ベクトル積を実行 */
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j) {
			out[i] += in1[i][j] * in2[j];
		}
	}
}
void mat_mlt(int size, double (*in1)[size], double (*in2)[size], double (*out)[size]) {
	/* 行列行列積を実行 */
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			for (int h = 0; h < size; ++h) {
				out[i][j] += in1[i][h] * in2[h][j];
			}
		}
	}
}
void get_A(int size, double (*mat)[size]){
	/* 行列 A の全要素の値を定める */

}

void printMlt(int size, double (*mat)[size]) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j ) {
			printf("%5g ", mat[i][j]);
		}
		printf("\n");
	}
}

void printVec(int size, double *vec) {
	for (int i = 0; i < size; ++i) {
		printf("%g\n", vec[i]);
	}
}

