// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_ROOT_HXX
#define NOLA_CXX17_ROOT_HXX

#include <cassert> // assert
#include <cmath>   // std::abs
#include <cstdlib> // std::size_t
#include <limits>  // std::numeric_limits
#include <utility> // std::forward
#include <nola/root_impl.hxx>


namespace nola
{
namespace root
{


//----------------------------------------------------------------------------//
// Declarations


template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
bisection(UnaryFunction && f, Real a, Real b);

template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
bisection(UnaryFunction && f, Real a, Real b, Real tol, std::int32_t maxiter);


template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
brent(UnaryFunction&& f, Real x0, Real x1);

template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
brent(UnaryFunction&& f, Real x0, Real x1, Real tol, std::int32_t maxiter);


template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
fixed_point(UnaryFunction&& g, Real x0);

template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
fixed_point(UnaryFunction&& g, Real x0, Real tol, std::int32_t maxiter);


template <class UnaryFunction1, class UnaryFunction2, class Real>
inline std::tuple<Real, std::size_t>
newton(UnaryFunction1&& f, UnaryFunction2&& fp, Real x0);

template <class UnaryFunction1, class UnaryFunction2, class Real>
inline std::tuple<Real, std::size_t>
newton(UnaryFunction1&& f, UnaryFunction2&& fp, Real x0, Real tol, std::int32_t maxiter);


template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
secant(UnaryFunction&& f, Real x0, Real x1);

template <class UnaryFunction, class Real>
inline std::tuple<Real, std::size_t>
secant(UnaryFunction&& f, Real x0, Real x1, Real tol, std::int32_t maxiter);


//----------------------------------------------------------------------------//
// Definitions


//
// Bisection Method

template <class Unary_function, class Real>
inline std::tuple<Real, std::size_t>
bisection(Unary_function && f, Real a, Real b, Real tol, std::int32_t maxiter)
{
  return detail::bisection_impl( std::forward<Unary_function>(f), a, b, tol, maxiter );
}

template <class Unary_function>
inline std::tuple<float, std::size_t>
bisection(Unary_function && f, float a, float b)
{
  float        tol{1e-5};
  std::int32_t maxiter{100};
  return detail::bisection_impl( std::forward<Unary_function>(f), a, b, tol, maxiter );
}

template <class Unary_function>
inline std::tuple<double, std::size_t>
bisection(Unary_function && f, double a, double b)
{
  double       tol{1e-10};
  std::int32_t maxiter{100};
  return detail::bisection_impl( std::forward<Unary_function>(f), a, b, tol, maxiter );
}


//
// Brent's Method



//
// Fixed-Point Method



//
// Newton's Method



//
// Secant Method




} // namespace root
} // namespace nola


#endif