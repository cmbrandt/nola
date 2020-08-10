// stat.hxx

#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX



#include <cstdlib>



namespace nola {

  //
  // Declarations

  template <typename Real>
  Real mean(Real* x, std::size_t n);

  template <typename Real>
  Real variance(Real* x, std::size_t n);

  template <typename Real>
  Real standard_deviation(Real* x, std::size_t n);

  template <typename Real>
  Real covariance(Real* x, Real* y, std::size_t n);

  template <typename Real>
  Real correlation(Real* x, Real* y, std::size_t n);



  //
  // Implementation Functions

  namespace detail {

    template <typename Real>
    Real mean_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

    template <typename Real>
    Real variance_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

    template <typename Real>
    Real standard_deviation_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

    template <typename Real>
    Real covariance_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

    template <typename Real>
    Real correlation_impl(Real* x, std::size_t) {
      //
      // compute mean
    }

  } // namespace detail



  //
  // C++17 Interfaces

  template <typename Real>
  Real mean(Real* x, std::size_t n) {
    return nola::detail::mean_impl(x, n);
  }

  template <typename Real>
  Real variance(Real* x, std::size_t n) {
    return nola::detail::variance_impl(x, n);
  }

  template <typename Real>
  Real standard_deviation(Real* x, std::size_t n) {
    return nola::detail::standard_deviation_impl(x, n);
  }

  template <typename Real>
  Real covariance(Real* x, std::size_t n) {
    return nola::detail::covariance_impl(x, n);
  }

  template <typename Real>
  Real correlation(Real* x, std::size_t n) {
    return nola::detail::correlation_impl(x, n);
  }



} // namespace nola



#endif