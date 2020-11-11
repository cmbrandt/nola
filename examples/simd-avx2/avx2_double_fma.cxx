// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<double, 4> a{ 5.0, 5.0, 5.0, 5.0 }; 
  std::array<double, 4> b{ 2.0, 2.0, 2.0, 2.0 }; 
  std::array<double, 4> c{ 1.0, 1.0, 1.0, 1.0 };
  std::array<double, 4> d;

  nola::v256d av = nola::avx2_load( a.data() );
  nola::v256d bv = nola::avx2_load( b.data() );
  nola::v256d cv = nola::avx2_load( c.data() );

  nola::v256d dv = nola::avx2_fma(av, bv, cv);

  nola::avx2_store( d.data(), dv );

  std::cout << "v = " << dv[0] << " " << dv[1] << " "
                      << dv[2] << " " << dv[3] << std::endl;
}