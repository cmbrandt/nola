
#ifndef NOLA_STAT_EXEC_IMPL_HXX
#define NOLA_STAT_EXEC_IMPL_HXX

#include <iostream>
#include "stat_serial.hxx"
#include "stat_parallel.hxx"
#include "stat_parallel_simd.hxx"
#include "stat_simd.hxx"


namespace nola
{
namespace stat
{


// Declaration

template <class ExecutionPolicy, class Real>
inline Real
mean(ExecutionPolicy&& exec, int n, Real x[]);


// Implementations

template <class ExecutionPolicy, class Real>
inline Real
mean(ExecutionPolicy&& /*exec*/, int n, Real x[ ])
{
  if constexpr (std::is_same_v<std::decay_t<ExecutionPolicy>, nola::exec::sequential_policy>)
    return detail::mean_serial(n, x);
  else
  if constexpr (std::is_same_v<std::decay_t<ExecutionPolicy>, nola::exec::parallel_policy>)
    return detail::mean_parallel(n, x);
  else
  if constexpr (std::is_same_v<std::decay_t<ExecutionPolicy>, nola::exec::parallel_unsequential_policy>)
    return detail::mean_parallel_simd(n, x);
  else
  if constexpr (std::is_same_v<std::decay_t<ExecutionPolicy>, nola::exec::unsequential_policy>)
    return detail::mean_simd(n, x);
  else
    static_assert(nola::exec::is_execution_policy_v<ExecutionPolicy>);

}


} // namespace stat
} // namespace nola


#endif