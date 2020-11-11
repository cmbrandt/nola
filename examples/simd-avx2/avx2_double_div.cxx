// avx2_double_div.cxx

// Compile:
//    g++-9 -Wall -pedantic -mavx2 -std=c++17 -O3 avx2_double_div.cxx -o double_div.exe

// Usage:
//    ./double_div.exe


#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  std::array<double, 4> a{ 5.0, 5.0, 5.0, 5.0 }; 
  std::array<double, 4> b{ 2.0, 2.0, 2.0, 2.0 }; 
  std::array<double, 4> c;

  nola::v256d av = nola::avx2_load( a.data() );
  nola::v256d bv = nola::avx2_load( b.data() );

  nola::v256d cv = nola::avx2_div(av, bv);

  nola::avx2_store( c.data(), cv );

  std::cout << "v = " << cv[0] << " " << cv[1] << " "
                      << cv[2] << " " << cv[3] << std::endl;
}
