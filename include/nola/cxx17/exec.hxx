// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_EXEC_HXX
#define NOLA_CXX17_EXEC_HXX


namespace nola
{
namespace exec
{


struct sequential { };
constexpr sequential seq;

struct unsequential { };
constexpr unsequential unseq;

struct parallel { };
constexpr parallel par;

struct parallel_unsequential { };
constexpr parallel_unsequential par_unseq;


} // namespace exec
} // namespace nola


#endif