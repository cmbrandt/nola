// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_BLAS_HXX
#define NOLA_CXX17_BLAS_HXX

#include <cstdint>     // std::int32_t
#include <type_traits> // std::is_same_v
#include <nola/detail/blas_impl.hxx>


namespace nola
{
namespace blas
{


//----------------------------------------------------------------------------//
// Tags


//
// Transpose

struct transpose_t { };
constexpr auto transpose = transpose_t{};

struct no_transpose_t { };
constexpr auto no_transpose = no_transpose_t{};


//
// Triangle


struct upper_triangle_t { };
constexpr auto upper_triangle = upper_triangle_t{};

struct lower_triangle_t { };
constexpr auto lower_triangle = lower_triangle_t{};


//
// Diagonal Storage

struct implicit_unit_diagonal_t { };
constexpr auto implicit_unit_diagonal = implicit_unit_diagonal_t{};

struct explicit_diagonal_t { };
constexpr auto explicit_diagonal = explicit_diagonal_t{};


//----------------------------------------------------------------------------//
// Declarations


template <class Real>
inline void
linalg_add(std::int32_t n,
           Real alpha,
           Real const x[ ],
           Real y[ ]);

template <class Real>
inline Real
vector_norm2(std::int32_t n,
             Real const x[ ]);

template <class Real,
          class Transpose>
inline void
matrix_vector_product(Transpose trans,
                      std::int32_t m,
                      std::int32_t n,
                      Real alpha,
                      Real const a[ ],
                      Real const x[ ],
                      Real beta,
                      Real y[ ]);

template <class Real,
          class Triangle,
          class Transpose,
          class DiagonalStorage>
inline void
matrix_vector_solve(Triangle uplo,
                    Transpose trans,
                    DiagonalStorage diag,
                    std::int32_t n,
                    Real const a[ ],
                    Real x[ ]);

template <class Real,
          class TransposeA,
          class TransposeB>
inline void
matrix_product(TransposeA transa,
               TransposeB transb,
               std::int32_t m,
               std::int32_t n,
               std::int32_t k,
               Real alpha,
               Real const a[ ],
               Real const b[ ],
               Real beta,
               Real c [ ]);


//----------------------------------------------------------------------------//
// Helper classes


namespace detail
{


//
// Linear Algebra Add

template <class Real>
struct blas_axpy {
  // static void
  // axpy(const std::int32_t n,
  //      const Real alpha,
  //      const Real x[ ], const std::int32_t incx,
  //      Real y[ ], const std::int32_t incy);
};

template <>
struct blas_axpy<float> {
  static void
  axpy(const std::int32_t n,
       const float alpha,
       const float x[ ], const std::int32_t incx,
       float y[ ], const std::int32_t incy)
  {
    detail::nola_saxpy_(&n, &alpha, x, &incx, y, &incy);
  }
};

template <>
struct blas_axpy<double> {
  static void
  axpy(const std::int32_t n,
       const double alpha,
       const double x[ ], const std::int32_t incx,
       double y[ ], const std::int32_t incy)
  {
    detail::nola_daxpy_(&n, &alpha, x, &incx, y, &incy);
  }
};


//
// Euclidean Vector Norm


template <class Real>
struct blas_nrm2 {
  // static Real
  // nrm2(const std::int32_t n,
  //      const Real x[ ], const std::int32_t incx);
};

template <>
struct blas_nrm2<float> {
  static float
  nrm2(const std::int32_t n,
       const float x[ ], const std::int32_t incx)
  {
    return detail::nola_snrm2_(&n, x, &incx);
  }
};

template <>
struct blas_nrm2<double> {
  static double
  nrm2(const std::int32_t n,
       const double x[ ], const std::int32_t incx)
  {
    return detail::nola_dnrm2_(&n, x, &incx);
  }
};


//
// Matrix Vector product

template <class Real>
struct blas_gemv {
  // static void
  // gemv(const char trans,
  //      const std::int32_t m, const std::int32_t n,
  //      const Real alpha,
  //      const Real a[ ], const std::int32_t lda,
  //      const Real x[ ], const std::int32_t incx,
  //      const Real beta,
  //      Real y[ ], const std::int32_t incy,
  //      std::int32_t length_trans);
};

template <>
struct blas_gemv<float> {
  static void
  gemv(const char trans,
       const std::int32_t m, const std::int32_t n,
       const float alpha,
       const float a[ ], const std::int32_t lda,
       const float x[ ], const std::int32_t incx,
       const float beta,
       float y[ ], const std::int32_t incy)
  {
    detail::nola_sgemv_(&trans, &m, &n, &alpha, a, &lda,
                        x, &incx, &beta, y, &incy, 1);
  }
};

template <>
struct blas_gemv<double> {
  static void
  gemv(const char trans,
       const std::int32_t m, const std::int32_t n,
       const double alpha,
       const double a[ ], const std::int32_t lda,
       const double x[ ], const std::int32_t incx,
       const double beta,
       double y[ ], const std::int32_t incy)
  {
    detail::nola_dgemv_(&trans, &m, &n, &alpha, a, &lda,
                        x, &incx, &beta, y, &incy, 1);
  }
};


//
// Matrix Vector Solve

template <class Real>
struct blas_trsv {
  // static void
  // trsv(const char uplo,
  //      const char trans,
  //      const char diag,
  //      const std::int32_t n,
  //      const float a[ ], const std::int32_t lda,
  //      float x[ ], const std::int32_t incx,
  //      std::int32_t length_uplo,
  //      std::int32_t length_trans,
  //      std::int32_t length_diag);
};


template <>
struct blas_trsv<float> {
  static void
  trsv(const char uplo,
       const char trans,
       const char diag,
       const std::int32_t n,
       const float a[ ], const std::int32_t lda,
       float x[ ], const std::int32_t incx,
       std::int32_t length_uplo,
       std::int32_t length_trans,
       std::int32_t length_diag)
  {
    detail::nola_strsv_(&uplo, &trans, &diag, &n, a, &lda, x, &incx,
                        length_uplo, length_trans, length_diag);
  }
};

template <>
struct blas_trsv<double> {
  static void
  trsv(const char uplo,
       const char trans,
       const char diag,
       const std::int32_t n,
       const double a[ ], const std::int32_t lda,
       double x[ ], const std::int32_t incx,
       std::int32_t length_uplo,
       std::int32_t length_trans,
       std::int32_t length_diag)
  {
    detail::nola_dtrsv_(&uplo, &trans, &diag, &n, a, &lda, x, &incx,
                        length_uplo, length_trans, length_diag);
  }
};


//
// Matrix Product

template <class Real>
struct blas_gemm {
  // static void
  // gemm(const char transa, const char transb,
  //      const std::int32_t m, const std::int32_t n, const std::int32_t k,
  //      const Real alpha,
  //      const Real a[ ], const std::int32_t lda,
  //      const Real b[ ], const std::int32_t ldb,
  //      const Real beta,
  //      Real c[ ], const std::int32_t ldc,
  //      std::int32_t length_transa, std::int32_t length_transb);
};

template <>
struct blas_gemm<float> {
  static void
  gemm(const char transa, const char transb,
       const std::int32_t m, const std::int32_t n, const std::int32_t k,
       const float alpha,
       const float a[ ], const std::int32_t lda,
       const float b[ ], const std::int32_t ldb,
       const float beta,
       float c[ ], const std::int32_t ldc,
       std::int32_t length_transa, std::int32_t length_transb)
  {
    detail::nola_sgemm_(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb,
                        &beta, c, &ldc, length_transa, length_transb);
  }
};

template <>
struct blas_gemm<double> {
  static void
  gemm(const char transa, const char transb,
       const std::int32_t m, const std::int32_t n, const std::int32_t k,
       const double alpha,
       const double a[ ], const std::int32_t lda,
       const double b[ ], const std::int32_t ldb,
       const double beta,
       double c[ ], const std::int32_t ldc,
       std::int32_t length_transa, std::int32_t length_transb)
  {
    detail::nola_dgemm_(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb,
                        &beta, c, &ldc, length_transa, length_transb);
  }
};


} // namespace detail


//----------------------------------------------------------------------------//
// Definitions


//
// Linear Algebra Add

template <class Real>
inline void
linalg_add(std::int32_t n, Real alpha, Real const x[ ], Real y[ ])
{
  detail::blas_axpy<Real>::axpy(n, alpha, x, 1, y, 1);
}


//
// Euclidean Vector Norm

template <class Real>
inline Real
vector_norm2(std::int32_t n, Real const x[ ])
{
  return detail::blas_nrm2<Real>::nrm2(n, x, 1);
}


//
// Matrix Vector Product

template <class Real, class Transpose>
inline void
matrix_vector_product(Transpose /*trans*/,
                      std::int32_t m,
                      std::int32_t n,
                      Real alpha,
                      Real const a[ ],
                      Real const x[ ],
                      Real beta,
                      Real y[ ])
{
  // Determine value of template parameter
  constexpr bool A_trans = std::is_same_v<Transpose, transpose_t>;

  // Define input paramter for BLAS routine
  const char TRANS = A_trans ? 'T' : 'N';

  detail::blas_gemv<Real>::gemv(TRANS, m, n, alpha, a, m, x, 1, beta, y, 1);
}


//
// Matrix Vector Solve

template <class Real,
          class Triangle,
          class Transpose,
          class DiagonalStorage>
inline void
matrix_vector_solve(Triangle /*uplo*/,
                    Transpose /*trans*/,
                    DiagonalStorage /*diag*/,
                    std::int32_t n,
                    Real const a[ ],
                    Real x[ ])
{
  // Determine values of template parameters
  constexpr bool A_uplo  = std::is_same_v<Triangle,        upper_triangle_t>;
  constexpr bool A_trans = std::is_same_v<Transpose,       transpose_t>;
  constexpr bool A_diag  = std::is_same_v<DiagonalStorage, implicit_unit_diagonal_t>;

  // Define input parameters for BLAS routine
  const char UPLO  = A_uplo  ? 'U' : 'L';
  const char TRANS = A_trans ? 'T' : 'N';
  const char DIAG  = A_diag  ? 'U' : 'N';

  detail::blas_trsv<Real>::trsv(UPLO, TRANS, DIAG, n, a, n, x, 1, 1, 1, 1);
}


//
// Matrix Product

template <class Real,
          class TransposeA,
          class TransposeB>
inline void
matrix_product(TransposeA /*transa*/,
               TransposeB /*transb*/,
               std::int32_t m,
               std::int32_t n,
               std::int32_t k,
               Real alpha,
               Real const a[ ],
               Real const b[ ],
               Real beta,
               Real c [ ])
{
  // Determine values of template parameters
  constexpr bool A_trans = std::is_same_v<TransposeA, transpose_t>;
  constexpr bool B_trans = std::is_same_v<TransposeB, transpose_t>;

  // Define input parameters for BLAS routine
  const char TRANSA = A_trans ? 'T' : 'N';
  const char TRANSB = B_trans ? 'T' : 'N';

  detail::blas_gemm<Real>::gemm(TRANSA, TRANSB, m, n, k, alpha,
                                a, m, b, k, beta, c, m, 1, 1);
}


/*

NOTES:
* how to handle case where argument passed to BLAS C++17 interface is undefined?
* how to handle cases where (assuming) the combination of templated arguments
  determines the definiton of other params, e.g. lda, ldb, etc.
* how to keep the impl as simple, clean, and readable as possible?

*/


} // namespace blas
} // namespace nola


#endif