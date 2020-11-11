// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_STAT_HXX
#define NOLA_CXX17_STAT_HXX

#include <cmath>   // std::sqrt
#include <cstdint> // std::int32_t
#include <nola/detail/stat_impl.hxx>


namespace nola
{
namespace stat
{


//----------------------------------------------------------------------------//
// Declarations


template <class Real>
inline Real
arithmetic_mean(std::int32_t n, Real const x[ ]);
/*
template <class ExecutionPolicy, class Real>
inline Real
arithmetic_mean(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ]);
*/

template <class Real>
inline Real
variance(std::int32_t n, Real const x[ ]);
/*
template <class ExecutionPolicy, class Real>
inline Real
variance(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ]);
*/

template <class Real>
inline Real
standard_deviation(std::int32_t n, Real const x[ ]);
/*
template <class ExecutionPolicy, class Real>
inline Real
standard_deviation(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ]);
*/

template <class Real>
inline Real
covariance(std::int32_t n, Real const x[ ], Real const y[ ]);
/*
template <class ExecutionPolicy, class Real>
inline Real
covariance(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ], const Real y[ ]);
*/

template <class Real>
inline Real
correlation(std::int32_t n, Real const x[ ], Real const y[ ]);
/*
template <class ExecutionPolicy, class Real>
inline Real
correlation(ExecutionPolicy&& exec, std::int32_t n, const Real x[ ], const Real y[ ]);
*/


//----------------------------------------------------------------------------//
// Definitions


//
// Arithmetic Mean

template <class Real>
inline Real
arithmetic_mean(std::int32_t n, Real const x[ ])
{
  return detail::arithmetic_mean_impl(n, x);
}
/*
template <class ExecutionPolicy, class Real>
inline Real
arithmetic_mean(ExecutionPolicy&& exec, Real const x[ ], std::size_t n)
{
  return detail::arithmetic_mean_impl(exec, x, n);
}
*/

//
// Variance

template <class Real>
inline Real
variance(std::int32_t n, Real const x[ ])
{
  return detail::variance_impl(n, x);
}
/*
template <class ExecutionPolicy, class Real>
inline Real
variance(Real const x[ ], std::size_t n)
{
  return detail::variance_impl(exec, x, n);
}
*/

//
// Standard Deviation

template <class Real>
inline Real
standard_deviation(std::int32_t n, Real const x[ ])
{
  return detail::standard_deviation_impl(n, x);
}
/*
template <class ExecutionPolicy, class Real>
inline Real
standard_deviation(Real const x[ ], std::size_t n)
{
  return detail::standard_deviation_impl(exec, x, n);
}
*/

//
// Covariance

template <class Real>
inline Real
covariance(std::int32_t n, Real const x[ ], Real const y[ ])
{
  return detail::covariance_impl(n, x, y);
}
/*
template <class ExecutionPolicy, class Real>
inline Real
covariance(Real const x[ ], Real const y[ ], std::size_t n)
{
  return detail::covariance_impl(exec, x, y, n);
}
*/

//
// Correlation

template <class Real>
inline Real
correlation(std::int32_t n, Real const x[ ], Real const y[ ])
{
  return detail::correlation_impl(n, x, y);
}
/*
template <class ExecutionPolicy, class Real>
inline Real
correlation(Real const x[ ], Real const y[ ], std::size_t n)
{
  return detail::correlation_impl(exec, x, y, n);
}
*/

} // namespace stat
} // namespace nola


#endif