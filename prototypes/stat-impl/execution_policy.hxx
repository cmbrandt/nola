// execution_policy.hxx

#ifndef EXECUTION_POLICY_HXX
#define EXECUTION_POLICY_HXX



namespace nola {

  //
  // Serial execution policy

  class serial {
    // anthing to define here??
  }



  //
  // OpenMP execution policy

  template <class Parallel, class Simd>
  class openmp {
  
  public:
    template<class Parallel, class Simd>
    openmp(int num_threads, int schedule, int chunk_size, int affinity)
      : 
  private:
    Simd;       // Vec, NoVec
    Parallel;   // Par, NoPar
      NumThreads; // integer values (hyperthreading?)
      Schedule;   // static, dynamic (chunk_size)
      Affinity;   // close, spread
  }



// - OR -

  template <class Policy>
  class openmp {

  };


  using OmpVec = nola::openmp<nola::simd>;

  using OmpPar = nola::openmp<nola::par<4>>;

  using OmpParVec nola::openmp<nola::par_simd<8>>;


  default = nola::openmp<nola::par<1>>; // which should be nearly identical to serial

  //
  // CUDA execution policy

  template <class ...>
  class cuda {
    // ...
  }


} // namespace nola


#endif