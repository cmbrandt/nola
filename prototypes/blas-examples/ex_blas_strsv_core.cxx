
// g++-9 -Wall ex_blas_strsv_core.cxx ../../source/libnola.a -lgfortran -o strsv.exe

#include <cstdint>
#include <iostream>
#include <vector>


extern "C" void strsv_(const char* uplo, const char* trans, const char* diag, const std::int32_t* n, const float a[ ], const std::int32_t* lda,
                       float x[ ], const std::int32_t* incx, std::int32_t length_uplo, std::int32_t length_trans, std::int32_t length_diag);


int main()
{
  std::cout << "\nSTRSV Core Interface Example." << std::endl;

  // Specify form of operations
  char uplo  = 'U'; // A is upper triangular
  char trans = 'N'; // op(A) involves A^(-1)
  char diag  = 'N'; // A is not unit triangular

  // Order of matrix, length of vector
  std::int32_t n = 3;

  // (Flattened) matrix of values
  std::vector<float> a{ 2.0, 0.0, 0.0, 6.0, 1.0, 0.0, -8.0, 5.0, 3.0 };

  // First dimension of matrix
  std::int32_t lda = n;

  // Vector of values
  std::vector<float> x{ 2.0, 0.5, 0.2 };

  // Storage spacing between elements of vector
  std::int32_t incx = 1;

  // Compute operation x := A^(-1)*x
  strsv_(&uplo, &trans, &diag, &n, a.data(), &lda, x.data(),
         &incx, 1, 1, 1);

  for (int i = 0; i < 3; ++i)
    std::cout << " " << x[i];

  std::cout << std::endl;

  // Vector X = [
  //  0.7667 0.1667 0.06667
  // ]
}