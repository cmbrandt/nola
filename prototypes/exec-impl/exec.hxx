
#ifndef EXEC_HXX
#define EXEC_HXX

#include <type_traits>
#include "par.hxx"
#include "unseq.hxx"
#include "par_unseq.hxx"
#include "seq.hxx"


namespace exec
{


struct sequenced_policy { };

struct parallel_policy { };

struct parallel_unsequenced_policy { };

struct unsequenced_policy { };

inline constexpr auto seq       = sequenced_policy{};
inline constexpr auto par       = parallel_policy{};
inline constexpr auto par_unseq = parallel_unsequenced_policy{};
inline constexpr auto unseq     = unsequenced_policy{};


} // namespace exec


namespace stat
{

template <class ExecutionPolicy, class Real>
inline Real
mean(ExecutionPolicy&& exec, int n, Real x[ ])
{
  if constexpr ( std::is_same_v<ExecutionPolicy, exec::parallel_policy> )
    return mean_par(n, x);
  else if ( std::is_same_v<ExecutionPolicy, exec::parallel_unsequenced_policy> )
    return mean_par_unseq(n, x);
  else if ( std::is_same_v<ExecutionPolicy, exec::unsequenced_policy> )
    return mean_unseq(n, x);
  else
    return mean_seq(n, x);
}



} // stat


#endif