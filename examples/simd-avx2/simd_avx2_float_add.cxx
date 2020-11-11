// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<float, 8> a{ 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 }; 
  std::array<float, 8> b{ 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 }; 
  std::array<float, 8> c;

  nola::v256f av = nola::avx2_load( a.data() );
  nola::v256f bv = nola::avx2_load( b.data() );

  nola::v256f cv = nola::avx2_add(av, bv);

  nola::avx2_store( c.data(), cv );

  std::cout << "v = " << cv[0] << " " << cv[1] << " "
                      << cv[2] << " " << cv[3] << " "
                      << cv[4] << " " << cv[5] << " "
                      << cv[6] << " " << cv[7] << std::endl;
}
