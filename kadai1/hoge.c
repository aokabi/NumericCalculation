#include <stdio.h>
#include <math.h>

#define N 3

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
			printf("%g ", mat[i][j]);
		}
		printf("\n");
	}
}

void printVec(double vec[N]) {
	for (int i = 0; i < N; ++i) {
		printf("%g\n", vec[i]);
	}
}

main(){
	double e[N], fold[N];
	/* 配列・変数を宣言 */
	double f[N] = {0};
	double vecout[N] = {0};
	double out[N][N] = {0};
	double b1[N] = {1,4,8};
	double b2[N] = {6,2,5};
	double b3[N] = {9,7,3};
	double a[N][N] = {{1,6,9},{4,2,7},{8,5,3}};


	//get_A(a);
	/* 演算実行・画面出力・ファイル出力など */

	

	mat_vec(a, b1, f);
	mat_vec(a, f, vecout);
	printVec(vecout);	
}
