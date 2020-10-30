// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

// g++-9 -std=c++17 -Wall -I ~/projects/nola/include/ cxx17_root_secant.cxx -o secant

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <nola/cxx17/root.hxx>


//double f(double x)
//{ return x - std::exp(-x); }

int main()
{
  std::cout << "\nSecant Method C++17 Interface Example." << std::endl;

  // Callback routine (lambda definition)
  auto f = [](double x) { return x - std::exp(-x); };

  // Initial points
  double x0 =  900.0;
  double x1 = 1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::int32_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::root::secant(f, x0, x1);  
  auto [r2, iter2] = nola::root::secant(f, x0, x1, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nroot1 = " << r1                   // r1    = 0.5671432904
            << "\niter1 = " << iter1                // iter1 = 8
            << "\nroot2 = " << r2                   // r2    = 0.5671432904
            << "\niter2 = " << iter2 << std::endl;  // iter2 = 8
}