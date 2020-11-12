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
linalg_add(std::int32_t n, Real alpha, Real const x[ ], Real y[ ]);

template <class Real>
inline Real
vector_norm2(std::int32_t n, Real const x[ ]);

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
// Definitions


//
// Linear Algebra Add

template <>
inline void
linalg_add(std::int32_t n, float alpha, float const x[ ], float y[ ])
{
  std::int32_t inc = 1;
  return detail::saxpy_(&n, &alpha, x, &inc, y, &inc);
}

template <>
inline void
linalg_add(std::int32_t n, double alpha, double const x[ ], double y[ ])
{
  std::int32_t inc = 1;
  return detail::daxpy_(&n, &alpha, x, &inc, y, &inc);
}


//
// Euclidean Vector Norm

template <>
inline float
vector_norm2(std::int32_t n, float const x[ ])
{
  std::int32_t inc = 1;
  return detail::snrm2_(&n, x, &inc);
}

template <>
inline double
vector_norm2(std::int32_t n, double const x[ ])
{
  std::int32_t inc = 1;
  return detail::dnrm2_(&n, x, &inc);
}


//
// Matrix Vector Product

template <class Transpose>
inline void
matrix_vector_product(Transpose trans,
                      std::int32_t m,
                      std::int32_t n,
                      float alpha,
                      float const a[ ],
                      float const x[ ],
                      float beta,
                      float y[ ])
{
  if constexpr (std::is_same_v<Transpose, transpose_t>) {
    char t = 'T';
    std::int32_t inc = 1;
    return detail::sgemv_(&t, &m, &n, &alpha, a, &m, x, &inc, &beta, y, &inc, 1);
  }
  else {
    char t = 'N';
    std::int32_t inc = 1;
    return detail::sgemv_(&t, &m, &n, &alpha, a, &m, x, &inc, &beta, y, &inc, 1);
  }
}


template <class Transpose>
inline void
matrix_vector_product(__attribute__((unused)) Transpose trans,
                      std::int32_t m,
                      std::int32_t n,
                      double alpha,
                      double const a[ ],
                      double const x[ ],
                      double beta,
                      double y[ ])
{
  std::int32_t inc = 1;

  char t = 'T';

  if constexpr (std::is_same_v<Transpose, no_transpose_t>)
    t = 'N';

  return detail::dgemv_(&t, &m, &n, &alpha, a, &m, x, &inc, &beta, y, &inc, 1);

 /*
  if constexpr (std::is_same_v<Transpose, transpose_t>) {
    char t = 'T';
    std::int32_t inc = 1;
    return detail::dgemv_(&t, &m, &n, &alpha, a, &m, x, &inc, &beta, y, &inc, 1);
  }
  else {
    char t = 'N';
    std::int32_t inc = 1;
    return detail::dgemv_(&t, &m, &n, &alpha, a, &m, x, &inc, &beta, y, &inc, 1);
  }
*/

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