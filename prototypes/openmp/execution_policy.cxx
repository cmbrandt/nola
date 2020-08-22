// execution_policy.cxx

#include "execution_policy.hxx"



// Possible OMP Interface Design (Including Type Aliases)


// Possible Base Class Specification
template <std::size_t NumThreads, Simd S> // S needs to be locked down.. NOT a customization point for users !!!
struct openmp<NumThreads, S> {

  // Constructor
  template <std::size_t NumThreads, Simd S>
  constexpr openmp() = default;

  // Accessor
  constexpr std::size_t num_threads() { return NumThreads; };
};


// Serial execution
using nola::serial = nola::openmp<1, nola::no_simd>;

// OpenMP parallel
template <std::size_t NumThreads>
using nola::omp_par = nola::openmp<NumThreads, nola::no_simd>;

// OpenMP vectorized
using nola::omp_vec = nola::openmp<1, nola::simd>;

// OpenMP parallel vectorized
template <std::size_t NumThreads>
using nola::omp_parvec = nola::openmp<NumThreads, nola::simd>;


// Possible OMP Usage

// Serial execution
using Serial = nola::serial;

// OpenMP parallel with 4 threads
using OmpPar = nola::omp_par<4>;

// OpenMP vectorized
using OmpVec = nola::omp_vec;

// OpenMP parallel vectorized with 4 threads
using OmpParVec = nola::omp_parvec<4>;



// Possible CUDA Inteface Design


// Possible Base Class Specification
template <std::size_t NumBlocks, std::size_t NumThreads, std::size_t NumIdk>
struct cuda<NumBlocks, NumThreads, NumIdk> {

  // Constructor
  template <std::size_t NumBlocks, std::size_t NumThreads, std::size_t NumIdk>
  constexpr cuda() = default;
  
  // Accessors
  constexpr std::size_t num_blocks()  { return NumBlocks;  };
  constexpr std::size_t num_threads() { return NumThreads; };
  constexpr std::size_t num_idk()     { return NumIdk;     };
};


// Possible CUDA Usage with 10 blocks, 20 threads per block, and 20 ???
using Cuda = nola::cuda<10, 20, 20>;


// Constructors for optional Parallel arguments:
// (1) num_threads
// (2) affinity
// (3) schedule, chunk_size
// (4) num_threads, affinity
// (5) num_threads, schedule, chunk_size
// (6) 



