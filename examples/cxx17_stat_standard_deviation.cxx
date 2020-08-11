// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdlib>
#include <iostream>
#include <vector>
#include <nola/stat.hxx>


int main()
{
  std::cout << "\nStandard Deviation Nola Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::size_t n = x.size();

  // Compute standard deviation
  double s = nola::standard_deviation( x.data(), x.size() );

  // Display result
  std::cout << "\nstandard deviation = " << s << std::endl; // s = 0.3162
}