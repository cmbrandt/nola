// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/cxx17/simd.hxx>


int main()
{
  std::array<double, 4> a{ 5.0, 5.0, 5.0, 5.0 }; 
  std::array<double, 4> b{ 2.0, 2.0, 2.0, 2.0 }; 
  std::array<double, 4> c{ 1.0, 1.0, 1.0, 1.0 };
  std::array<double, 4> d;

  nola::v512d av = nola::avx512_load( a.data() );
  nola::v512d bv = nola::avx512_load( b.data() );
  nola::v512d cv = nola::avx512_load( c.data() );

  nola::v512d dv = nola::avx512_fma(av, bv, cv);

  nola::avx512_store( d.data(), dv );

  std::cout << "v = " << dv[0] << " " << dv[1] << " "
                      << dv[2] << " " << dv[3] << std::endl;
}