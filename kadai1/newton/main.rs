use std::f64;

const EPS:f64 = 0.0000001;

fn main() {
    let x_0 = 5.0;
    let h = 1e-7;
    let f  = |x: f64| 1.1*x.powf(4.0) - 3.2*x.powf(3.0) + 5.3*x.powf(2.0) - 8.1*x + 3.3;
    let df = |x| (f(x+h)-f(x))/h;
    let result = newton(&f, &df, x_0);
    println!("result : {}", result);
}

fn newton<T1, T2>(f: T1, df: T2, mut x: f64) -> f64
    where T1: Fn(f64) -> f64,
          T2: Fn(f64) -> f64
{
    x -= f(x)/df(x);
    let mut y = f(x);
    while y.abs() > EPS {
        x -= f(x)/df(x);
        println!("{}", x);
        y = f(x);
    }
    x
}
