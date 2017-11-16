package main

import (
	"fmt"
	nu "numeric"
)

func main() {
	A := [][]float64{{2, 1, 3}, {0, -2, 3}, {0, 0, -2}}
	c := []float64{-5, -6, 8}
	var x = make([]float64, 3)
	nu.ReverseAssignment(A, c, x)
	fmt.Println(x[:])
}
