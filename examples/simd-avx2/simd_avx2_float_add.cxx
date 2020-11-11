// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  // 
  constexpr std::int32_t w = nola::simd::avx2_width<float>();

  // 
  std::array<float, w> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::array<float, w> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 

  //
  std::vector<float> c(w);

  //
  nola::simd::v256f av = nola::simd::avx2_load( a.data() );
  nola::simd::v256f bv = nola::simd::avx2_load( b.data() );

  //
  nola::simd::v256f cv = nola::simd::avx2_add(av, bv);

  //
  nola::simd::avx2_store( c.data(), cv );

  // Display result
  nola::util::print_vector("c", c.size(), c.data(), 2, 3);
}
