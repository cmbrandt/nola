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



//----------------------------------------------------------------------------//
// Definitions

//
// Linear Algebra Add

template <>
inline void
linalg_add(std::int32_t n, float alpha, float const x[ ], float y[ ]);
{
  return 5.0;
}


template <>
inline void
linalg_add(std::int32_t n, double alpha, double const x[ ], double y[ ]);
{
  return 5.0;
}


//
// Euclidean Vector Norm

template <>
inline float
vector_norm2(std::int32_t n, float const x[ ])
{
  std::int32_t incx = 1;
  return snrm2_(&n, x, &incx);
}


template <>
inline double
vector_norm2(std::int32_t n, double const x[ ])
{
  std::int32_t incx = 1;
  return dnrm2_(&n, x, &incx);
}


} // namespace blas
} // namespace nola


#endif