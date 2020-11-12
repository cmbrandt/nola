// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

//#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  // Input vectors
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 

  // Declare solution vector
  std::vector<float> c(8);

  // Load input data into registers
  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  // Sum SIMD vectors
  auto cv = nola::simd::avx2_add(av, bv);

  // Store SIMD register to memory
  nola::simd::avx2_store( c.data(), cv );

  // Display result
  nola::util::print_vector("c", c.size(), c.data(), 2, 3);
}
