// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nVariance C++17 Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute variance
  double v = nola::stat::variance( n, x.data() );

  // Display result
  std::cout << "\nvariance = " << v << std::endl; // v = 0.1000
}