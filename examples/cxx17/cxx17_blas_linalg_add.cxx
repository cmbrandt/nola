// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/blas.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nLinear Algebra Addition C++17 Interface Example." << std::endl;

  // Two vectors of values
  std::vector<double> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<double> y{ 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5 };

  // Length of vectors
  std::int32_t n = x.size();

  // Scalar coefficient
  double alpha = 0.8;

  // Compute operation y := alpha*x + y
  nola::blas::linalg_add( n, alpha, x.data(), y.data() );

  // Display result
  nola::util::print_vector("y", n, y.data(), 2, 3);
  // y = [
  //  2.3 3.1 3.9 4.7 5.5 6.3 7.1 7.9
  // ]
}