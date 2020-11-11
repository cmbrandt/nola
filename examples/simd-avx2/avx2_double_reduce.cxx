// avx2_double_reduce.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_reduce.cxx -o double_reduce.exe

// Usage:
//    ./double_reduce.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<double, 4> a{ 1.0, 1.0, 1.0, 1.0 }; 

  nola::v256d av = nola::avx2_load( a.data() );

  double r = nola::avx2_reduce(av);

  std::cout << "r = " << r << std::endl;
}
