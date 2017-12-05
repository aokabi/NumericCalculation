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
	result := Make(len(left))
	for i := 0; i < len(left); i++ {
		for j := 0; j < len(right); j++ {
			for h := 0; h < len(left); h++ {
				result[i][j] += left[i][h] * right[h][j]
			}
		}
	}
	return result
}

func Make(size int) [][]float64 {
	result := make([][]float64, 0)
	for i := 0; i < size; i++ {
		result = append(result, make([]float64, size))
	}
	return result
}

func LUDecomposition(A [][]float64) ([][]float64, [][]float64){
	elu := Make(len(A))
	u := Make(len(A))

	for h := 0; h < len(A); h++ {
			elu[h][h] = 1.0
	}

	for j, a := range A[0] {
		u[0][j] = a 
	}

	for i := 1; i < len(A); i++ {
		elu[i][0] = A[i][0]/u[0][0]
	}

	for i := 1; i < len(A); i++ {
		for j := i; j < len(A); j++ {
			u[i][j] = A[i][j] - sum(i, j, elu, u)
		}
		for k := i+1; k < len(A); k++ {
			elu[k][i] = (1/u[i][i])*(A[k][i] - sum(k, i, elu, u))
		}
	}

	return elu, u
}

func sum(i, j int, elu, u [][]float64) float64{
	result := 0.0;
	for k := 0; k <= j-1; k++ {
		result += elu[i][k]*u[k][j]
	} 
	return result
}
