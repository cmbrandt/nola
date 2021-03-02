// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nMaximum Absolute Difference C++17 Interface Example." << std::endl;

  // Two sequences of values
  std::vector<double> x{ 3.2, 1.4, 2.6,  0.8, 2.0  };
  std::vector<double> y{ 3.2, 1.4, 2.59, 0.8, 2.03 };

  // Length of sequences
  std::int32_t n = x.size();

  // Compute maximum difference
  double d = nola::util::max_abs_difference( n, x.data(), y.data() );

  // Display result
  std::cout << "\nmaximum absolute difference = " << d << std::endl; // c = 0.03
}