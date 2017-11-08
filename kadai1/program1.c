#include <stdio.h>
#include <math.h>
#include <my.h>

#define N 3

int main(){
	double e[N], fold[N];
	/* 配列・変数を宣言 */
	double f[N] = {0};
	double vecout[N] = {0};
	double out[N][N] = {0};
	double b1[N] = {1,4,8};
	double b2[N] = {6,2,5};
	double b3[N] = {9,7,3};
	double a[N][N] = {{1,6,9},{4,2,7},{8,5,3}};
	double unitMat[N][N] = {{1,0,0},{0,1,0},{0,0,1}};
	double zeroMat[N][N] = {{0,0,0},{0,0,0},{0,0,0}};
	double oneMat[N][N] = {{1,1,1},{1,1,1},{1,1,1}};


	//get_A(a);
	/* 演算実行・画面出力・ファイル出力など */	

	printf("関数のテストを実行します\n");
	printf("単位行列×ゼロ行列\n");
	mat_mlt(N, unitMat, zeroMat, out);
	printMlt(N, out);
	printf("\n");	
	printf("単位行列×全ての要素が1の行列\n");
	InitMat(N, out);
	mat_mlt(N, unitMat, oneMat, out);
	printMlt(N, out);
	printf("\n");

	//Ab1
	printf("Ab1\n");	
	mat_vec(N, a, b1, f);
	printVec(N, f);
	printf("\n");

	//Ab2
	printf("Ab2\n");
	InitVec(N, f);
	mat_vec(N, a, b2, f);
	printVec(N, f);
	printf("\n");

	//Ab3
	printf("Ab3\n");
	InitVec(N, f);
	mat_vec(N, a, b3, f);
	printVec(N, f);
	printf("\n");

	//A^2
	printf("A^2\n");
	InitMat(N, out);
	mat_mlt(N, a, a, out);
	printMlt(N, out);
	printf("\n");

	//A(Ab1)
	printf("A(Ab1)\n");
	InitVec(N, f);
	mat_vec(N, a, b1, f);
	InitVec(N, vecout);
	mat_vec(N, a, f, vecout);
	printVec(N, vecout);
	printf("\n");

	//AAb1
	printf("AAb1\n");
	InitMat(N, out);
	mat_mlt(N, a, a, out);
	InitVec(N, vecout);
	mat_vec(N, out, b1, vecout);
	printVec(N, vecout);	
	return 0;
}
