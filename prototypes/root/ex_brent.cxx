// ex_brent.cxx

// g++-9 -Wall -std=c++17 -O3 ex_brent.cxx -o brent

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "brent.hxx"


double f1(double x)
{ return x - std::exp(-x); };


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

  // Callback routine (lambda definition)
  auto f2 = [](double x) { return x - std::exp(-x); };

  // Function object without state
  F_no_state f3;

  // Function object with state
  F_state    f4;

  // Initial points
  double x0 = -1.0;
  double x1 =  1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::size_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::brent(f4, x0, x1);
  auto [r2, iter2] = nola::brent(f4, x0, x1, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nroot1 = " << r1                   // r1    = 0.5671432904
            << "\niter1 = " << iter1                // iter1 = 15
            << "\nroot2 = " << r2                   // r2    = 0.5671432904
            << "\niter2 = " << iter2 << std::endl;  // iter2 = 15
}