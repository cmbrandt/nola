// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Fused Multiply-Add Example." << std::endl;

  // Two vectors of values
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 };
  std::vector<float> c{ 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 };

  // Container to store solution
  std::vector<float> d(8);

  // Initialize SIMD objects using input data
  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );
  auto cv = nola::simd::avx2_load( c.data() );

  // Compute SIMD operation d = (a*b) + c
  auto dv = nola::simd::avx2_fma(av, bv, cv);

  // Store SIMD register to memory
  nola::simd::avx2_store( d.data(), dv );

  // Display result
  nola::util::print_vector("\nd", d.size(), d.data(), 3, 4);
}