
const N: usize = 3;

fn main() {
    let matrix_a: [[f64; N]; N] = [[1., 0., 0.], [-3., 1., 0.], [2., -1., 1.]];
    let array_b: [f64; N] = [-5., 9., 4.];
    let mut array_y: [f64; N] = [0.; N];

    for i in 0..N {
        array_y[i] = forward_substitute(i, &matrix_a[i], &array_b[i], &array_y);
    }

    for y in &array_y {
        println!("{}", y);
    }
}

fn forward_substitute(row: usize, a: &[f64], b: &f64, y: &[f64]) -> f64 {
    //let iter: f64 = a.iter().zip(y.iter()).sum();
    let mut sum = 0.;
    if row == 0 {
        return *b;
    }

    for j in 0..row {
        sum += a[j] * y[j];
    }
    b - sum
}
