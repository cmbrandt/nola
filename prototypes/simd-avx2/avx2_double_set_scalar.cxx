// avx2_double_set_scalar.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_set_scalar.cxx -o double_set_scalar.exe

// Usage:
//    ./double_set_scalar.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<double, 4> a;

  nola::v256d av = nola::avx2_set_scalar( float(5.0) );

  nola::avx2_store( a.data(), av );

  std::cout << "a = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << std::endl;
}
