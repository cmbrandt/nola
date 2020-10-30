// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_IMPL_HXX
#define NOLA_STAT_IMPL_HXX

#include <cmath>
#include <cstdint>


namespace nola
{
namespace stat
{
namespace detail
{


//----------------------------------------------------------------------------//
// Sequential Implementations


//
// Arithmetic Mean

template <class Real>
inline Real
arithmetic_mean_impl(std::int32_t n, const Real x[ ])
{
  // Compute and return the mean of the sequence
  Real sum{0.0};

  for (std::int32_t i = 0; i < n; ++i)
    sum += x[i];

  return sum / n;
}


//
// Variance

template <class Real>
inline Real
variance_impl(std::int32_t n, const Real x[ ])
{
  // Compute the mean of the sequence
  Real sum{0.0};

  for (std::int32_t i = 0; i < n; ++i)
    sum += x[i];

  Real mean = sum / n;

  // Compute and return the variance of the sequence
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i) {
    Real center = x[i] - mean;
    sum += center * center;
  }

  return sum / (n - 1);
}


//
// Standard Deviation

template <class Real>
inline Real
standard_deviation_impl(std::int32_t n, const Real x[ ])
{
  // Compute the mean of the sequence
  Real sum{0.0};

  for (std::int32_t i = 0; i < n; ++i)
    sum += x[i];

  Real mean = sum / n;

  // Compute the variance of the sequence
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i) {
    Real center = x[i] - mean;
    sum += center * center;
  }

  Real var = sum / (n - 1);

  // Compute and return the standard deviation of the sequence
  return std::sqrt(var);
}


//
// Covariance

template <class Real>
inline Real
covariance_impl(std::int32_t n, const Real x[ ], const Real y[ ])
{
  // Compute the mean of the first sequence
  Real sum{0.0};

  for (std::int32_t i = 0; i < n; ++i)
    sum += x[i];

  Real x_mean = sum / n;

  // Compute the mean of the second sequence
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i)
    sum += y[i];

  Real y_mean = sum / n;

  // Compute and return the covariance of the two sequences
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i) {
    Real x_center = x[i] - x_mean;
    Real y_center = y[i] - y_mean;
    sum += x_center * y_center;
  }

  return sum / (n - 1);
}


//
// Correlation

template <class Real>
inline Real
correlation_impl(std::int32_t n, const Real x[ ], const Real y[ ])
{
  // Compute the mean of the first sequence
  Real sum{0.0};

  for (std::int32_t i = 0; i < n; ++i)
    sum += x[i];

  Real x_mean = sum / n;

  // Compute the variance of the first sequence
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i) {
    Real x_center = x[i] - x_mean;
    sum += x_center * x_center;
  }

  Real x_var = sum / (n - 1);

  // Compute the mean of the second sequence
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i)
    sum += y[i];

  Real y_mean = sum / n;

  // Compute the variance of the second sequence
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i) {
    Real y_center = y[i] - y_mean;
    sum += y_center * y_center;
  }

  Real y_var = sum / (n - 1);

  // Compute the standard deviation of the two sequences
  Real x_std = std::sqrt(x_var);
  Real y_std = std::sqrt(y_var);

  // Compute and return the correlation of the two sequences
  sum = 0.0;

  for (std::int32_t i = 0; i < n; ++i) {
    Real x_center = x[i] - x_mean;
    Real y_center = y[i] - y_mean;
    sum += x_center * y_center;
  }

  Real cov = sum / (n - 1);
  return cov / (x_std * y_std);
}


} // namespace detail
} // namespace stat
} // namespace nola


#endif