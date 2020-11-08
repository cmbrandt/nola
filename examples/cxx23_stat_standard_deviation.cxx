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
  std::cout << "\nStandard Deviation C++23 Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Define mdspan object
  auto a = stdex::mdspan<double, 5>{ x.data() };

  // Compute standard deviation
  double s = nola::stat::standard_deviation(a);

  // Display result
  std::cout << "\nstandard deviation = " << s << std::endl; // s = 0.3162
}