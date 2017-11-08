#include <stdio.h>
#include <math.h>

void mat_vec(int size, double (*in1)[size], double *in2, double *out) {
	/* 行列ベクトル積を実行 */
	InitVec(size, out);
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j) {
			out[i] += in1[i][j] * in2[j];
		}
	}
}
void mat_mlt(int size, double (*in1)[size], double (*in2)[size], double (*out)[size]) {
	/* 行列行列積を実行 */
	InitMat(size, out);
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

void cp(int size, double *in, double *out) {
	for (int i = 0; i < size; ++i) {
		out[i] = in[i];
	}
}

void InitVec(int size, double *out) {
	for (int i = 0; i < size; ++i) {
		out[i] = 0;
	}
}

void InitMat(int size, double (*out)[size]){
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			out[i][j] = 0;
		}
	}
}

void matrix(int size, double (*out)[size], double s, double c) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if ((j == 0 && i == 0) || (j == size-1 && i == size-1)) {
				out[i][j] += (1-s)*(1-c);
			}
			if (i == j) {
				out[i][j] += s;
			}
			else if (j == i+1) {
				out[i][j] += (1-s)*(1-c);
			}
			else if (i == j+1) {
				out[i][j] += (1-s)*c;
			}
		}
	}
}

