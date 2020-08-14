// mean.hxx

#ifndef MEAN_HXX
#define MEAN_HXX


#include <cstdlib> // std::size_t


namespace nola {

  //
  // Declarations

  template <class Real>
  inline Real
  arithmetic_mean(Real const x[ ], std::size_t n);

  template <class ExecutionPolicy, class Real>
  inline Real
  arithmetic_mean(ExecutionPolicy&& exec, Real const x[ ], std::size_t n);



  //
  // Definitions

  template <class Real>
  inline Real
  arithmetic_mean(Real const x[ ], std::size_t n)
  {
    return nola::detail::arithmetic_mean_impl(x, n);
  }

  template <class ExecutionPolicy, class Real>
  inline Real
  arithmetic_mean(ExecutionPolicy&& exec, Real const x[ ], std::size_t n)
  {
    return nola::detail::arithmetic_mean_impl(exec, x, n);
  }

} // namespace nola


#endif