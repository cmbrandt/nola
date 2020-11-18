// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_STAT_HXX
#define NOLA_CXX17_STAT_HXX


// If <nola/cxx17/exec.hxx> has already been included,
// pull in the parallel/simd backend declarations
#if defined (NOLA_CXX17_EXEC_HXX)
  #include <nola/detail/stat_exec_impl.hxx>
// Otherwise, only pull in serial backend
#else
  #include <nola/detail/stat_impl.hxx>
#endif


#endif