use std::f64;

const EPS:f64 = 0.0000001;

fn main() {
    let x_0 = 1.0*f64::consts::PI;
    //let h = 1e-7;
    let f = |x: f64| 1.1*x.powf(4.0) - 3.2*x.powf(3.0) + 5.3*x.powf(2.0) - 8.1*x + 3.3;
    let g = |x: f64| (-3.0*x).sin()*-2.1 + (x-1.0).exp()*0.4 + 0.9*x.powf(2.0) - 5.1;
    //let df = |x| (f(x+h)-f(x))/h;
    let result = newton(&g, x_0);
    println!("result : {}", result);
}

fn newton<T1>(f: T1, mut x: f64) -> f64
    where T1: Fn(f64) -> f64
{
    x -= f(x)/df(&f, x);
    let mut y = f(x);
    while y.abs() > EPS {
        x -= f(x)/df(&f, x);
        println!("{}", x);
        y = f(x);
    }
    x
}

fn df<T1>(f: T1, x: f64) -> f64 
    where T1: Fn(f64) -> f64
{
    let h = 1e-7;
   (f(x+h)-f(x))/h
}
