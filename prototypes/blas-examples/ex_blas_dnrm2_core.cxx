
// g++-10 -Wall -std=c++20 ex_blas_dnrm2_core.cxx -I ~/projects/nola/include ../../lib/libnola.a -lgfortran -o dnrm2.exe

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/detail/blas_impl.hxx>


int main()
{
  std::cout << "\nDNRM2 Core Interface Example." << std::endl;

  // Vectors of values
  std::vector<double> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

  // Length of array
  std::int32_t n = x.size();

  // Stride length between elements of array
  std::int32_t incx = 1;

  // Compute operation: n = (x'*x)^(1/2)
  double norm = nola::blas::detail::nola_dnrm2_(&n, x.data(), &incx);

  // Display solution
  std::cout << "\nnorm = " << norm << std::endl; // norm = 14.2829
}