// avx2_double_width.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_width.cxx -o double_width.exe

// Usage:
//    ./double_width.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::int32_t w = nola::avx2_width<double>();

  std::cout << "w = " << w << std::endl;
}
