// avx2_double_broacast.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_broadcast.cxx -o double_broadcast.exe

// Usage:
//    ./double_broadcast.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  double as = 5.0; 

  std::array<double, 4> a;

  nola::v256d av = nola::avx2_broadcast(&as);

  nola::avx2_store( a.data(), av );

  std::cout << "a = " << a[0] << " " << a[1] << " "
                      << a[2] << " " << a[3] << std::endl;
}
