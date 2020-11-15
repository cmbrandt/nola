// exec.hxx

#ifndef EXEC_HXX
#define EXEC_HXX


struct sequential_policy { };
constexpr auto seq = sequential_policy {};

struct parallel_policy { };
constexpr auto par = parallel_policy {};

struct parallel_unsequential_policy  { };
constexpr auto par_unseq = parallel_unsequential_policy {};

struct unsequential_policy  { };
constexpr auto unseq = unsequential_policy {};


#endif