// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_ROOT_HXX
#define NOLA_ROOT_HXX


namespace nola {

  //
  // Declarations

  template <class Real>
  inline std::tuple<Real, std::size_t>
  bisection(Real (*f)(Real), Real a, Real b);

  template <class Real>
  inline std::tuple<Real, std::size_t>
  bisection(Real (*f)(Real), Real a, Real b, Real tol std::size_t maxiter);



  template <class Real>
  inline std::tuple<double, std::size_t>
  brent(Real (*f)(Real), Real x0, Real x1);

  template <class Real>
  inline std::tuple<double, std::size_t>
  brent(Real (*f)(Real), Real x0, Real x1, Real tol std::size_t maxiter);



  template <class Real>
  inline std::tuple<Real, std::size_t>
  fixed_point(Real (*g)(Real), Real x0);

  template <class Real>
  inline std::tuple<Real, std::size_t>
  fixed_point(Real (*g)(Real), Real x0, Real tol std::size_t maxiter);



  template <class Real>
  inline std::tuple<Real, std::size_t>
  newton(Real (*f)(Real), Real (*fp)(Real), Real x0);

  template <class Real>
  inline std::tuple<Real, std::size_t>
  newton(Real (*f)(Real), Real (*fp)(Real), Real x0, Real tol std::size_t maxiter);



  template <class Real>
  inline std::tuple<Real, std::size_t>
  secant(Real (*f)(Real), Real x0, Real x1);

  template <class Real>
  inline std::tuple<Real, std::size_t>
  secant(Real (*f)(Real), Real x0, Real x1, Real tol std::size_t maxiter);



  //
  // Implementation Functions

  namespace detail {

    template <class Real>
    inline std::tuple<Real, std::size_t>
    bisection_impl(Real (*f)(Real), Real a, Real b, Real tol std::size_t maxiter)
    {

    }

    template <class Real>
    inline std::tuple<double, std::size_t>
    brent_impl(Real (*f)(Real), Real x0, Real x1, Real tol std::size_t maxiter)
    {

    }

    template <class Real>
    inline std::tuple<Real, std::size_t>
    fixed_point_impl(Real (*g)(Real), Real x0, Real tol std::size_t maxiter)
    {

    }

    template <class Real>
    inline std::tuple<Real, std::size_t>
    newton_impl(Real (*f)(Real), Real (*fp)(Real), Real tol std::size_t maxiter)
    {

    }

    template <class Real>
    inline std::tuple<Real, std::size_t>
    secant_impl(Real (*f)(Real), Real x0, Real x1, Real tol std::size_t maxiter)
    {

    }

  } // namespace detail



  //
  // C++17 Interfaces

  template <class Real>
  inline std::tuple<Real, std::size_t>
  bisection(Real (*f)(Real), Real a, Real b)
  {
    Real tol = 1e-10;
    std::size_t maxiter = 100;

    return nola::detail::bisection_impl(f, a, b, tol, maxiter);
  }

  template <class Real>
  inline std::tuple<Real, std::size_t>
  bisection(Real (*f)(Real), Real a, Real b, Real tol std::size_t maxiter)
  {
    return nola::detail::bisection_impl(f, a, b, tol, maxiter);
  }



  template <class Real>
  inline std::tuple<double, std::size_t>
  brent(Real (*f)(Real), Real x0, Real x1)
  {
    Real tol = 1e-10;
    std::size_t maxiter = 100;

    return nola::detail::brent_impl(f, x0, x1, tol, maxiter);
  }

  template <class Real>
  inline std::tuple<double, std::size_t>
  brent(Real (*f)(Real), Real x0, Real x1, Real tol, std::size_t maxiter)
  {
    return nola::detail::brent_impl(f, x0, x1, tol, maxiter);
  }



  template <class Real>
  inline std::tuple<Real, std::size_t>
  fixed_point(Real (*g)(Real), Real x0)
  {
    Real tol = 1e-10;
    std::size_t maxiter = 100;

    return nola::detail::fixed_point_impl(g, x0, tol, maxiter);
  }

  template <class Real>
  inline std::tuple<Real, std::size_t>
  fixed_point(Real (*g)(Real), Real x0, Real tol, std::size_t maxiter)
  {
    return nola::detail::fixed_point_impl(g, x0, tol, maxiter);
  }



  template <class Real>
  inline std::tuple<Real, std::size_t>
  newton(Real (*f)(Real), Real (*fp)(Real), Real x0)
  {
    Real tol = 1e-10;
    std::size_t maxiter = 100;

    return nola::detail::newton_impl(f, fp, x0, tol, maxiter);
  }

  template <class Real>
  inline std::tuple<Real, std::size_t>
  newton(Real (*f)(Real), Real (*fp)(Real), Real x0, Real tol, std::size_t maxiter)
  {
    return nola::detail::newton_impl(f, fp, x0, tol, maxiter);
  }



  template <class Real>
  inline std::tuple<Real, std::size_t>
  secant(Real (*f)(Real), Real x0, Real x1, Real tol)
  {
    Real tol = 1e-10;
    std::size_t maxiter = 100;

    return nola::detail::secant_impl(f, x0, x1, tol, maxiter);
  }

  template <class Real>
  inline std::tuple<Real, std::size_t>
  secant(Real (*f)(Real), Real x0, Real x1, Real tol, std::size_t maxiter)
  {
    return nola::detail::secant_impl(f, x0, x1, tol, maxiter);
  }



} // namespace nola


#endif