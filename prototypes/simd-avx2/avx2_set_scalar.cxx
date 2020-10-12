// avx2_set_scalar.cxx

#include <array>
#include <iostream>
#include "nola_avx2.hxx"


int main()
{
  float a = 5.0;

  nola::v256f av = nola::avx2_set_scalar(a);

  std::array<float, 8> v;

  nola::avx2_store(v.data(), av);

  std::cout << "v = " << v[0] << " " << v[1] << " "
                      << v[2] << " " << v[3] << " "
                      << v[4] << " " << v[5] << " "
                      << v[6] << " " << v[7] << std::endl;
}