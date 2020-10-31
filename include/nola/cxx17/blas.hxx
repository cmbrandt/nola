// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_BLAS_HXX
#define NOLA_CXX17_BLAS_HXX


namespace nola
{
namespace blas
{


//----------------------------------------------------------------------------//
// Declarations


template <class Real,
          class in_vector_1_t,
          class in_vector_2_t,
          class out_vector_t>
inline void
linalg_add(in_vector_1_t x, in_vector_2_t y, out_vector_t z);


template <class Real,
          class in_vector_t,
          class in_matrix_t,
          class out_vector_t>
inline void
matrix_vector_product(in_matrix_t A, in_vector_t x, out_vector_t y);


template <class Real,
          class in_matrix_1_t,
          class in_matrix_2_t,
          class out_matrix_t>
inline void
matrix_product(in_matrix_1_t A, in_matrix_2_t B, out_matrix_t C)


} // namespace blas
} // namespace nola


#endif