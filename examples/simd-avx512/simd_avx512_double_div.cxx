// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <array>
#include <iostream>
#include <nola/c++17/simd.hxx>


int main()
{
  std::array<double, 4> a{ 5.0, 5.0, 5.0, 5.0 }; 
  std::array<double, 4> b{ 2.0, 2.0, 2.0, 2.0 }; 
  std::array<double, 4> c;

  nola::v512d av = nola::avx512_load( a.data() );
  nola::v512d bv = nola::avx512_load( b.data() );

  nola::v512d cv = nola::avx512_div(av, bv);

  nola::avx512_store( c.data(), cv );

  std::cout << "v = " << cv[0] << " " << cv[1] << " "
                      << cv[2] << " " << cv[3] << std::endl;
}
