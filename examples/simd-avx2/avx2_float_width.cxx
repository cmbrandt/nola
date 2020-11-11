// avx2_float_width.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_float_width.cxx -o float_width.exe

// Usage:
//    ./float_width.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::int32_t w = nola::avx2_width<float>();

  std::cout << "w = " << w << std::endl;
}
