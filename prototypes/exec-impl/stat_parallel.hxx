
#ifndef NOLA_STAT_PARALLEL_HXX
#define NOLA_STAT_PARALLEL_HXX

#include <iostream>


namespace nola
{
namespace stat
{
namespace detail
{


// Declarations

template <class Real>
inline Real
arithmetic_mean_parallel_impl(int n, Real x[]);


// Implementations

template <class Real>
inline Real
arithmetic_mean_parallel_impl(int n, Real x[ ])
{
  std::cout << "\ninside arithmetic_mean_parallel()" << std::endl;

  double mean{0.0};

  for (int i = 0; i < n; ++i)
    mean += x[i];

  return mean / n;
}


} // namespace detail
} // namespace stat
} // namespace nola


#endif