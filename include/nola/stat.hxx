// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX


#include <cstdlib>



namespace nola {

  //
  // Declarations

  template <class Real>
  inline Real
  arithmetic_mean(Real* x, std::size_t n);

  template <class Real>
  inline Real
  variance(Real* x, std::size_t n);

  template <class Real>
  inline Real
  standard_deviation(Real* x, std::size_t n);

  template <class Real>
  inline Real
  covariance(Real* x, Real* y, std::size_t n);

  template <class Real>
  inline Real
  correlation(Real* x, Real* y, std::size_t n);



  //
  // Implementation Functions

  namespace detail {

    template <class Real>
    inline Real
    arithmetic_mean_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

    template <class Real>
    inline Real
    variance_impl(Real* x, std::size_t) {
      //
      // compute variance
    }

    template <class Real>
    inline Real
    standard_deviation_impl(Real* x, std::size_t) {
      //
      // compute standard deviation
    }

    template <class Real>
    inline Real
    covariance_impl(Real* x, std::size_t) {
      //
      // compute covariance
    }

    template <class Real>
    inline Real
    correlation_impl(Real* x, std::size_t) {
      //
      // compute correlation
    }

  } // namespace detail



  //
  // C++17 Interfaces

  template <class Real>
  inline Real
  arithmetic_mean(Real* x, std::size_t n) {
    return nola::detail::arithmetic_mean_impl(x, n);
  }

  template <class Real>
  inline Real
  variance(Real* x, std::size_t n) {
    return nola::detail::variance_impl(x, n);
  }

  template <class Real>
  inline Real
  standard_deviation(Real* x, std::size_t n) {
    return nola::detail::standard_deviation_impl(x, n);
  }

  template <class Real>
  inline Real covariance(Real* x, std::size_t n) {
    return nola::detail::covariance_impl(x, n);
  }

  template <class Real>
  inline Real
  correlation(Real* x, std::size_t n) {
    return nola::detail::correlation_impl(x, n);
  }



} // namespace nola


#endif