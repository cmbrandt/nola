// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<float, 8> a{ 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 }; 
  std::array<float, 8> b{ 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 }; 
  std::array<float, 8> c{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
  std::array<float, 8> d;

  nola::v512f av = nola::avx512_load( a.data() );
  nola::v512f bv = nola::avx512_load( b.data() );
  nola::v512f cv = nola::avx512_load( c.data() );

  nola::v512f dv = nola::avx512_fma(av, bv, cv);

  nola::avx512_store( d.data(), dv );

  std::cout << "v = " << dv[0] << " " << dv[1] << " "
                      << dv[2] << " " << dv[3] << " "
                      << dv[4] << " " << dv[5] << " "
                      << dv[6] << " " << dv[7] << std::endl;
}