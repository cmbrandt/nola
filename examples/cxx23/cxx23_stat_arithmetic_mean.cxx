// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <experimental/mdspan>
#include <nola/cxx23/stat.hxx>


namespace stdex = std::experimental;

int main()
{
  std::cout << "\nArithmetic Mean C++23 Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Define mdspan object
  auto a = stdex::mdspan<double, 5>{ x.data() };

  // Compute arithmetic mean
  double m = nola::stat::arithmetic_mean(a);

  // Display result
  std::cout << "\narithmetic mean = " << m << std::endl; // m = 0.6000
}