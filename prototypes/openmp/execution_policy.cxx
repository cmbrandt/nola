// execution_policy.cxx

#include "execution_policy.hxx"


//
// Possible OMP Interface Design (Including Type Aliases)


// Simd tag classes

struct simd_t { };
inline constexpr simd_t simd = { };

struct no_simd_t { };
inline constexpr no_simd_t no_simd = { };


// Possible Base Class Specifications

template <std::size_t NumThreads, class nola::simd_t> // nola::simd_t is a tag class
struct openmp {

  // Constructor
  constexpr openmp() noexcept = default;

  // Accessor
  constexpr std::size_t num_threads() const noexcept { return NumThreads; };
};

template <std::size_t NumThreads, class nola::no_simd_t> // nola::no_simd_t is a tag class
struct openmp {

  // Constructor
  constexpr openmp() noexcept = default;

  // Accessor
  constexpr std::size_t num_threads() const noexcept { return NumThreads; };
};


//
// OpenMP type aliases

// Serial execution
using nola::serial = nola::openmp<1, nola::no_simd_T>;

// OpenMP parallel
template <std::size_t NumThreads>
using nola::omp_par = nola::openmp<NumThreads, nola::no_simd_t>;

// OpenMP vectorized
using nola::omp_vec = nola::openmp<1, nola::simd_t>;

// OpenMP parallel vectorized
template <std::size_t NumThreads>
using nola::omp_parvec = nola::openmp<NumThreads, nola::simd_t>;


//
// Possible OMP Usage

// Serial execution
using Serial = nola::serial;
//nola::serial Serial;

// OpenMP parallel with 4 threads
using OmpPar = nola::omp_par<4>;
//nola::omp_par<4> OmpPar;

// OpenMP vectorized
using OmpVec = nola::omp_vec;
//nola::omp_vec OmpVec;

// OpenMP parallel vectorized with 4 threads
using OmpParVec = nola::omp_parvec<4>;
//nola::omp_parvec<4> OmpParVec;


//
// Possible CUDA Inteface Design


// Possible Base Class Specification

template <std::size_t NumBlocks, std::size_t NumThreads, std::size_t NumIdk>
struct cuda {

  // Constructor
  constexpr cuda() noexcept = default;
  
  // Accessors
  constexpr std::size_t num_blocks()  const noexcept { return NumBlocks;  };
  constexpr std::size_t num_threads() const noexcept { return NumThreads; };
  constexpr std::size_t num_idk()     const noexcept { return NumIdk;     };
};


//
// Possible CUDA Usage

// 10 blocks, 20 threads per block, and 20 ???
using Cuda = nola::cuda<10, 20, 20>;
//nola::cuda<10, 20, 20> Cuda;


// Constructors for optional Parallel arguments:
// (1) num_threads
// (2) affinity
// (3) schedule, chunk_size
// (4) num_threads, affinity
// (5) num_threads, schedule, chunk_size
// (6) 



