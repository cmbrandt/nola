// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<double, 4> a;

  nola::v512d av = nola::avx512_set_zero<double>();

  nola::avx512_store( a.data(), av );

  std::cout << "a = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << std::endl;
}