// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <nola/cxx17/root.hxx>


// Callback routine and derivative (free function definitions)
// double f(double x)
// { return x - std::exp(-x); }

// double fp(double x)
// { return 1.0 + std::exp(-x); }

int main()
{
  std::cout << "\nNewton's Method C++17 Interface Example." << std::endl;

  // Callback routine and derivative (lambda definitions)
  auto f  = [](double x) { return x   - std::exp(-x); };
  auto fp = [](double x) { return 1.0 + std::exp(-x); };

  // Initial point
  double x0 = 1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::int32_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::root::newton(f, fp, x0);
  auto [r2, iter2] = nola::root::newton(f, fp, x0, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nroot1 = " << r1                  // r1    = 0.56714329
            << "\niter1 = " << iter1               // iter1 = 6
            << "\nroot2 = " << r2                  // r2    = 0.56714329
            << "\niter2 = " << iter2 << std::endl; // iter2 = 6
}