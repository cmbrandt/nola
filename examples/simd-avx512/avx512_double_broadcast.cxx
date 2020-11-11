// avx512_double_broacast.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_double_broadcast.cxx -o double_broadcast.exe

// Usage:
//    ./double_broadcast.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  double as = 5.0; 

  std::array<double, 4> a;

  nola::v512d av = nola::avx512_broadcast(&as);

  nola::avx512_store( a.data(), av );

  std::cout << "a = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << std::endl;
}
