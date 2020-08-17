// ex_brent.cxx

// g++-9 -Wall -std=c++17 -O3 ex_brent.cxx -o brent

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "brent.hxx"


// Function definition
double f1(double x)
{ return x - std::exp(-x); };

// Function objects

struct F_no_state {
  double operator()(double x) { return x - std::exp(-x); };
};


struct F_state {
  double operator()(double x) { return x - std::exp(-x); };
  double value = 5.0;
};



int main()
{
  std::cout << "\nBrent's Method C++17 Interface Example." << std::endl;

  //
  // Define callable objects

  // Lambda expressino without state
  auto f2 = [](double x) { return x - std::exp(-x); };

  // Lambda expression with state
  auto f3 = [](double x) { double y = x; return y - std::exp(-y); };

  // Function object without state
  F_no_state f4;

  // Function object with state
  F_state    f5;

  // Initial points
  double x0 = -1.0;
  double x1 =  1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::size_t maxit = 100;

  //
  // Compute roots of f

  // Function
  auto [r1, iter1] = nola::brent(f1, x0, x1);
  auto [r2, iter2] = nola::brent(f1, x0, x1, tol, maxit);

  // Function object without state
  auto [r3, iter3] = nola::brent(f2, x0, x1);
  auto [r4, iter4] = nola::brent(f2, x0, x1, tol, maxit);

  // Function object with state
  auto [r5, iter5] = nola::brent(f3, x0, x1);
  auto [r6, iter6] = nola::brent(f3, x0, x1, tol, maxit);

  // Lambda expression
  auto [r7, iter7] = nola::brent(f4, x0, x1);
  auto [r8, iter8] = nola::brent(f4, x0, x1, tol, maxit);

  // Lambda expression
  auto [r9,  iter9]  = nola::brent(f5, x0, x1);
  auto [r10, iter10] = nola::brent(f5, x0, x1, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nfunction:"
            << "\nr1     = " << r1
            << "\niter1  = " << iter1
            << "\nr2     = " << r2
            << "\niter2  = " << iter2
            << "\n\nlambda without state:"
            << "\nr3     = " << r3
            << "\niter3  = " << iter3
            << "\nr4     = " << r4
            << "\niter4  = " << iter4
            << "\n\nlambda with state:"
            << "\nr5     = " << r5
            << "\niter5  = " << iter5
            << "\nr6     = " << r6
            << "\niter6  = " << iter6
            << "\n\nfunction object without state:"
            << "\nr7     = " << r7
            << "\niter7  = " << iter7
            << "\nr8     = " << r8
            << "\niter8  = " << iter8
            << "\n\nfunction object with state:"
            << "\nr9     = " << r9
            << "\niter9  = " << iter9
            << "\nr10    = " << r10
            << "\niter10 = " << iter10
            << std::endl << std::endl;
}