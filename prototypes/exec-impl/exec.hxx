
#ifndef NOLA_EXEC_HXX
#define NOLA_EXEC_HXX

#include <type_traits>


namespace nola
{
namespace exec
{


//----------------------------------------------------------------------------//
// Execution policy classes

struct sequential_policy { };
struct parallel_policy { };
struct parallel_unsequential_policy  { };
struct unsequential_policy  { };


//----------------------------------------------------------------------------//
// Execution policy instances

constexpr auto seq       = sequential_policy {};
constexpr auto par       = parallel_policy {};
constexpr auto par_unseq = parallel_unsequential_policy {};
constexpr auto unseq     = unsequential_policy {};


//----------------------------------------------------------------------------//
// Execution policy type support


// Type category

template <typename T>
struct is_execution_policy : std::false_type { };

template <typename T>
inline constexpr bool is_execution_policy_v = is_execution_policy<T>::value;


// Type category specializations

template <>
struct is_execution_policy<sequential_policy> : std::true_type { };

template <>
struct is_execution_policy<parallel_policy> : std::true_type { };

template <>
struct is_execution_policy<parallel_unsequential_policy> : std::true_type { };

template <>
struct is_execution_policy<unsequential_policy> : std::true_type { };


/*

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

*/


} // namespace stat
} // namespace nola


#endif