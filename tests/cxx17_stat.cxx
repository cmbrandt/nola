// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <iostream>
#include <vector>
#include <nola/cxx17/stat.hxx>
#include "cxx17_stat.hxx"


void cxx17_stat()
{
  std::int32_t fail{0};

  fail = cxx17_arithmetic_mean_float(fail);
  fail = cxx17_arithmetic_mean_double(fail);
  fail = cxx17_variance_float(fail);
  fail = cxx17_variance_double(fail);
  fail = cxx17_standard_deviation_float(fail);
  fail = cxx17_standard_deviation_double(fail);
  fail = cxx17_covariance_float(fail);
  fail = cxx17_covariance_double(fail);
  fail = cxx17_correlation_float(fail);
  fail = cxx17_correlation_double(fail);

  if (fail == 0)
    std::cout << "\ncxx17_stat() passed with zero errors." << std::endl;
  else
    std::cout << "\ncxx17_stat() had " << fail << " errors." << std::endl;
}


//
// Arithmetic Mean

std::int32_t cxx17_arithmetic_mean_float(std::int32_t fail)
{
  std::vector<float> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  float r = nola::stat::arithmetic_mean( x.size(), x.data() );

  if (r != 0.6f) {
    ++fail;
    std::cout << "\nERROR! nola::stat::arithmetic_mean( float )"
              << "\nsoln  = " << 0.6f
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


std::int32_t cxx17_arithmetic_mean_double(std::int32_t fail)
{
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double r = nola::stat::arithmetic_mean( x.size(), x.data() );
  
  if (r != 0.6) {
    ++fail;
    std::cout << "\nERROR! nola::stat::arithmetic_mean( double )"
              << "\nsoln  = " << 0.6
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


//
// Variance

std::int32_t cxx17_variance_float(std::int32_t fail)
{
  std::vector<float> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  float r = nola::stat::variance( x.size(), x.data() );

  if (r != 0.1f) {
    ++fail;
    std::cout << "\nERROR! nola::stat::variance( float )"
              << "\nsoln  = " << 0.1f
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


std::int32_t cxx17_variance_double(std::int32_t fail)
{
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double r = nola::stat::variance( x.size(), x.data() );
  
  if (r != 0.1) {
    ++fail;
    std::cout << "\nERROR! nola::stat::variance( double )"
              << "\nsoln  = " << 0.1
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


//
// Standard Deviation

std::int32_t cxx17_standard_deviation_float(std::int32_t fail)
{
  std::vector<float> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  float r = nola::stat::standard_deviation( x.size(), x.data() );

  bool b = std::abs( r - 0.3162f) > 0.0001f;

  if (b) {
    ++fail;
    std::cout << "\nERROR! nola::stat::standard_deviation( float )"
              << "\nsoln  = " << 0.3162f
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


std::int32_t cxx17_standard_deviation_double(std::int32_t fail)
{
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double r = nola::stat::standard_deviation( x.size(), x.data() );
  
  bool b = std::abs( r - 0.3162) > 0.0001;

  if (b) {
    ++fail;
    std::cout << "\nERROR! nola::stat::standard_deviation( double )"
              << "\nsoln  = " << 0.3162
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


//
// Covariance

std::int32_t cxx17_covariance_float(std::int32_t fail)
{
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  float r = nola::stat::covariance( x.size(), x.data(), y.data() );

  bool b = std::abs( r + 0.27f) > 0.001f;

  if (b) {
    ++fail;
    std::cout << "\nERROR! nola::stat::covariance( float )"
              << "\nsoln  = " << -0.27f
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


std::int32_t cxx17_covariance_double(std::int32_t fail)
{
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  double r = nola::stat::covariance( x.size(), x.data(), y.data() );

  bool b = std::abs( r + 0.27) > 0.001;

  if (b) {
    ++fail;
    std::cout << "\nERROR! nola::stat::covariance( double )"
              << "\nsoln  = " << -0.27
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


//
// Correlation

std::int32_t cxx17_correlation_float(std::int32_t fail)
{
  std::vector<float> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<float> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  float r = nola::stat::correlation( x.size(), x.data(), y.data() );

  bool b = std::abs( r + 0.9f) > 0.01f;

  if (b) {
    ++fail;
    std::cout << "\nERROR! nola::stat::correlation( float )"
              << "\nsoln  = " << -0.9f
              << "\nr     = " << r << std::endl;
  }

  return fail;
}


std::int32_t cxx17_correlation_double(std::int32_t fail)
{
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  double r = nola::stat::correlation( x.size(), x.data(), y.data() );
  
  bool b = std::abs( r + 0.9) > 0.01;

  if (b) {
    ++fail;
    std::cout << "\nERROR! nola::stat::correlation( double )"
              << "\nsoln  = " << -0.9
              << "\nr     = " << r << std::endl;
  }

  return fail;
}