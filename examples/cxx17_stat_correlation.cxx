// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdlib>
#include <iostream>
#include <vector>
#include <nola/stat.hxx>


int main()
{
  std::cout << "\nCorrelation Nola Interface Example." << std::endl;

  // Two sequences of values
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  // Length of sequences
  std::size_t n = x.size();

  // Compute correlation
  double c = nola::correlation( x.data(), y.data(), x.size() );

  // Display result
  std::cout << "\ncorrelation = " << c << std::endl; // c = -0.9000
}