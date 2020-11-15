
#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX

#include <iostream>
#include "stat_serial.hxx"


namespace nola
{
namespace stat
{


// Declarations

template <class Real>
inline Real
mean(int n, Real x[]);


// Implementations

template <class Real>
inline Real
mean(int n, Real x[ ])
{
  return detail::mean_serial(n, x);
}


} // namespace stat
} // namespace nola


#endif