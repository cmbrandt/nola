// brent.hxx

#ifndef BRENT_HXX
#define BRENT_HXX

#include <cassert> // assert
#include <cmath>   // std::abs
#include <cstdlib> // std::size_t
#include <limits>  // std::numeric_limits



namespace nola {

  //
  // Declarations

  template <class F, class Real>
  inline std::tuple<Real, std::size_t>
  brent(F const& f, Real x0, Real x1);

  template <class F, class Real>
  inline std::tuple<Real, std::size_t>
  brent(F const& f, Real x0, Real x1, Real tol, std::size_t maxiter);



  //
  // Implementation

  namespace detail {

    template <class F, class Real>
    inline std::tuple<Real, std::size_t>
    brent_impl(F const& f, Real x0, Real x1, Real tol, std::size_t iter)
    {
      Real fx0 = f(x0);
      Real fx1 = f(x1);

      // Confirm f(x0) and f(x1) have opposite signs
      assert(fx0 * fx1 <= 0.0);

      std::size_t max_iter{iter};  
      Real eps = std::numeric_limits<Real>::epsilon();

      if ( std::abs(fx0) < std::abs(fx1) )
        std::swap(x0,  x1);

      bool mflag{true};
      Real x2{x0};

      // Local variables used below
      Real fx2;
      Real s;
      Real d;

      // Compute root
      iter = 0;
      while (iter < max_iter) {
        ++iter;

        fx0 = f(x0);
        fx1 = f(x1);
        fx2 = f(x2);

        if ( (fx0 != fx2) and (fx1 != fx2) ) { // Inverse quadratic interpolation
          Real L0 = (x0 * fx1 * fx2) / ( (fx0 - fx1) * (fx0 - fx2) );
          Real L1 = (x1 * fx0 * fx2) / ( (fx1 - fx0) * (fx1 - fx2) );
          Real L2 = (x2 * fx1 * fx0) / ( (fx2 - fx0) * (fx2 - fx1) );
          s = L0 + L1 + L2;
        }
        else {                                 // Secant method
          s = x1 - ( (fx1 * (x1 - x0)) / (fx1 - fx0) );
        }

        if ( ( (s < ((fx1 * x0 + x1) / 4.0)) or (s > x1) )                           or
             ( (mflag == true)  and (std::abs(s  - x1) >= std::abs(x1 - x2) / 2.0) ) or
             ( (mflag == false) and (std::abs(s  - x1) >= std::abs(x2 - d)  / 2.0) ) or
             ( (mflag == true)  and (std::abs(x1 - x2) <  tol) )                     or
             ( (mflag == false) and (std::abs(x1 - d)  <  tol) ) ) {
          s = (x0 + x1) / 2.0;                 // Bisection method
          mflag = true;
        }
        else {
          mflag = false;
        }

        Real fs = f(s);

        d  = x2;
        x2 = x1;

        if (fx0 * fs < 0)
          x1 = s;
        else
          x0 = s;

        Real abserr = std::abs(x1 - x0);
        Real relerr = abserr / std::abs(x1 + eps);

        // Stopping criteria
        if (abserr < tol && relerr < tol)
          break;
        else if ( std::abs(fx0) < std::abs(fx1) )
          std::swap (x0, x1);
      } // while loop

      return {x1, iter};
    }

  } // namespace detail



  //
  // C++17 Interfaces

  template <class F, class Real>
  inline std::tuple<Real, std::size_t>
  brent(F const& f, Real x0, Real x1)
  {
    Real tol = 1e-10;
    std::size_t maxiter = 100;

    return nola::detail::brent_impl(f, x0, x1, tol, maxiter);
  }

  template <class F, class Real>
  inline std::tuple<Real, std::size_t>
  brent(F const& f, Real x0, Real x1, Real tol, std::size_t maxiter)
  {
    return nola::detail::brent_impl(f, x0, x1, tol, maxiter);
  }



} // namespace nola


#endif