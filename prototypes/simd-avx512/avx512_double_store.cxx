// avx512_double_store.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx512f -std=c++17 -O3 avx512_double_store.cxx -o double_store.exe

// Usage:
//    ./double_store.exe


#include <array>
#include <iostream>
#include "nola_avx512.hxx"


int main()
{
  std::array<double, 4> a;

  nola::v512d av = nola::avx512_set_zero();

  nola::avx512_store( a.data(), av );

  std::cout << "a = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << std::endl;
}
