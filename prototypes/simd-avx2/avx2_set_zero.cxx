// avx2_set_zero.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_set_zero.cxx -o set_zero.exe

// Usage:
//    ./set_zero.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  nola::v256f av = nola::avx2_set_zero();

  std::array<float, 8> v;

  nola::avx2_store(v.data(), av);

  std::cout << "v = " << v[0] << " " << v[1] << " "
                      << v[2] << " " << v[3] << " "
                      << v[4] << " " << v[5] << " "
                      << v[6] << " " << v[7] << std::endl;
}