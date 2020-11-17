
// g++-10 -Wall -std=c++20 ex_blas_sgemm_core.cxx -I ~/projects/nola/include ../../lib/libnola.a -lgfortran -o sgemm.exe

#include <cstdint>
#include <iostream>
#include <vector>
#include <nola/detail/blas_impl.hxx>


int main()
{
  std::cout << "\nSGEMM Core Interface Example." << std::endl;

  // Specify form of op(A) and op(B)
  char transa = 'N';
  char transb = 'N';

  // Dimensions of matrices
  std::int32_t m = 4; // rows in input matrix A, rows in solution matrix C
  std::int32_t n = 3; // cols in input matrix B, cols in solution matrix C
  std::int32_t k = 2; // cols in input matrix A, rows in input matrix B

  // Scalar coefficients
  float alpha = 0.25;
  float beta  = 0.75;

  // (Flattened) matrices of values
  std::vector<float>
    a{ 1.0, 3.0, 5.0, 7.0, 2.0, 4.0, 6.0, 8.0 };
  std::vector<float>
    b{ 1.5, 4.5, 2.5, 5.5, 3.5, 6.5 };
  std::vector<float>
    c{ 1.0, 4.0, 7.0, 10.0, 2.0, 5.0, 8.0, 11.0, 3.0, 6.0, 9.0, 12.0 };

  // First dimension of matrices
  std::int32_t lda = m;
  std::int32_t ldb = k;
  std::int32_t ldc = m;

  // Compute operation C := alpha*A*B + beta*C
  nola::blas::detail::nola_sgemm_(&transa, &transb, &m, &n, &k, &alpha, a.data(), &lda,
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