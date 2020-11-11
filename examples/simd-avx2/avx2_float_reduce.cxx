// avx2_float_reduce.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_float_reduce.cxx -o float_reduce.exe

// Usage:
//    ./float_reduce.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<float, 8> a{ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }; 

  nola::v256f av = nola::avx2_load( a.data() );

  float r = nola::avx2_reduce(av);

  std::cout << "r = " << r << std::endl;
}
