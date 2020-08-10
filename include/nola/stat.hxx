// stat.hxx

#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX



#include <cstdlib>



namespace nola {

  //
  // Declarations

  template <class Real>
  Real mean(Real* x, std::size_t n);

  template <class Real>
  Real variance(Real* x, std::size_t n);

  template <class Real>
  Real standard_deviation(Real* x, std::size_t n);

  template <class Real>
  Real covariance(Real* x, Real* y, std::size_t n);

  template <class Real>
  Real correlation(Real* x, Real* y, std::size_t n);



  //
  // Implementation Functions

  namespace detail {

    template <class Real>
    Real mean_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

    template <class Real>
    Real variance_impl(Real* x, std::size_t) {
      //
      // compute variance
    }

    template <class Real>
    Real standard_deviation_impl(Real* x, std::size_t) {
      //
      // compute standard deviation
    }

    template <class Real>
    Real covariance_impl(Real* x, std::size_t) {
      //
      // compute covariance
    }

    template <class Real>
    Real correlation_impl(Real* x, std::size_t) {
      //
      // compute correlation
    }

  } // namespace detail



  //
  // C++17 Interfaces

  template <class Real>>
  Real mean(Real* x, std::size_t n) {
    return nola::detail::mean_impl(x, n);
  }

  template <class Real>
  Real variance(Real* x, std::size_t n) {
    return nola::detail::variance_impl(x, n);
  }

  template <class Real>
  Real standard_deviation(Real* x, std::size_t n) {
    return nola::detail::standard_deviation_impl(x, n);
  }

  template <class Real>
  Real covariance(Real* x, std::size_t n) {
    return nola::detail::covariance_impl(x, n);
  }

  template <class Real>
  Real correlation(Real* x, std::size_t n) {
    return nola::detail::correlation_impl(x, n);
  }



} // namespace nola



#endif