// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <nola/cxx17/root.hxx>


// Callback routine (free function definition)
// double g(double x)
// { return std::exp(-x); }

int main()
{
  std::cout << "\nFixed-Point Method C++17 Interface Example." << std::endl;

  // Callback routine (lambda definition)
  auto g = [](double x) { return std::exp(-x); };

  // Initial point
  double x0 = 1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::int32_t maxit = 100;

  // Compute fixed-point x = g(x)
  auto [x1, iter1] = nola::root::fixed_point(g, x0);
  auto [x2, iter2] = nola::root::fixed_point(g, x0, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nroot1 = " << x1                  // x    = 0.56714329
            << "\niter1 = " << iter1               // iter = 44
            << "\nroot2 = " << x2                  // x    = 0.56714329
            << "\niter2 = " << iter2 << std::endl; // iter = 52
}