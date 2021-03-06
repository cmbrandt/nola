 !> \brief \b NOLA_DAXPY
 !
 !  =========== DOCUMENTATION ===========
 !
 ! Online html documentation available at
 !            http://www.netlib.org/lapack/explore-html/
 !
 !  Definition:
 !  ===========
 !
 !       SUBROUTINE NOLA_DAXPY(N,DA,DX,INCX,DY,INCY)
 !
 !       .. Scalar Arguments ..
 !       DOUBLE PRECISION DA
 !       INTEGER INCX,INCY,N
 !       ..
 !       .. Array Arguments ..
 !       DOUBLE PRECISION DX(*),DY(*)
 !       ..
 !
 !
 !> \par Purpose:
 !  =============
 !>
 !> \verbatim
 !>
 !>    NOLA_DAXPY constant times a vector plus a vector.
 !>    uses unrolled loops for increments equal to one.
 !> \endverbatim
 !
 !  Arguments:
 !  ==========
 !
 !> \param[in] N
 !> \verbatim
 !>          N is INTEGER
 !>         number of elements in input vector(s)
 !> \endverbatim
 !>
 !> \param[in] DA
 !> \verbatim
 !>          DA is DOUBLE PRECISION
 !>           On entry, DA specifies the scalar alpha.
 !> \endverbatim
 !>
 !> \param[in] DX
 !> \verbatim
 !>          DX is DOUBLE PRECISION array, dimension ( 1 + ( N - 1 )*abs( INCX ) )
 !> \endverbatim
 !>
 !> \param[in] INCX
 !> \verbatim
 !>          INCX is INTEGER
 !>         storage spacing between elements of DX
 !> \endverbatim
 !>
 !> \param[in,out] DY
 !> \verbatim
 !>          DY is DOUBLE PRECISION array, dimension ( 1 + ( N - 1 )*abs( INCY ) )
 !> \endverbatim
 !>
 !> \param[in] INCY
 !> \verbatim
 !>          INCY is INTEGER
 !>         storage spacing between elements of DY
 !> \endverbatim
 !
 !  Authors:
 !  ========
 !
 !> \author Univ. of Tennessee
 !> \author Univ. of California Berkeley
 !> \author Univ. of Colorado Denver
 !> \author NAG Ltd.
 !
 !> \date November 2017
 !
 !> \ingroup double_blas_level1
 !
 !> \par Further Details:
 !  =====================
 !>
 !> \verbatim
 !>
 !>     jack dongarra, linpack, 3/11/78.
 !>     modified 12/3/93, array(1) declarations changed to array(*)
 !> \endverbatim
 !>
 !  =====================================================================
       SUBROUTINE NOLA_DAXPY(N,DA,DX,INCX,DY,INCY)
 !
 !  -- Reference BLAS level1 routine (version 3.8.0) --
 !  -- Reference BLAS is a software package provided by Univ. of Tennessee,    --
 !  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
 !     November 2017
 !
 !     .. Scalar Arguments ..
       DOUBLE PRECISION DA
       INTEGER INCX,INCY,N
 !     ..
 !     .. Array Arguments ..
       DOUBLE PRECISION DX(*),DY(*)
 !     ..
 !
 !  =====================================================================
 !
 !     .. Local Scalars ..
       INTEGER I,IX,IY,M,MP1
 !     ..
 !     .. Intrinsic Functions ..
       INTRINSIC mod
 !     ..
       IF (n.LE.0) RETURN
       IF (da.EQ.0.0d0) RETURN
       IF (incx.EQ.1 .AND. incy.EQ.1) THEN
 !
 !        code for both increments equal to 1
 !
 !
 !        clean-up loop
 !
          m = mod(n,4)
          IF (m.NE.0) THEN
             DO i = 1,m
                dy(i) = dy(i) + da*dx(i)
             END DO
          END IF
          IF (n.LT.4) RETURN
          mp1 = m + 1
          DO i = mp1,n,4
             dy(i) = dy(i) + da*dx(i)
             dy(i+1) = dy(i+1) + da*dx(i+1)
             dy(i+2) = dy(i+2) + da*dx(i+2)
             dy(i+3) = dy(i+3) + da*dx(i+3)
          END DO
       ELSE
 !
 !        code for unequal increments or equal increments
 !          not equal to 1
 !
          ix = 1
          iy = 1
          IF (incx.LT.0) ix = (-n+1)*incx + 1
          IF (incy.LT.0) iy = (-n+1)*incy + 1
          DO i = 1,n
           dy(iy) = dy(iy) + da*dx(ix)
           ix = ix + incx
           iy = iy + incy
          END DO
       END IF
       RETURN
       END