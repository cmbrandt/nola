// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <nola/cxx17/blas.hxx>
#include <nola/cxx17/util.hxx>
#include "cxx17_blas.hxx"


void cxx17_blas()
{
  std::int32_t fail{0};

  fail = cxx17_linalg_add_float(fail);
  fail = cxx17_linalg_add_double(fail);
  fail = cxx17_vector_norm2_float(fail);
  fail = cxx17_vector_norm2_double(fail);

  if (fail == 0)
    std::cout << "\ncxx17_blas() passed with zero errors." << std::endl;
  else
    std::cout << "\ncxx17_blas() had " << fail << " errors." << std::endl;
}


//
// Linear Algebra Addition

std::int32_t cxx17_linalg_add_float(std::int32_t fail)
{
  std::vector<float> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<float> y{ 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5 };
  std::vector<float> s{ 2.3, 3.1, 3.9, 4.7, 5.5, 6.3, 7.1, 7.9 };

  nola::blas::linalg_add( x.size(), 0.8f, x.data(), y.data() );

  float r = nola::util::max_abs_difference( y.size(), y.data(), s.data() );

  if (r > 0.000001f) {
    ++fail;
    std::cout << "\nERROR! nola::stat::cxx17_linalg_add( float )" << std::endl;
              nola::util::print_vector("Expected:", s.size(), s.data(), 2, 3);
              nola::util::print_vector("Computed:", y.size(), y.data(), 2, 3);
  }

  return fail;
}


std::int32_t cxx17_linalg_add_double(std::int32_t fail)
{
  std::vector<double> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  std::vector<double> y{ 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5 };
  std::vector<double> s{ 2.3, 3.1, 3.9, 4.7, 5.5, 6.3, 7.1, 7.9 };

  nola::blas::linalg_add( x.size(), 0.8, x.data(), y.data() );

  double r = nola::util::max_abs_difference( y.size(), y.data(), s.data() );

  if (r > 0.000000000001) {
    ++fail;
    std::cout << "\nERROR! nola::stat::cxx17_linalg_add( double )" << std::endl;
              nola::util::print_vector("Expected:", s.size(), s.data(), 2, 3);
              nola::util::print_vector("Computed:", y.size(), y.data(), 2, 3);
  }

  return fail;
}


//
// Vector Euclidean Norm
std::int32_t cxx17_vector_norm2_float(std::int32_t fail)
{
  std::vector<float> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

  float r = nola::blas::vector_norm2( x.size(), x.data() );

  bool b = std::abs(r - 14.2829) > 0.0001;
  if (b) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::stat::cxx17_vector_norm2( float )"
              << "\nsoln  = " << 14.2829f
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


std::int32_t cxx17_vector_norm2_double(std::int32_t fail)
{
  std::vector<double> x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

  double r = nola::blas::vector_norm2( x.size(), x.data() );

  bool b = std::abs(r - 14.2829) > 0.0001;
  if (b) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::stat::cxx17_vector_norm2( double )"
              << "\nsoln  = " << 14.2829
              << "\nr     = " << r << std::endl;
  }

  return fail;
}