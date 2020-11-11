// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<double, 4> a{ 5.0, 5.0, 5.0, 5.0 }; 
  std::array<double, 4> b;

  nola::v256d av = nola::avx2_load( a.data() );

  nola::avx2_store( b.data(), av );

  std::cout << "b = " << b[0] << " " << b[1] << " "
                      << b[2] << " " << b[3] << std::endl;
}
