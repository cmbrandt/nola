// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX


#include <cmath>
#include <cstdlib>



namespace nola {

  //
  // Declarations

  template <class Real>
  inline Real
  arithmetic_mean(Real const x[ ], std::size_t n);

  template <class Real>
  inline Real
  variance(Real const x[ ], std::size_t n);

  template <class Real>
  inline Real
  standard_deviation(Real const x[ ], std::size_t n);

  template <class Real>
  inline Real
  covariance(Real const x[ ], Real const y[ ], std::size_t n);

  template <class Real>
  inline Real
  correlation(Real const x[ ], Real const y[ ], std::size_t n);



  //
  // Implementation Functions

  namespace detail {

    template <class Real>
    inline Real
    arithmetic_mean_impl(Real const x[ ], std::size_t n)
    {
      //
      // Compute and return the mean of the sequence

      Real sum{0.0};

      for (std::size_t i = 0; i < n; ++i)
        sum += x[i];

      return sum / n;
    }



    template <class Real>
    inline Real
    variance_impl(Real const x[ ], std::size_t n)
    {
      //
      // Compute the mean of the sequence

      Real sum{0.0};

      for (std::size_t i = 0; i < n; ++i)
        sum += x[i];

      Real mean = sum / n;

      //
      // Compute and return the variance of the sequence

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i) {
        Real center = x[i] - mean;
        sum += center * center;
      }

      return sum / (n - 1);
    }



    template <class Real>
    inline Real
    standard_deviation_impl(Real const x[ ], std::size_t n)
    {
      //
      // Compute the mean of the sequence

      Real sum{0.0};

      for (std::size_t i = 0; i < n; ++i)
        sum += x[i];

      Real mean = sum / n;

      //
      // Compute the variance of the sequence

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i) {
        Real center = x[i] - mean;
        sum += center * center;
      }

      Real var = sum / (n - 1);

      //
      // Compute and return the standard deviation of the sequence

      return std::sqrt(var);
    }



    template <class Real>
    inline Real
    covariance_impl(Real const x[ ], Real const y[ ], std::size_t n)
    {
      //
      // Compute the mean of the first sequence

      Real sum{0.0};

      for (std::size_t i = 0; i < n; ++i)
        sum += x[i];

      Real x_mean = sum / n;

      //
      // Compute the mean of the second sequence

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i)
        sum += y[i];

      Real y_mean = sum / n;

      //
      // Compute and return the covariance of the two sequences

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i) {
        Real x_center = x[i] - x_mean;
        Real y_center = y[i] - y_mean;
        sum += x_center * y_center;
      }

      return sum / (n - 1);
    }



    template <class Real>
    inline Real
    correlation_impl(Real const x[ ], Real const y[ ], std::size_t n)
    {
      //
      // Compute the mean of the first sequence

      Real sum{0.0};

      for (std::size_t i = 0; i < n; ++i)
        sum += x[i];

      Real x_mean = sum / n;

      //
      // Compute the variance of the first sequence

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i) {
        Real x_center = x[i] - x_mean;
        sum += x_center * x_center;
      }

      Real x_var = sum / (n - 1);
      Real x_std = std::sqrt(x_var);

      //
      // Compute the mean of the second sequence

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i)
        sum += y[i];

      Real y_mean = sum / n;

      //
      // Compute the variance of the first sequence

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i) {
        Real y_center = y[i] - y_mean;
        sum += y_center * y_center;
      }

      Real y_var = sum / (n - 1);
      Real y_std = std::sqrt(y_var);

      //
      // Compute and return the correlation of the two sequences

      sum = 0.0;

      for (std::size_t i = 0; i < n; ++i) {
        Real x_center = x[i] - x_mean;
        Real y_center = y[i] - y_mean;
        sum += x_center * y_center;
      }

      Real cov = sum / (n - 1);
      return cov / (x_std * y_std);
    }



  } // namespace detail



  //
  // C++17 Interfaces

  template <class Real>
  inline Real
  arithmetic_mean(Real const x[ ], std::size_t n)
  {
    return nola::detail::arithmetic_mean_impl(x, n);
  }

  template <class Real>
  inline Real
  variance(Real const x[ ], std::size_t n)
  {
    return nola::detail::variance_impl(x, n);
  }

  template <class Real>
  inline Real
  standard_deviation(Real const x[ ], std::size_t n)
  {
    return nola::detail::standard_deviation_impl(x, n);
  }

  template <class Real>
  inline Real covariance(Real const x[ ], Real const y[ ], std::size_t n)
  {
    return nola::detail::covariance_impl(x, y, n);
  }

  template <class Real>
  inline Real
  correlation(Real const x[ ], Real const y[ ], std::size_t n)
  {
    return nola::detail::correlation_impl(x, y, n);
  }



} // namespace nola


#endif