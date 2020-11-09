// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX23_STAT_TEST_HXX
#define NOLA_CXX23_STAT_TEST_HXX

#include <cstdint>


std::int32_t cxx23_arithmetic_mean_float(std::int32_t);
std::int32_t cxx23_arithmetic_mean_double(std::int32_t);
std::int32_t cxx23_variance_float(std::int32_t);
std::int32_t cxx23_variance_double(std::int32_t);
std::int32_t cxx23_standard_deviation_float(std::int32_t);
std::int32_t cxx23_standard_deviation_double(std::int32_t);
std::int32_t cxx23_covariance_float(std::int32_t);
std::int32_t cxx23_covariance_double(std::int32_t);
std::int32_t cxx23_correlation_float(std::int32_t);
std::int32_t cxx23_correlation_double(std::int32_t);

void cxx23_stat();


#endif