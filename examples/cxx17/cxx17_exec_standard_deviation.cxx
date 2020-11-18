// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/cxx17/exec.hxx>
#include <nola/cxx17/stat.hxx>


int main()
{
  std::cout << "\nStandard Deviation C++17 Interface Example." << std::endl;

  // Execution policies
  using nola::exec::seq;
  using nola::exec::par;
  using nola::exec::par_unseq;
  using nola::exec::unseq;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute standard deviation
  double s1 = nola::stat::standard_deviation( n, x.data() );

  // Compute standard deviation using execution policy overload
  double s2 = nola::stat::standard_deviation( seq,       n, x.data() );
  double s3 = nola::stat::standard_deviation( par,       n, x.data() );
  double s4 = nola::stat::standard_deviation( par_unseq, n, x.data() );
  double s5 = nola::stat::standard_deviation( unseq,     n, x.data() );

  // Display result
  std::cout << "\nstandard deviation             = " << s1 // s1 = 0.3162
            << "\nstandard deviation (seq)       = " << s2 // s2 = 0.3162
            << "\nstandard deviation (par)       = " << s3 // s3 = 0.3162
            << "\nstandard deviation (par_unseq) = " << s4 // s4 = 0.3162
            << "\nstandard deviation (unseq)     = " << s5 // s5 = 0.3162
            << std::endl;
}