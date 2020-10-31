// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nCovariance C++17 Interface Example." << std::endl;

  // Two sequences of values
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  // Length of sequences
  std::int32_t n = x.size();

  // Compute covariance
  double r = nola::stat::covariance( n, x.data(), y.data() );

  // Display result
  std::cout << "\ncovariance = " << r << std::endl; // r = -0.2700
}