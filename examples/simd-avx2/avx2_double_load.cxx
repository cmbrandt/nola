// avx2_double_load.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_load.cxx -o double_load.exe

// Usage:
//    ./double_load.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<double, 4> a{ 5.0, 5.0, 5.0, 5.0 }; 
  std::array<double, 4> b;

  nola::v256d av = nola::avx2_load( a.data() );

  nola::avx2_store( b.data(), av );

  std::cout << "b = " << b[0] << " " << b[1] << " "
                      << b[2] << " " << b[3] << std::endl;
}
