// avx512_double_reduce.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_double_reduce.cxx -o double_reduce.exe

// Usage:
//    ./double_reduce.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  std::array<double, 4> a{ 1.0, 1.0, 1.0, 1.0 }; 

  nola::v512d av = nola::avx512_load( a.data() );

  double r = nola::avx512_reduce(av);

  std::cout << "r = " << r << std::endl;
}
