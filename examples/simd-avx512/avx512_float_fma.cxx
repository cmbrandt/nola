// avx512_float_fma.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -mfma -std=c++17 -O3 avx512_float_fma.cxx -o float_fma.exe

// Usage:
//    ./float_fma.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


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