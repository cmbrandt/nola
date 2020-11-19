// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nPrint Matrix C++17 Interface Example." << std::endl;

  // Two sequences of values
  std::vector<double> A{ 3.22222, 1.44444, 2.66666,
                         0.88888, 2.11111, 7.99999 };

  // Dimensions of matrix
  std::int32_t rows = 3;
  std::int32_t cols = 2;

  // Display elements of two-dimensional container
  nola::util::print_matrix( "\nmatrix 'A'" , rows, cols, A.data() );
  nola::util::print_matrix( "\nmatrix 'A'" , rows, cols, A.data(), 4, 6);

  // Output:

  // matrix 'A' = [
  //   3.22222  0.88888
  //   1.44444  2.11111
  //   2.66666  7.99999
  // ]

  // matrix 'A' = [
  //  3.222 0.8889
  //  1.444  2.111
  //  2.667      8
  // ]
}