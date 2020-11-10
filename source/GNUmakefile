# Fortran compiler and compiler flags
FXX      := gfortran-10
FXXFLAGS := -Wall -std=legacy -O3


# Location of build directory
#BUILD_DIR := /build/


# Location of installation directory
#INSTALL_DIR := /lib/


# Library files to build
#all: libnola.a
all: blas_obj libnola.a

libnola.a: $(blas_obj)
	ar rcs libnola.a *.o

# ar rcs libnola.a *.o




blas_obj: nola_saxpy.o nola_snrm2.o nola_sgemv.o nola_sgemm.o nola_strsv.o \
          nola_daxpy.o nola_dnrm2.o nola_dgemv.o nola_dgemm.o nola_dtrsv.o \
          nola_lsame.o nola_xerbla.o


# Compile library source files into object files

nola_saxpy.o: nola_saxpy.f90
	$(FXX) $(FXXFLAGS) -c nola_saxpy.f90

nola_snrm2.o: nola_snrm2.f90
	$(FXX) $(FXXFLAGS) -c nola_snrm2.f90

nola_sgemv.o: nola_sgemv.f90
	$(FXX) $(FXXFLAGS) -c nola_sgemv.f90

nola_sgemm.o: nola_sgemm.f90
	$(FXX) $(FXXFLAGS) -c nola_sgemm.f90

nola_strsv.o: nola_strsv.f90
	$(FXX) $(FXXFLAGS) -c nola_strsv.f90

nola_daxpy.o: nola_daxpy.f90
	$(FXX) $(FXXFLAGS) -c nola_daxpy.f90

nola_dnrm2.o: nola_dnrm2.f90
	$(FXX) $(FXXFLAGS) -c nola_dnrm2.f90

nola_dgemv.o: nola_dgemv.f90
	$(FXX) $(FXXFLAGS) -c nola_dgemv.f90

nola_dgemm.o: nola_dgemm.f90
	$(FXX) $(FXXFLAGS) -c nola_dgemm.f90

nola_dtrsv.o: nola_dtrsv.f90
	$(FXX) $(FXXFLAGS) -c nola_dtrsv.f90

nola_lsame.o: nola_lsame.f90
	$(FXX) $(FXXFLAGS) -c nola_lsame.f90

nola_xerbla.o: nola_xerbla.f90
	$(FXX) $(FXXFLAGS) -c nola_xerbla.f90


make install:
	mv libnola.a ../lib && rm *.o


# Clean build
make clean:
		rm *.o *.a && clear
