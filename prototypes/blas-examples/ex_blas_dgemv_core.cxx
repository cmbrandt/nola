
// g++-9 -Wall ex_blas_dgemv_core.cxx ../../source/libnola.a -lgfortran -o dgemv.exe

#include <cstdint>
#include <iostream>
#include <vector>


extern "C" void dgemv_(const char* trans, const std::int32_t* m, const std::int32_t* n, const double* alpha, const double a[ ], const std::int32_t* lda,
                       const double x[ ], const std::int32_t* incx, const double* beta, double y[ ], const std::int32_t* incy, std::int32_t length_trans);


int main()
{
  std::cout << "\nDGEMV Core Interface Example." << std::endl;

  // Specify form of op(A)
  char trans = 'N';

  // Dimensions of matrix
  std::int32_t m = 3; // rows in input matrix A
  std::int32_t n = 2; // cols in input matrix A

  // Scalar coefficients
  double alpha = 0.5;
  double beta  = 0.25;

  // (Flattened) matrix of values
  std::vector<double> a{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };

  // First dimension of matrix
  std::int32_t lda = m;

  // Vectors of values
  std::vector<double> x{ 1.0, 2.0 };
  std::vector<double> y{ 1.0, 1.0, 1.0 };

  // Storage spacing between elements of vectors
  std::int32_t incx = 1;
  std::int32_t incy = 1;

  // Compute operation y := alpha*A*x + beta*y
  dgemv_(&trans, &m, &n, &alpha, a.data(), &lda, x.data(), &incx,
         &beta, y.data(), &incy, 1);

  for (int i = 0; i < 3; ++i)
    std::cout << " " << y[i];

  std::cout << std::endl;

  // Vector Y = [
  //  4.75 6.25 7.75
  // ]
}