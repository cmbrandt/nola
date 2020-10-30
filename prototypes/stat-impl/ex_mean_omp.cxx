// ex_mean_omp.cxx

// g++-9 -Wall -std=c++17 -O3 -fopenmp ex_mean_omp.cxx -o mean

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "mean_serial.hxx"
#include "mean_simd.hxx"
#include "mean_parallel.hxx"
#include "mean_parallel_simd.hxx"


int main()
{
  std::cout << "\nArithmetic Mean C++17 Interface Example." << std::endl;


  //
  // Sequence of values
  std::vector<double> x(100000000, 5.0);


  //
  // Declare start and stop time points
  std::chrono::steady_clock::time_point s1, s2;
  std::chrono::duration<double>         d;


  //
  // Serial

  s1 = std::chrono::steady_clock::now();

  double m1 = nola::arithmetic_mean_serial( x.data(), x.size() );
  std::cout << "\narithmetic_mean_serial        = " << m1 << std::endl;

  s2 = std::chrono::steady_clock::now();
  d  = s2 - s1;

  std::cout << "time to compute:  " << d.count() << std::endl;


  //
  // SIMD

  s1 = std::chrono::steady_clock::now();

  double m2 = nola::arithmetic_mean_simd( x.data(), x.size() );
  std::cout << "\narithmetic_mean_simd          = " << m2 << std::endl;

  s2 = std::chrono::steady_clock::now();
  d  = s2 - s1;

  std::cout << "time to compute:  " << d.count() << std::endl;


  //
  // Parallel

  s1 = std::chrono::steady_clock::now();

  double m3 = nola::arithmetic_mean_parallel( x.data(), x.size() );
  std::cout << "\narithmetic_mean_parallel      = " << m3 << std::endl;

  s2 = std::chrono::steady_clock::now();
  d  = s2 - s1;

  std::cout << "time to compute:  " << d.count() << std::endl;


  //
  // Parallel SIMD

  s1 = std::chrono::steady_clock::now();

  double m4 = nola::arithmetic_mean_parallel_simd( x.data(), x.size() );
  std::cout << "\narithmetic_mean_parallel_simd = " << m4 << std::endl;

  s2 = std::chrono::steady_clock::now();
  d  = s2 - s1;

  std::cout << "time to compute:  " << d.count() << std::endl << std::endl;

}