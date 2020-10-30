// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_ROOT_TEST_HXX
#define NOLA_CXX17_ROOT_TEST_HXX

#include <cstdint>


std::int32_t cxx17_bisection_float(std::int32_t);
std::int32_t cxx17_brent_float(std::int32_t);
std::int32_t cxx17_fixed_point_float(std::int32_t);
std::int32_t cxx17_newton_float(std::int32_t);
std::int32_t cxx17_secant_float(std::int32_t);

std::int32_t cxx17_bisection_double(std::int32_t);
std::int32_t cxx17_brent_double(std::int32_t);
std::int32_t cxx17_fixed_point_double(std::int32_t);
std::int32_t cxx17_newton_double(std::int32_t);
std::int32_t cxx17_secant_double(std::int32_t);

void cxx17_root();


#endif