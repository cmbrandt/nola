// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/blas.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nMatrix Vector Product C++17 Interface Example." << std::endl;

  // (Flattened) matrix of values
  std::vector<double> a{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };

  // Vectors of values
  std::vector<double> x{ 1.0, 2.0 };
  std::vector<double> y{ 1.0, 1.0, 1.0 };

  // Specify form of op(A)
  using nola::blas::no_transpose;

  // Dimensions of matrix A
  std::int32_t m = 3; // rows
  std::int32_t n = 2; // cols

  // Scalar coefficients
  double alpha = 0.5;
  double beta  = 0.25;

  // Compute operation y := alpha*op(A)*x + beta*y
  nola::blas::matrix_vector_product(no_transpose, m, n, alpha, a.data(),
                                    x.data(), beta, y.data() );

  // Display result
  nola::util::print_vector("\ny", y.size(), y.data(), 3, 4);

  // Vector Y = [
  //  4.75 6.25 7.75
  // ]
}

/*

g++-10 -Wall -Wpedantic -Wextra -std=c++17 -I \
~/projects/nola/include cxx17_blas_matrix_vector_product.cxx \
../../lib/libnola.a -lgfortran -o mat_vec_prod.exe

*/