// avx2_float_add.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_float_add.cxx -o float_add.exe

// Usage:
//    ./float_add.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


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
