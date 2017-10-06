#include <stdio.h>
#include <math.h>
#include <my.h>

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
