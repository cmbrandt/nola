
// g++-9 -Wall ex_blas_dgemm_core.cxx ../../source/libnola.a -lgfortran -o dgemm.exe

#include <cstdint>
#include <iostream>
#include <vector>


extern "C" void dgemm_(const char* transa, const char* transb, const std::int32_t* m, const std::int32_t* n, const std::int32_t* k,
                       const double* alpha, const double a[ ], const std::int32_t* lda, const double b[ ], const std::int32_t* ldb,
                       const double* beta, double c[ ], const std::int32_t* ldc, std::int32_t length_transa, std::int32_t length_transb);


int main()
{
  std::cout << "\nDGEMM Core Interface Example." << std::endl;

  // Specify form of op(A) and op(B)
  char transa = 'N';
  char transb = 'N';

  // Dimensions of matrices
  std::int32_t m = 4; // rows in input matrix A, rows in solution matrix C
  std::int32_t n = 3; // cols in input matrix B, cols in solution matrix C
  std::int32_t k = 2; // cols in input matrix A, rows in input matrix B

  // Scalar coefficients
  double alpha = 0.25;
  double beta  = 0.75;

  // (Flattened) matrices of values
  std::vector<double>
    a{ 1.0, 3.0, 5.0, 7.0, 2.0, 4.0, 6.0, 8.0 };
  std::vector<double>
    b{ 1.5, 4.5, 2.5, 5.5, 3.5, 6.5 };
  std::vector<double>
    c{ 1.0, 4.0, 7.0, 10.0, 2.0, 5.0, 8.0, 11.0, 3.0, 6.0, 9.0, 12.0 };

  // First dimension of matrices
  std::int32_t lda = m;
  std::int32_t ldb = k;
  std::int32_t ldc = m;

  // Compute operation C := alpha*A*B + beta*C
  dgemm_(&transa, &transb, &m, &n, &k, &alpha, a.data(), &lda,
         b.data(), &ldb, &beta, c.data(), &ldc, 1, 1);

  for (int i = 0; i < 12; ++i)
    std::cout << " " << c[i];

  std::cout << std::endl;

  // Matrix C = [
  //   3.375  4.875  6.375
  //   8.625 11.125 13.625
  //  13.875 17.375 20.875
  //  19.125 23.625 28.125
  // ]
}