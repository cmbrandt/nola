// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Double Store Example." << std::endl;

  // Input data
  std::vector<double> a{ 5.5, 5.5, 5.5, 5.5 }; 
  
  // Container to store solution
  std::vector<double> b(4);

  // Define SIMD object using input data
  auto av = nola::simd::avx2_load( a.data() );

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( b.data(), av );

  // Display result
  nola::util::print_vector("\nvector 'b'", b.size(), b.data(), 2, 3);
  
  // b = [
  //  5.5 5.5 5.5 5.5
  // ]
}