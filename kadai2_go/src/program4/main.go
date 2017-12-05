package main

import (
	"fmt"
	nu "numeric"
)

func main(){
	left := [][]float64{{1, 0, 0}, {-3, 1, 0}, {2, -1, 1}}
	right := [][]float64{{2, 1, 3}, {0, -2, 3}, {0, 0, -2}}
	A := nu.Multiply(left, right)
	fmt.Println("A =", A)
	res1, res2 := LUDecomposition(A)
	fmt.Println("L =", res1)
	fmt.Println("U =", res2)
}