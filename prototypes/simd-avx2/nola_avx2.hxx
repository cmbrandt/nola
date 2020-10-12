// nola_avx2.hxx

#ifndef NOLA_AVX2_HXX
#define NOLA_AVX2_HXX


#include <immintrin.h>


namespace nola {


//
// Type aliases
using v256f = __m256;
using v256d = __m256d;


//
// Function declarations

// Single precision
inline v256f avx2_set_scalar(float a);
//inline v256f avx2_set_zero();
//inline v256f avx2_broadcast(float const* addr);
//inline v256f avx2_load(float const* addr);
void         avx2_store(float* addr, v256f a);
/*
inline v256f avx2_add(v256f a, v256f b);
inline v256f avx2_sub(v256f a, v256f b);
inline v256f avx2_mul(v256f a, v256f b);
inline v256f avx2_div(v256f a, v256f b);
inline v256f avx2_fma(v256f a, v256f b, v256f c);

*/

/*
// Double precision
inline v256d avx2_set_scalar(double a);
inline v256d avx2_set_zero();
inline v256d avx2_broadcast(double const* addr);
inline v256d avx2_load(double const* addr);
inline v256d avx2_store(double* addr, v256d a);
inline v256d avx2_add(v256d a, v256d b);
inline v256d avx2_sub(v256d a, v256d b);
inline v256d avx2_mul(v256d a, v256d b);
inline v256d avx2_div(v256d a, v256d b);
inline v256d avx2_fma(v256d a, v256d b, v256d c);
*/

//
// Function implementations

// Single precision
inline v256f
avx2_set_scalar(float a) { return _mm256_set1_ps(a); }
/*
inline v256f
avx2_set_zero() { return _mm256_setzero_ps(); }

inline v256f
avx2_broadcast(float const& addr) { return _mm256_broadcast_ss(addr); }

inline v256f
avx2_load(float const& addr)  return _mm256_load_ps(addr); }
*/
inline void
avx2_store(float* addr, v256f a) { _mm256_store_ps(addr, a); }
/*
inline v256f
avx2_add(v256f a, v256f b) { return _mm256_add_ps(a, b); }

inline v256f 
avx2_sub(v256f a, v256f b) { return _mm256_sub_ps(a, b); }

inline v256f
avx2_mul(v256f a, v256f b) { return _mm256_mul(a, b); }

inline v256f
avx2_div(v256f a, v256f b) { return _mm256_div(a, b); }

inline v256f
avx2_fma(v256f a, v256f b, v256f c) { return _mm256_fmadd_ps(a, b, c); }
*/

// Double precision




} // namespace nola


#endif
