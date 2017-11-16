package numeric

func ProgressAssignment(A [][]float64, b []float64, y []float64) {
	for i := 0; i < len(y); i++ {
		y[i] = b[i] - Sum(Zip(A[i], y))
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
