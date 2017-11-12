pub fn forward_substitute(row: usize, a: &[f64], b: &f64, y: &[f64]) -> f64 {
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

pub fn make_matrix_h(slice: &mut [&mut [f64]]) {
  for i in 0..slice.len() {
    for j in 0..slice.len() {
      slice[i][j] = (0.2 as f64).powf(((i as f64) - (j as f64)).abs());
    }
  }
}
