// avx512_float_reduce.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_float_reduce.cxx -o float_reduce.exe

// Usage:
//    ./float_reduce.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  std::array<float, 8> a{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }; 

  nola::v512f av = nola::avx512_load( a.data() );

  float r = nola::avx512_reduce(av);

  std::cout << "r = " << r << std::endl;
}
