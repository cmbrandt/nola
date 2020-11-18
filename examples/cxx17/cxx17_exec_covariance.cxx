// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/exec.hxx>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nExecution Policy Covariance C++17 Interface Example." << std::endl;

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

  // Compute covariance
  double r1 = nola::stat::covariance( n, x.data(), y.data() );

  // Compute covariance using execution policy overloads
  double r2 = nola::stat::covariance( seq,       n, x.data(), y.data() );
  double r3 = nola::stat::covariance( par,       n, x.data(), y.data() );
  double r4 = nola::stat::covariance( par_unseq, n, x.data(), y.data() );
  double r5 = nola::stat::covariance( unseq,     n, x.data(), y.data() );

  // Display result
  std::cout << "\ncovariance             = " << r1 // r1 = 0.1
            << "\ncovariance (seq)       = " << r2 // r2 = 0.1
            << "\ncovariance (par)       = " << r3 // r3 = 0.1
            << "\ncovariance (par_unseq) = " << r4 // r4 = 0.1
            << "\ncovariance (unseq)     = " << r5 // r5 = 0.1
            << std::endl;
}