// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_BLAS_TEST_HXX
#define NOLA_CXX17_BLAS_TEST_HXX

#include <cstdint>


std::int32_t cxx17_linalg_add_float(std::int32_t);
std::int32_t cxx17_linalg_add_double(std::int32_t);
std::int32_t cxx17_vector_norm2_float(std::int32_t);
std::int32_t cxx17_vector_norm2_double(std::int32_t);
std::int32_t cxx17_matrix_vector_product_float(std::int32_t);
std::int32_t cxx17_matrix_vector_product_double(std::int32_t);

void cxx17_blas();


#endif