// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/exec.hxx>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nVariance C++17 Interface Example." << std::endl;

  // Execution policies
  using nola::exec::seq;
  using nola::exec::par;
  using nola::exec::par_unseq;
  using nola::exec::unseq;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute variance
  double v1 = nola::stat::variance( n, x.data() );

  // Compute variance using execution policy overload
  double v2 = nola::stat::variance( seq,       n, x.data() );
  double v3 = nola::stat::variance( par,       n, x.data() );
  double v4 = nola::stat::variance( par_unseq, n, x.data() );
  double v5 = nola::stat::variance( unseq,     n, x.data() );

  // Display result
  std::cout << "\nvariance             = " << v1 // v1 = 0.1000
            << "\nvariance (seq)       = " << v2 // v2 = 0.1000
            << "\nvariance (par)       = " << v3 // v3 = 0.1000
            << "\nvariance (par_unseq) = " << v4 // v4 = 0.1000
            << "\nvariance (unseq)     = " << v5 // v5 = 0.1000
            << std::endl;
}