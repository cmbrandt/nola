// mean_parallel_simd.hxx

#ifndef MEAN_PARALLEL_SIMD_HXX
#define MEAN_PARALLEL_SIMD_HXX


#include <cstdlib> // std::size_t


namespace nola {

  template <class Real>
  inline Real
  arithmetic_mean_parallel_simd(Real const x[ ], std::size_t n)
  {
    //
    // Compute and return the mean of the sequence

    Real sum{0.0};

#pragma omp parallel for simd \
  num_threads(8)              \
  reduction(+:sum)
    for (std::size_t i = 0; i < n; ++i)
      sum += x[i];

    return sum / n;
  }

} // namespace nola


#endif