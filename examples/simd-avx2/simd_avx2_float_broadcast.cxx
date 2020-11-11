// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/cxx17/simd.hxx>


int main()
{
  float as = 5.0; 

  std::array<float, 8> a;

  nola::v256f av = nola::avx2_broadcast(&as);

  nola::avx2_store( a.data(), av );

  std::cout << "v = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << " "
                      << a[4] << " " << a[5] << " "
                      << a[6] << " " << a[7] << std::endl;
}
