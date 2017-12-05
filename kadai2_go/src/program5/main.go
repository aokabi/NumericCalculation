package main

import (
	"fmt"
	nu "numeric"
)

func main() {
	left := [][]float64{{1, 0, 0}, {-3, 1, 0}, {2, -1, 1}}
	right := [][]float64{{2, 1, 3}, {0, -2, 3}, {0, 0, -2}}
	A := nu.Multiply(left, right)
	fmt.Println("A =", A)
	b := []float64{-5, 9, 4}
	y := make([]float64, 3)
	x := make([]float64, 3)
	//前進代入して後進代入する
	L, U := nu.LUDecomposition(A)
	nu.ProgressAssignment(L, b, y)	
	nu.ReverseAssignment(U, y, x)
	fmt.Println(x)
}