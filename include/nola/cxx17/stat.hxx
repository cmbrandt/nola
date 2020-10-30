// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_STAT_HXX
#define NOLA_CXX17_STAT_HXX

#include <cmath>   // std::sqrt
#include <cstdlib> // std::size_t

#include <nola/impl/stat_impl_seq.hxx>
//#include <nola/impl/stat_impl_par.hxx>
//#include <nola/impl/stat_impl_unseq.hxx>
//#include <nola/impl/stat_impl_par_unseq.hxx>


namespace nola
{
namespace stat
{


//----------------------------------------------------------------------------//
// Declarations


template <class Real>
inline Real
arithmetic_mean(std::int32_t n, const Real x[ ]);

template <class ExecutionPolicy, class Real>
inline Real
arithmetic_mean(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ]);


template <class Real>
inline Real
variance(std::int32_t n, const Real x[ ]);

template <class ExecutionPolicy, class Real>
inline Real
variance(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ]);


template <class Real>
inline Real
standard_deviation(std::int32_t n, const Real x[ ]);

template <class ExecutionPolicy, class Real>
inline Real
standard_deviation(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ]);


template <class Real>
inline Real
covariance(std::int32_t n, const Real x[ ], const Real y[ ]);

template <class ExecutionPolicy, class Real>
inline Real
covariance(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ], const Real y[ ]);


template <class Real>
inline Real
correlation(std::int32_t n, const Real x[ ], const Real y[ ]);

template <class ExecutionPolicy, class Real>
inline Real
correlation(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ], const Real y[ ]);


//----------------------------------------------------------------------------//
// Definitions


//
// Arithmetic Mean

template <class Real>
inline Real
arithmetic_mean(Real const x[ ], std::size_t n)
{
  return detail::arithmetic_mean_impl(nola::exec::seq, x, n);
}

template <class ExecutionPolicy, class Real>
inline Real
arithmetic_mean(ExecutionPolicy&& exec, Real const x[ ], std::size_t n)
{
  return detail::arithmetic_mean_impl(exec, x, n);
}


//
// Variance

template <class Real>
inline Real
variance(Real const x[ ], std::size_t n)
{
  return detail::variance_impl(nola::exec::seq, x, n);
}

template <class ExecutionPolicy, class Real>
inline Real
variance(Real const x[ ], std::size_t n)
{
  return detail::variance_impl(exec, x, n);
}


//
// Standard Deviation

template <class Real>
inline Real
standard_deviation(Real const x[ ], std::size_t n)
{
  return detail::standard_deviation_impl(nola::exec::seq, x, n);
}

template <class ExecutionPolicy, class Real>
inline Real
standard_deviation(Real const x[ ], std::size_t n)
{
  return detail::standard_deviation_impl(exec, x, n);
}


//
// Covariance

template <class Real>
inline Real
covariance(Real const x[ ], Real const y[ ], std::size_t n)
{
  return detail::covariance_impl(nola::exec::seq, x, y, n);
}

template <class ExecutionPolicy, class Real>
inline Real
covariance(Real const x[ ], Real const y[ ], std::size_t n)
{
  return detail::covariance_impl(exec, x, y, n);
}


//
// Correlation

template <class Real>
inline Real
correlation(Real const x[ ], Real const y[ ], std::size_t n)
{
  return detail::correlation_impl(nola::exec::seq, x, y, n);
}

template <class ExecutionPolicy, class Real>
inline Real
correlation(Real const x[ ], Real const y[ ], std::size_t n)
{
  return detail::correlation_impl(exec, x, y, n);
}


} // namespace stat
} // namespace nola


#endif