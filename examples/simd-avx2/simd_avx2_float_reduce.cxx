// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Reduce Example." << std::endl;

  // Vector of values
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };

  // Initialize SIMD object using input data
  auto av = nola::simd::avx2_load( a.data() );

  // Compute SIMD reduction
  float r = nola::avx2_reduce(av);

  // Display result
  std::cout << "r = " << r << std::endl;
}