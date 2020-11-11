// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/cxx17/simd.hxx>


int main()
{
  std::array<float, 8> a{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }; 

  nola::v512f av = nola::avx512_load( a.data() );

  float r = nola::avx512_reduce(av);

  std::cout << "r = " << r << std::endl;
}
