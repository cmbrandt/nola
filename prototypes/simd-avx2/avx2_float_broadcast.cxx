// avx2_float_broacast.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_float_broadcast.cxx -o float_broadcast.exe

// Usage:
//    ./float_broadcast.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  float as = 5.0; 

  std::array<float, 8> a;

  nola::v256f av = nola::avx2_broadcast(&as);

  nola::avx2_store( a.data(), av );

  std::cout << "v = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << " "
                      << a[4] << " " << a[5] << " "
                      << a[6] << " " << a[7] << std::endl;
}