# C++ compiler, compiler flags, and include statement
CXX        := g++-10
CXXINCLD   := -I $(HOME)/projects/nola/include
CXXLIB     := $(HOME)/projects/nola/lib/libnola.a

CXX17FLAGS := -Wall -Wpedantic -Wextra -std=c++17
CXX17OBJS  := cxx17_main.o cxx17_blas.o cxx17_root.o cxx17_stat.o cxx17_simd.o cxx17_exec.o

CXX23FLAGS := -Wall -Wpedantic -Wextra -std=c++20
CXX23OBJS  := cxx23_main.o cxx23_blas.o cxx23_root.o cxx23_stat.o cxx23_simd.o cxx23_exec.o
CXX23INCLD := -I $(HOME)/opt/mdspan/include

all: cxx17_test.exe cxx23_test.exe


cxx17_test.exe: $(CXX17OBJS) $(CXXLIB)
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) $(CXX17OBJS) $(CXXLIB) -lgfortran -o cxx17_test.exe

cxx23_test.exe: $(CXX23OBJS)
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) $(CXX23OBJS) $(CXXLIB) -lgfortran -o cxx23_test.exe


cxx17_main.o: cxx17_main.cxx
	$(CXX) $(CXXINCLD) $(CXX17FLAGS) -c cxx17_main.cxx

cxx17_blas.o: cxx17_blas.cxx
	$(CXX) $(CXXINCLD) $(CXX17FLAGS) -c cxx17_blas.cxx

cxx17_root.o: cxx17_root.cxx
	$(CXX) $(CXXINCLD) $(CXX17FLAGS) -c cxx17_root.cxx

cxx17_stat.o: cxx17_stat.cxx
	$(CXX) $(CXXINCLD) $(CXX17FLAGS) -c cxx17_stat.cxx

cxx17_simd.o: cxx17_simd.cxx
	$(CXX) $(CXXINCLD) $(CXX17FLAGS) -c cxx17_simd.cxx

cxx17_exec.o: cxx17_exec.cxx
	$(CXX) $(CXXINCLD) $(CXX17FLAGS) -c cxx17_exec.cxx


cxx23_main.o: cxx23_main.cxx
	$(CXX) $(CXXINCLD) $(CXX23INCLD) $(CXX23FLAGS) -c cxx23_main.cxx

cxx23_blas.o: cxx23_blas.cxx
	$(CXX) $(CXXINCLD) $(CXX23INCLD) $(CXX23FLAGS) -c cxx23_blas.cxx

cxx23_root.o: cxx23_root.cxx
	$(CXX) $(CXXINCLD) $(CXX23INCLD) $(CXX23FLAGS) -c cxx23_root.cxx

cxx23_stat.o: cxx23_stat.cxx
	$(CXX) $(CXXINCLD) $(CXX23INCLD) $(CXX23FLAGS) -c cxx23_stat.cxx

cxx23_simd.o: cxx23_simd.cxx
	$(CXX) $(CXXINCLD) $(CXX23INCLD) $(CXX23FLAGS) -c cxx23_simd.cxx

cxx23_exec.o: cxx23_exec.cxx
	$(CXX) $(CXXINCLD) $(CXX23INCLD) $(CXX23FLAGS) -c cxx23_exec.cxx


run: cxx17_test.exe cxx23_test.exe
	./cxx17_test.exe
	./cxx23_test.exe

clean:
	rm *.exe *.o
	clear
