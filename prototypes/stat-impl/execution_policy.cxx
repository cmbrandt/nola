// execution_policy.cxx

#include "execution_policy.hxx"



//
// Example usage

// Serial execution
using Serial  = nola::serial;

// OpenMP parallel
using OmpPar  = nola::openmp<par, no_simd>;

// OpenMP vectorized
using OmpSimd = nola::openmp<no_par, simd>;

// OpenMP parallel vectorized
using OmpParSimd = nola::openmp<par, simd>;

// Cuda execution
using Cuda = nola::cuda<3, 3, 3>;



//
// Customized parallel execution

// 4 parallel threads
using OmpCustomPar = nola::openmp<Par, NoVec>(4);

// close thread affinity
using OmpCustomPar = nola::openmp<Par, NoVec>(close);

// 8 parallel threads with spread affinity
using OmpCustomPar = nola::openmp<Par, NoVec>(8, spread);


// Constructors for optional Parallel arguments:
// (1) num_threads
// (2) affinity
// (3) schedule, chunk_size
// (4) num_threads, affinity
// (5) num_threads, schedule, chunk_size
// (6) 