// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_STAT_HXX
#define NOLA_CXX17_STAT_HXX

#include <nola/detail/stat_impl.hxx>


// If <nola/cxx17/exec.hxx> has already been included,
// pull in the parallel/simd backends
#if defined (NOLA_EXEC_HXX)
  #include "stat_exec_impl.hxx"
#endif


#endif