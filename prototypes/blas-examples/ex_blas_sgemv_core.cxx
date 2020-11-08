
// g++-9 -Wall ex_blas_sgemv_core.cxx ../../source/libnola.a -lgfortran -o sgemv.exe

#include <cstdint>
#include <iostream>
#include <vector>


extern "C" void sgemv_(const char* trans, const std::int32_t* m, const std::int32_t* n, const float* alpha, const float a[ ], const std::int32_t* lda,
                       const float x[ ], const std::int32_t* incx, const float* beta, float y[ ], const std::int32_t* incy, std::int32_t length_trans);


int main()
{
  std::cout << "\nSGEMV Core Interface Example." << std::endl;

  // Specify form of op(A)
  char trans = 'N';

  // Dimensions of matrix
  std::int32_t m = 3; // rows in input matrix A
  std::int32_t n = 2; // cols in input matrix A

  // Scalar coefficients
  float alpha = 0.5;
  float beta  = 0.25;

  // (Flattened) matrix of values
  std::vector<float> a{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };

  // First dimension of matrix
  std::int32_t lda = m;

  // Vectors of values
  std::vector<float> x{ 1.0, 2.0 };
  std::vector<float> y{ 1.0, 1.0, 1.0 };

  // Storage spacing between elements of vectors
  std::int32_t incx = 1;
  std::int32_t incy = 1;

  // Compute operation y := alpha*A*x + beta*y
  sgemv_(&trans, &m, &n, &alpha, a.data(), &lda, x.data(), &incx,
         &beta, y.data(), &incy, 1);

  for (int i = 0; i < 3; ++i)
    std::cout << " " << y[i];

  std::cout << std::endl;

  // Vector Y = [
  //  4.75 6.25 7.75
  // ]
}