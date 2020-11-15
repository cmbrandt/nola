
#ifndef NOLA_STAT_SIMD_HXX
#define NOLA_STAT_SIMD_HXX

#include <iostream>


namespace nola
{
namespace stat
{


// Declarations

template <class Real>
inline Real
mean_simd(int n, Real x[]);


// Implementations

template <class Real>
inline Real
mean_simd(int n, Real x[ ])
{
  std::cout << "\ninside mean_simd()" << std::endl;

  double mean{0.0};

  for (int i = 0; i < n; ++i)
    mean += x[i];

  return mean / n;
}


} // namespace stat
} // namespace nola


#endif