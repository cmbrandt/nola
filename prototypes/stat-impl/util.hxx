// util.hxx

#ifndef UTIL_HXX
#define UTIL_HXX


#include <cstdlib> // std::size_t


namespace nola {

  //
  // Execution policies

  namespace detail {

    template <std::size_t NumThreads>
    class parallel {
      // tag class of sorts ??
    };

  } // namespace detail

  class serial {
    //
    // just a simple tag class ??
  };


  template <class Parallel, class Simd>
  class openmp {
    // template parameter Parallel is either nola::par  or nola::no_par
    // template parameter Simd     is either nola::simd or nola::no_simd

    // How to you add the number of threads to this interface ??
  };


  template <std::size_t Blocks, std::size_t Cores, class Threads>
  clas cuda {
    //
    // similar design as nola::openmp
  };

} // namespace nola


#endif