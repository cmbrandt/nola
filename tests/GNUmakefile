# C++ compiler, compiler flags, and include statement
CXX17      := g++-10
CXX17FLAGS := -Wall -pedantic -std=c++17
CXX17INCLD := -I $(HOME)/projects/stl-algorithms/include
CXX17OBJS  := cxx17_main.o cxx17_blas.o cxx17_root.o cxx17_stat.o cxx17_simd.o cxx17_util.o

all: cxx17_test.exe

cxx17_test.exe: $(CXX17OBJS)
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -o cxx17_test.exe $(CXX17OBJS)

cxx17_main.o: cxx17_main.cxx
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -c cxx17_main.cxx

cxx17_blas.o: cxx17_blas.cxx
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -c cxx17_blas.cxx

cxx17_root.o: cxx17_root.cxx
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -c cxx17_root.cxx

cxx17_stat.o: cxx17_stat.cxx
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -c cxx17_stat.cxx

cxx17_simd.o: cxx17_simd.cxx
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -c cxx17_simd.cxx

cxx17_util.o: cxx17_util.cxx
	$(CXX17) $(CXX17FLAGS) $(CXX17INCLD) -c cxx17_util.cxx

run: cxx17_test.exe
	./cxx17_test.exe

clean:
	rm *.exe *.o
	clear