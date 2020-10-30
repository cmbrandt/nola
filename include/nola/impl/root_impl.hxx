// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_ROOT_IMPL_HXX
#define NOLA_ROOT_IMPL_HXX

#include <type_traits>
#include <cassert> // std::assert
#include <cstdlib> // std::int32_t


namespace nola
{
namespace stat
{
namespace detail
{


//----------------------------------------------------------------------------//
// Implementation functions


// Bisection

template <class Unary_function, class Real>
inline std::tuple<Real, std::int32_t>
bisection_impl(Unary_function && f, Real a, Real b, Real tol, std::int32_t iter)
{
  // Confirm a is the lower bound and b is the upper bound
  assert(a < b);

  Real fa = f(a);
  Real fb = f(b);

  // Confirm f(x0) and f(x1) have opposite signs
  assert(fa * fb <= 0.0);

  std::int32_t max_iter{iter};

  // Local variables used below
  Real c;
  Real fc;

  // Compute root
  iter = 0;
  while (iter < max_iter) {
    ++iter;

    c  = (a + b) / 2;
    fc = f(c);

    if (fb * fc > 0) {
      b  = c;
      fb = fc; // Omit right half of current interval
    }
    else if (fa * fc > 0) {
      a  = c;
      fa = fc; // Omit left half of current interval
    }
    else {
      a = c;
      b = c;
    }

    // Stopping criteria
    if (b - a < tol)
      break;

    c = (a + b) / 2;
  } // while loop

  return { c, iter };
}


// Brent's Method




// Fixed-Point Method




// Newton's Method




// Secant Method





} // namespace detail
} // namespace root
} // namespace nola


#endif