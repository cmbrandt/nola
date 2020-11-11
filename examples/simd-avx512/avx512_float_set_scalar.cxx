// avx512_float_set_scalar.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_float_set_scalar.cxx -o float_set_scalar.exe

// Usage:
//    ./float_set_scalar.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  std::array<float, 8> a;

  nola::v512f av = nola::avx512_set_scalar( float(5.0) );

  nola::avx512_store( a.data(), av );

  std::cout << "v = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << " "
                      << a[4] << " " << a[5] << " "
                      << a[6] << " " << a[7] << std::endl;
}
