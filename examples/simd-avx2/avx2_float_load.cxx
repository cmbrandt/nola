// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<float, 8> a{ 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 }; 
  std::array<float, 8> b;

  nola::v256f av = nola::avx2_load( a.data() );

  nola::avx2_store( b.data(), av );

  std::cout << "v = " << b[0] << " " << b[1] << " "
                      << b[2] << " " << b[3] << " "
                      << b[4] << " " << b[5] << " "
                      << b[6] << " " << b[7] << std::endl;
}
