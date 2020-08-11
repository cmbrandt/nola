// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdlib>
#include <iostream>
#include <vector>
#include <nola/nola.hxx>


int main()
{
  std::cout << "\nVariance Nola Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Compute variance
  double v = nola::variance( x.data(), x.size() );

  // Display result
  std::cout << "\nvariance = " << v << std::endl; // v = 0.1000
}