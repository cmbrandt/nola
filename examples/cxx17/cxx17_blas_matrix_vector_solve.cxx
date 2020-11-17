// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/blas.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nMatrix Vector Solve C++17 Interface Example." << std::endl;

  // (Flattened) matrix of values
  std::vector<double> a{ 2.0, 0.0, 0.0, 6.0, 1.0, 0.0, -8.0, 5.0, 3.0 };

  // Vector of values
  std::vector<double> x{ 2.0, 0.5, 0.2 };

  // Specify form of operations
  using nola::blas::upper_triangle;
  using nola::blas::no_transpose;
  using nola::blas::explicit_diagonal;

  // Order of matrix, length of vector
  std::int32_t n = 3;

  // Compute operation x := op(A)*x
  nola::blas::matrix_vector_solve( upper_triangle, no_transpose,
                                   explicit_diagonal, n, a.data(), x.data() );

  // Display result
  nola::util::print_vector("\nx", x.size(), x.data(), 4, 5);

  // x = [
  //  0.7667 0.1667 0.06667
  // ]
}