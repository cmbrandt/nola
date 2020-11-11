// avx512_float_load.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_float_load.cxx -o float_load.exe

// Usage:
//    ./float_load.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  std::array<float, 8> a{ 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0 }; 
  std::array<float, 8> b;

  nola::v512f av = nola::avx512_load( a.data() );

  nola::avx512_store( b.data(), av );

  std::cout << "v = " << b[0] << " " << b[1] << " "
                      << b[2] << " " << b[3] << " "
                      << b[4] << " " << b[5] << " "
                      << b[6] << " " << b[7] << std::endl;
}
