// avx2_set_scalar.cxx

#include <iostream>
#include <vector>
//#include <immintrin.h>
#include "nola_avx2.hxx"


int main()
{
  float a = 5.0;

  nola::v256f av = nola::avx2_set_scalar(a);

  float v[8];
  //std::vector<float> v{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  nola::avx2_store(&v[0], av);

  std::cout << "v = " << v[0] << " " << v[1] << " "
                      << v[2] << " " << v[3] << " "
                      << v[4] << " " << v[5] << " "
                      << v[6] << " " << v[7] << std::endl;


}