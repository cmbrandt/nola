# C++ compiler, compiler flags, and include statement
CXX        := g++-10
CXXINCLD   := -I $(HOME)/projects/nola/include

CXX17FLAGS := -Wall -pedantic -Wextra -std=c++17
CXX17OBJS  := cxx17_main.o cxx17_blas.o cxx17_root.o cxx17_stat.o cxx17_simd.o cxx17_exec.o cxx17_util.o

CXX23FLAGS := -Wall -pedantic -Wextra -std=c++20
CXX23OBJS  := cxx23_main.o cxx23_blas.o cxx23_root.o cxx23_stat.o cxx23_simd.o cxx23_exec.o cxx23_util.o
CXX23INCLD := -I $(HOME)/opt/mdspan/include

all: cxx17_test.exe cxx23_test.exe


cxx17_test.exe: $(CXX17OBJS)
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) $(CXX17OBJS) -o cxx17_test.exe

cxx23_test.exe: $(CXX23OBJS)
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) $(CXX23OBJS) -o cxx23_test.exe


cxx17_main.o: cxx17_main.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_main.cxx

cxx17_blas.o: cxx17_blas.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_blas.cxx

cxx17_root.o: cxx17_root.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_root.cxx

cxx17_stat.o: cxx17_stat.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_stat.cxx

cxx17_simd.o: cxx17_simd.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_simd.cxx

cxx17_exec.o: cxx17_exec.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_exec.cxx

cxx17_util.o: cxx17_util.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) -c cxx17_util.cxx


cxx23_main.o: cxx23_main.cxx
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_main.cxx

cxx23_blas.o: cxx23_blas.cxx
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_blas.cxx

cxx23_root.o: cxx23_root.cxx
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_root.cxx

cxx23_stat.o: cxx23_stat.cxx
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_stat.cxx

cxx23_simd.o: cxx23_simd.cxx
	$(CXX) $(CXX23FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_simd.cxx

cxx23_exec.o: cxx23_exec.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_exec.cxx

cxx23_util.o: cxx23_util.cxx
	$(CXX) $(CXX17FLAGS) $(CXXINCLD) $(CXX23INCLD) -c cxx23_util.cxx


run: cxx17_test.exe cxx23_test.exe
	./cxx17_test.exe
	./cxx23_test.exe

clean:
	rm *.exe *.o
	clear
