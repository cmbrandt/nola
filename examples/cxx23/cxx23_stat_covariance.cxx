// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx23/stat.hxx>


namespace stdex = std::experimental;

int main()
{
  std::cout << "\nCovariance C++23 Interface Example." << std::endl;

  // Two sequences of values
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  // Define mdspan objects
  auto a = stdex::mdspan<double, 5>{ x.data() };
  auto b = stdex::mdspan<double, 5>{ y.data() };

  // Compute covariance
  double r = nola::stat::covariance(a, b);

  // Display result
  std::cout << "\ncovariance = " << r << std::endl; // r = -0.2700
}