// avx512_float_width.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_float_width.cxx -o float_width.exe

// Usage:
//    ./float_width.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  std::int32_t w = nola::avx512_width<float>();

  std::cout << "w = " << w << std::endl;
}
