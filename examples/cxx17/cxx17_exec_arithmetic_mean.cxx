// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/exec.hxx>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nArithmetic Mean C++17 Interface Example." << std::endl;

  // Execution policies
  using nola::exec::seq;
  using nola::exec::par;
  using nola::exec::par_unseq;
  using nola::exec::unseq;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute arithmetic mean
  double m1 = nola::stat::arithmetic_mean( n, x.data() );

  // Compute arithmetic mean using execution policy overload
  double m2 = nola::stat::arithmetic_mean( seq,       n, x.data() );
  double m3 = nola::stat::arithmetic_mean( par,       n, x.data() );
  double m4 = nola::stat::arithmetic_mean( par_unseq, n, x.data() );
  double m5 = nola::stat::arithmetic_mean( unseq,     n, x.data() );

  // Display result
  std::cout << "\narithmetic mean             = " << m1 // m1 = 0.6000
            << "\narithmetic mean (seq)       = " << m2 // m2 = 0.6000
            << "\narithmetic mean (par)       = " << m3 // m3 = 0.6000
            << "\narithmetic mean (par_unseq) = " << m4 // m4 = 0.6000
            << "\narithmetic mean (unseq)     = " << m5 // m5 = 0.6000
            << std::endl;
}