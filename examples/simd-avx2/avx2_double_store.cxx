// avx2_double_store.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_store.cxx -o double_store.exe

// Usage:
//    ./double_store.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<double, 4> a;

  nola::v256d av = nola::avx2_set_zero();

  nola::avx2_store( a.data(), av );

  std::cout << "a = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << std::endl;
}
