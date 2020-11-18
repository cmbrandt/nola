// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nPrint Vector C++17 Interface Example." << std::endl;

  // Two sequences of values
  std::vector<double> x{ 3.22222, 1.44444, 2.66666, 0.88888, 2.11111 };

  // Length of vector
  std::int32_t n = x.size();

  // Display elements of one-dimensional container
  nola::util::print_vector( "\nvector 'x'" , n, x.data() );
  nola::util::print_vector( "\nvector 'x'" , n, x.data(), 4, 6);

  // Output:

  // vector 'x' = [
  //   3.22222  1.44444  2.66666  0.88888  2.11111
  // ]

  // vector 'x' = [
  //   3.222  1.444  2.667 0.8889  2.111
  // ]
}