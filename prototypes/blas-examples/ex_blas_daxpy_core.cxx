
// g++-9 -Wall ex_blas_daxpy_core.cxx ../../source/libnola.a -o daxpy.exe

#include <cstdint>
#include <iostream>
#include <vector>


extern "C" void daxpy_(const std::int32_t* n, const double* alpha, const double x[ ], const std::int32_t* incx, double y[ ], const std::int32_t* incy);


int main()
{
  std::cout << "\nDAXPY Core Interface Example." << std::endl;

  // Number of elements from each vector to sum
  std::int32_t n = 8;

  // Scalar coefficient
  double alpha = 0.8;

  // Vectors of values
  std::vector<double> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<double> y{ 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5 };

  // Storage spacing between elements of vectors
  std::int32_t incx = 1;
  std::int32_t incy = 1;

  // Compute operation y := alpha*x + y
  daxpy_(&n, &alpha, x.data(), &incx, y.data(), &incy);

  for (int i = 0; i < n; ++i)
    std::cout << " " << y[i];

  std::cout << std::endl;
  // Vector Y = [
  //  2.3 3.1 3.9 4.7 5.5 6.3 7.1 7.9
  // ]
}