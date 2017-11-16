package main

import (
	"fmt"
	nu "numeric"
)

func main() {
	A := [][]float64{{1, 0, 0}, {-3, 1, 0}, {2, -1, 1}}
	b := []float64{-5, 9, 4}
	y := make([]float64, 3)
	nu.ProgressAssignment(A, b, y)
	fmt.Println(y[:])
}
