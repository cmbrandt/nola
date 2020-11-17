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


//
// Linear Algebra Add

template <class Real>
struct Blas_axpy {
  // static void
  // nola_axpy(const std::int32_t n,
  //           const Real alpha,
  //           const Real x[ ], const std::int32_t incx,
  //           Real y[ ], const std::int32_t incy);
};

template <>
struct Blas_axpy<float> {
  static void
  nola_axpy(const std::int32_t n,
            const float alpha,
            const float x[ ], const std::int32_t incx,
            float y[ ], const std::int32_t incy)
  {
    detail::nola_saxpy_(&n, &alpha, x, &incx, y, &incy);
  }
};

template <>
struct Blas_axpy<double> {
  static void
  nola_axpy(const std::int32_t n,
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
struct Blas_nrm2 {
  // static Real
  // nola_nrm2(const std::int32_t n,
  //           const Real x[ ], const std::int32_t incx);
};

template <>
struct Blas_nrm2<float> {
  static float
  nola_nrm2(const std::int32_t n,
            const float x[ ], const std::int32_t incx)
  {
    return detail::nola_snrm2_(&n, x, &incx);
  }
};

template <>
struct Blas_nrm2<double> {
  static double
  nola_nrm2(const std::int32_t n,
            const double x[ ], const std::int32_t incx)
  {
    return detail::nola_dnrm2_(&n, x, &incx);
  }
};


//
// Matrix Vector product

template <class Real>
struct Blas_gemv {
  // static void
  // nola_gemv(const char trans,
  //           const std::int32_t m, const std::int32_t n,
  //           const Real alpha,
  //           const Real a[ ], const std::int32_t lda,
  //           const Real x[ ], const std::int32_t incx,
  //           const Real beta,
  //           Real y[ ], const std::int32_t incy,
  //           std::int32_t length_trans)
};

template <>
struct Blas_gemv<float> {
  static void
  nola_gemv(const char trans,
            const std::int32_t m, const std::int32_t n,
            const float alpha,
            const float a[ ], const std::int32_t lda,
            const float x[ ], const std::int32_t incx,
            const float beta,
            float y[ ], const std::int32_t incy)
  {
    detail::nola_sgemv_(&trans, &m, &n, &alpha, a, &lda, x, &incx, &beta, y, &incy, 1);
  }
};

template <>
struct Blas_gemv<double> {
  static void
  nola_gemv(const char trans,
            const std::int32_t m, const std::int32_t n,
            const double alpha,
            const double a[ ], const std::int32_t lda,
            const double x[ ], const std::int32_t incx,
            const double beta,
            double y[ ], const std::int32_t incy)
  {
    detail::nola_dgemv_(&trans, &m, &n, &alpha, a, &lda, x, &incx, &beta, y, &incy, 1);
  }
};





//----------------------------------------------------------------------------//
// Definitions


//
// Linear Algebra Add

template <class Real>
inline void
linalg_add(std::int32_t n, Real alpha, Real const x[ ], Real y[ ])
{
  Blas_axpy<Real>::nola_axpy(n, alpha, x, std::int32_t{1}, y, std::int32_t{1});
}


//
// Euclidean Vector Norm

template <class Real>
inline Real
vector_norm2(std::int32_t n, Real const x[ ])
{
  return Blas_nrm2<Real>::nola_nrm2(n, x, std::int32_t{1});
}


//
// Matrix Vector Product

template <class Real, class Transpose>
inline void
matrix_vector_product(Transpose /* trans */,
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

  Blas_gemv<Real>::nola_gemv(TRANS, m, n, alpha, a, m, x,
                             std::int32_t{1}, beta, y, std::int32_t{1});
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