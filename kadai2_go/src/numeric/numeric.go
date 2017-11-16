package numeric

func ProgressAssignment(A [][]float64, b []float64, y []float64) {
	for i := 0; i < len(y); i++ {
		y[i] = b[i] - Sum(Zip(A[i], y))
	}
}

func ReverseAssignment(A [][]float64, c []float64, x []float64) {
	for i := len(x) - 1; i >= 0; i-- {
		x[i] = (1 / A[i][i]) * (c[i] - Sum(Zip(A[i], x)))
	}
}

func Zip(a, b []float64) []float64 {
	result := make([]float64, len(a))
	for i := 0; i < len(a); i++ {
		result[i] = a[i] * b[i]
	}
	return result
}

func Sum(ary []float64) float64 {
	r := 0.
	for _, value := range ary {
		r += value
	}
	return r
}

func Multiply(left, right [][]float64) [][]float64 {
	var result [][]float64
	for i := 0; i < len(left); i++ {
		for j := 0; j < len(right); j++ {
			for h := 0; h < len(left); h++ {
				result[i][j] += left[i][h] * right[h][j]
			}
		}
	}
	return result
}
