
#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX

#include <iostream>
#include "stat_impl.hxx"

// If <nola/cxx17/exec.hxx> has already been included,
// pull in the parallel/simd backends
#if defined (NOLA_EXEC_HXX)
  #include "stat_exec_impl.hxx"
#endif


#endif