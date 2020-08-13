// ex_mean_omp.cxx


#include <cstdlib>
#include <iostream>
#include <vector>
#include "mean_serial.hxx"
#include "mean_simd.hxx"
#include "mean_parallel.hxx"
#include "mean_parallel_simd.hxx"


int main()
{
  std::cout << "\nArithmetic Mean Nola Interface Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Serial
  double m1 = nola::arithmetic_mean_serial( x.data(), x.size() );
  std::cout << "\narithmetic_mean_serial        = " << m1 << std::endl; // m = 0.6000

  // SIMD
  double m2 = nola::arithmetic_mean_simd( x.data(), x.size() );
  std::cout << "\narithmetic_mean_simd          = " << m2 << std::endl; // m = 0.6000

  // Parallel
  double m3 = nola::arithmetic_mean_parallel( x.data(), x.size() );
  std::cout << "\narithmetic_mean_parallel      = " << m3 << std::endl; // m = 0.6000

  // Parallel SIMD
  double m4 = nola::arithmetic_mean_parallel_simd( x.data(), x.size() );
  std::cout << "\narithmetic_mean_parallel_simd = " << m4 << std::endl; // m = 0.6000

}