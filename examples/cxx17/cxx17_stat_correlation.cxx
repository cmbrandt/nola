// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/exec.hxx>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nCorrelation C++17 Interface Example." << std::endl;

  // Execution policies
  using nola::exec::seq;
  using nola::exec::par;
  using nola::exec::par_unseq;
  using nola::exec::unseq;

  // Two sequences of values
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute correlation
  double c1 = nola::stat::correlation( n, x.data(), y.data() );

  // Compute correlation using execution policy overload
  double c2 = nola::stat::correlation( seq,       n, x.data(), y.data() );
  double c3 = nola::stat::correlation( par,       n, x.data(), y.data() );
  double c4 = nola::stat::correlation( par_unseq, n, x.data(), y.data() );
  double c5 = nola::stat::correlation( unseq,     n, x.data(), y.data() );

  // Display result
  std::cout << "\ncorrelation             = " << c1 // c1 = -0.9000
            << "\ncorrelation (seq)       = " << c2 // c2 = -0.9000
            << "\ncorrelation (par)       = " << c3 // c3 = -0.9000
            << "\ncorrelation (par_unseq) = " << c4 // c4 = -0.9000
            << "\ncorrelation (unseq)     = " << c5 // c5 = -0.9000
            << std::endl;
}