// traits.hxx

#ifndef TRAITS_HXX
#define TRAITS_HXX

#include <type_traits>
#include "exec.hxx"


//----------------------------------------------------------------------------//
// <exec>

// Type trait

template <typename T>
struct is_execution_policy : std::false_type { };


// Specializations

template <>
struct is_execution_policy<sequential_policy> : std::true_type { };

template <>
struct is_execution_policy<parallel_policy> : std::true_type { };

template <>
struct is_execution_policy<parallel_unsequential_policy> : std::true_type { };

template <>
struct is_execution_policy<unsequential_policy> : std::true_type { };

// 

template <typename T>
inline constexpr bool is_execution_policy_v = is_execution_policy<T>::value;


#endif