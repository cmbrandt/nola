
// g++-9 -Wall ex_blas_dtrsm_core.cxx ../../source/libnola.a -lgfortran -o dtrsm.exe

#include <cstdint>
#include <iostream>
#include <vector>


extern "C" void dtrsm_(const char* side, const char* uplo, const char* transa, const char* diag, const std::int32_t* m, const std::int32_t* n,
                       const double* alpha, const double a[ ], const std::int32_t* lda, double b[ ], const std::int32_t* ldb, std::int32_t length_side,
                       std::int32_t length_uplo, std::int32_t length_transa, std::int32_t length_diag);


int main()
{
  std::cout << "\nDTRSM Core Interface Example." << std::endl;

  // Specify form of operations
  char side   = 'L'; // B is pre-multiplied from the left
  char uplo   = 'U'; // A is upper triangular
  char transa = 'N'; // op(A) involves A^(-1)
  char diag   = 'N'; // A is not unit triangular

  // Dimensions of matrices
  std::int32_t m = 3; // rows in solution matrix B, order of matrix A
  std::int32_t n = 2; // cols in solution matrix B

  // Scalar coefficient
  double alpha = 0.5;

  // (Flattened) matrices of values
  std::vector<double> a{ 2.0, 0.0, 0.0, 6.0, 1.0, 0.0, -8.0, 5.0, 3.0 };
  std::vector<double> b{ 2.5, 1.5, 0.5, 0.5, 0.5, 0.5 };

  // First dimension of matrices
  std::int32_t lda = m;
  std::int32_t ldb = m;

  // Compute operation B := alpha*A^(-1)*B
  dtrsm_(&side, &uplo, &transa, &diag, &m, &n, &alpha, a.data(),
         &lda, b.data(), &ldb, 1, 1, 1, 1);

  for (int i = 0; i < 6; ++i)
    std::cout << " " << b[i];

  std::cout << std::endl;

  // Matrix B = [
  //  -0.04167  0.9583
  //   0.3333  -0.1667
  //   0.08333  0.08333
  // ]
}