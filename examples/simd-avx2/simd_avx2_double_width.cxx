// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/cxx17/simd.hxx>


int main()
{
  std::int32_t w = nola::avx2_width<double>();

  std::cout << "w = " << w << std::endl;
}
