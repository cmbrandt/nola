// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/blas.hxx>


int main()
{
  std::cout << "\nVector Euclidean Norm C++17 Interface Example." << std::endl;

  // Vector of values
  std::vector<double> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

  // Length of vector
  std::int32_t n = x.size();

  // Compute vector Euclidean norm
  double norm = nola::blas::vector_norm2( n, x.data() );

  // Display result
  std::cout << "\nnorm = " << norm << std::endl; // norm = 14.2829
}