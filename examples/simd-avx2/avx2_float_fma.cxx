// avx2_float_fma.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -mfma -std=c++17 -O3 avx2_float_fma.cxx -o float_fma.exe

// Usage:
//    ./float_fma.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<float, 8> a{ 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 }; 
  std::array<float, 8> b{ 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 }; 
  std::array<float, 8> c{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
  std::array<float, 8> d;

  nola::v256f av = nola::avx2_load( a.data() );
  nola::v256f bv = nola::avx2_load( b.data() );
  nola::v256f cv = nola::avx2_load( c.data() );

  nola::v256f dv = nola::avx2_fma(av, bv, cv);

  nola::avx2_store( d.data(), dv );

  std::cout << "v = " << dv[0] << " " << dv[1] << " "
                      << dv[2] << " " << dv[3] << " "
                      << dv[4] << " " << dv[5] << " "
                      << dv[6] << " " << dv[7] << std::endl;
}