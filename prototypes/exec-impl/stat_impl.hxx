
#ifndef NOLA_STAT_IMPL_HXX
#define NOLA_STAT_IMPL_HXX

#include <iostream>
#include "stat_serial.hxx"


namespace nola
{
namespace stat
{


// Declarations

template <class Real>
inline Real
arithmetic_mean(int n, Real x[]);


// Implementations

template <class Real>
inline Real
arithmetic_mean(int n, Real x[ ])
{
  return detail::arithmetic_mean_serial_impl(n, x);
}


} // namespace stat
} // namespace nola


#endif