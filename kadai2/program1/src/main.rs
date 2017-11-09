
const N: usize = 3;

fn main() {
    let matrix_a: [[f64; N];N] = [[1., 0., 0.], [-3., 1., 0.], [2., -1., 1.]];
    let array_b: [f64; N] = [-5., 9., 4.];
    let mut array_y: [f64; N] = [0.; N];
    println!("Hello, world!");
    for i in 1..N {
        array_y[i] = forward_substitute(i, &matrix_a[i], &array_b[i], &array_y);
    } 
}

fn forward_substitute(i: usize, A: &[f64], b: &f64, y: &[f64]) -> f64{
    b - A.iter().fold(0, |acc &x| acc + x) 
}
