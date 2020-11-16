 !> \brief \b NOLA_DNRM2
 !
 !  =========== DOCUMENTATION ===========
 !
 ! Online html documentation available at
 !            http://www.netlib.org/lapack/explore-html/
 !
 !  Definition:
 !  ===========
 !
 !       DOUBLE PRECISION FUNCTION NOLA_DNRM2(N,X,INCX)
 !
 !       .. Scalar Arguments ..
 !       INTEGER INCX,N
 !       ..
 !       .. Array Arguments ..
 !       DOUBLE PRECISION X(*)
 !       ..
 !
 !
 !> \par Purpose:
 !  =============
 !>
 !> \verbatim
 !>
 !> NOLA_DNRM2 returns the euclidean norm of a vector via the function
 !> name, so that
 !>
 !>    NOLA_DNRM2 := sqrt( x'*x )
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
 !> \param[in] X
 !> \verbatim
 !>          X is DOUBLE PRECISION array, dimension ( 1 + ( N - 1 )*abs( INCX ) )
 !> \endverbatim
 !>
 !> \param[in] INCX
 !> \verbatim
 !>          INCX is INTEGER
 !>         storage spacing between elements of DX
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
 !>  -- This version written on 25-October-1982.
 !>     Modified on 14-October-1993 to inline the call to DLASSQ.
 !>     Sven Hammarling, Nag Ltd.
 !> \endverbatim
 !>
 !  =====================================================================
       DOUBLE PRECISION FUNCTION NOLA_DNRM2(N,X,INCX)
 !
 !  -- Reference BLAS level1 routine (version 3.8.0) --
 !  -- Reference BLAS is a software package provided by Univ. of Tennessee,    --
 !  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
 !     November 2017
 !
 !     .. Scalar Arguments ..
       INTEGER incx,n
 !     ..
 !     .. Array Arguments ..
       DOUBLE PRECISION x(*)
 !     ..
 !
 !  =====================================================================
 !
 !     .. Parameters ..
       DOUBLE PRECISION one,zero
       parameter(one=1.0d+0,zero=0.0d+0)
 !     ..
 !     .. Local Scalars ..
       DOUBLE PRECISION absxi,norm,scale,ssq
       INTEGER ix
 !     ..
 !     .. Intrinsic Functions ..
       INTRINSIC abs,sqrt
 !     ..
       IF (n.LT.1 .OR. incx.LT.1) THEN
           norm = zero
       ELSE IF (n.EQ.1) THEN
           norm = abs(x(1))
       ELSE
           scale = zero
           ssq = one
 !        The following loop is equivalent to this call to the LAPACK
 !        auxiliary routine:
 !        CALL DLASSQ( N, X, INCX, SCALE, SSQ )
 !
           DO 10 ix = 1,1 + (n-1)*incx,incx
               IF (x(ix).NE.zero) THEN
                   absxi = abs(x(ix))
                   IF (scale.LT.absxi) THEN
                       ssq = one + ssq* (scale/absxi)**2
                       scale = absxi
                   ELSE
                       ssq = ssq + (absxi/scale)**2
                   END IF
               END IF
    10     CONTINUE
           norm = scale*sqrt(ssq)
       END IF
 !
       NOLA_DNRM2 = norm
       RETURN
 !
 !     End of NOLA_DNRM2.
 !
       END