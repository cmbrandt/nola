// util.hxx

#ifndef UTIL_HXX
#define UTIL_HXX


#include <cstdlib> // std::size_t


namespace nola {

  //
  // Execution policies

  class serial {
    // class definition
  };


  template <class A, class B, class C>
  class openmp {
    // class definition
  };


  template <class A, class B, class C>
  clas cuda {
    // class definition
  };

} // namespace nola


#endif