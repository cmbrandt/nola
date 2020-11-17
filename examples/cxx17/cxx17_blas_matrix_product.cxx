// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/blas.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nMatrix Product C++17 Interface Example." << std::endl;

  // (Flattened) matrices of values
  std::vector<double>
    a{ 1.0, 3.0, 5.0, 7.0, 2.0, 4.0, 6.0, 8.0 };
  std::vector<double>
    b{ 1.5, 4.5, 2.5, 5.5, 3.5, 6.5 };
  std::vector<double>
    c{ 1.0, 4.0, 7.0, 10.0, 2.0, 5.0, 8.0, 11.0, 3.0, 6.0, 9.0, 12.0 };

  // Specify form of op(A) and op(B)
  using nola::blas::no_transpose;

  // Dimensions of matrices
  std::int32_t m = 4; // rows in input matrix A, rows in solution matrix C
  std::int32_t n = 3; // cols in input matrix B, cols in solution matrix C
  std::int32_t k = 2; // cols in input matrix A, rows in input matrix B

  // Scalar coefficients
  double alpha = 0.25;
  double beta  = 0.75;

  // Compute operation C := alpha*op(A)*op(B) + beta*C
  nola::blas::matrix_product( no_transpose, no_transpose, m, n, k, alpha,
                              a.data(), b.data(), beta, c.data() );

  nola::util::print_matrix("\nC", m, n, c.data(), 5, 6);

  // C = [
  //   3.375  4.875  6.375
  //   8.625 11.125 13.625
  //  13.875 17.375 20.875
  //  19.125 23.625 28.125
  // ]
}