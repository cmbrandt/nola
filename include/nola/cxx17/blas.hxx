// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_BLAS_HXX
#define NOLA_CXX17_BLAS_HXX

#include <cstdint> // std::int32_t
#include <nola/detail/blas_impl.hxx>


namespace nola
{
namespace blas
{


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
                    Tranpose trans,
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


} // namespace blas
} // namespace nola


#endif