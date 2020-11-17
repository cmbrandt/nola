// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_DETAIL_BLAS_HXX
#define NOLA_DETAIL_BLAS_HXX

#include <cstdint> // std::int32_t


namespace nola
{
namespace blas
{
namespace detail
{


//----------------------------------------------------------------------------//
// Declarations (for Reference BLAS)


//
// xAXPY (e.g. Linear Algebra Add)

extern "C" void
nola_saxpy_(const std::int32_t* n,
            const float* alpha,
            const float x[ ], const std::int32_t* incx,
            float y[ ], const std::int32_t* incy);

extern "C" void
nola_daxpy_(const std::int32_t* n,
            const double* alpha,
            const double x[ ], const std::int32_t* incx,
            double y[ ], const std::int32_t* incy);


//
// xNRM2 (e.g. Vector Euclidean Norm)

extern "C" float
nola_snrm2_(const std::int32_t* n,
            const float x[ ], const std::int32_t* incx);

extern "C" double
nola_dnrm2_(const std::int32_t* n,
            const double x[ ], const std::int32_t* incx);


//
// xGEMV (e.g. General Matrix Vector Produt)

extern "C" void
nola_sgemv_(const char* trans,
            const std::int32_t* m, const std::int32_t* n,
            const float* alpha,
            const float a[ ], const std::int32_t* lda,
            const float x[ ], const std::int32_t* incx,
            const float* beta,
            float y[ ], const std::int32_t* incy,
            std::int32_t length_trans);

extern "C" void
nola_dgemv_(const char* trans,
            const std::int32_t* m, const std::int32_t* n,
            const double* alpha,
            const double a[ ], const std::int32_t* lda,
            const double x[ ], const std::int32_t* incx,
            const double* beta,
            double y[ ], const std::int32_t* incy,
            std::int32_t length_trans);


//
// xTRSV (e.g. Triangular Matrix Vector Solve)

extern "C" void
nola_strsv_(const char* uplo,
            const char* trans,
            const char* diag,
            const std::int32_t* n,
            const float a[ ], const std::int32_t* lda,
            float x[ ], const std::int32_t* incx,
            std::int32_t length_uplo,
            std::int32_t length_trans,
            std::int32_t length_diag);

extern "C" void
nola_dtrsv_(const char* uplo,
            const char* trans,
            const char* diag,
            const std::int32_t* n,
            const double a[ ], const std::int32_t* lda,
            double x[ ], const std::int32_t* incx,
            std::int32_t length_uplo,
            std::int32_t length_trans,
            std::int32_t length_diag);


//
// xGEMM (e.g. General Matrix Product)

extern "C" void
nola_sgemm_(const char* transa, const char* transb,
            const std::int32_t* m, const std::int32_t* n, const std::int32_t* k,
            const float* alpha,
            const float a[ ], const std::int32_t* lda,
            const float b[ ], const std::int32_t* ldb,
            const float* beta,
            float c[ ], const std::int32_t* ldc,
            std::int32_t length_transa, std::int32_t length_transb);

extern "C" void
nola_dgemm_(const char* transa, const char* transb,
            const std::int32_t* m, const std::int32_t* n, const std::int32_t* k,
            const double* alpha,
            const double a[ ], const std::int32_t* lda,
            const double b[ ], const std::int32_t* ldb, const double* beta,
            double c[ ], const std::int32_t* ldc,
            std::int32_t length_transa, std::int32_t length_transb);


} // namespace detail
} // namespace blas
} // namespace nola


#endif