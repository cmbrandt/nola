// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdlib>
#include <iostream>
#include <vector>
#include <nola/stat.hxx>


int main()
{
  std::cout << "\nArithmetic Mean C++17 Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Compute arithmetic mean
  double m = nola::arithmetic_mean( x.data(), x.size() );

  // Display result
  std::cout << "\narithmetic mean = " << m << std::endl; // m = 0.6000
}