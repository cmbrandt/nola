// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <nola/root.hxx>


double f(double x)
{ return x - std::exp(-x); };

int main()
{
  std::cout << "\nBisection Method C++17 Interface Example." << std::endl;

  // Callback routine (lambda definition)
//  auto f = [](double x) { return x - std::exp(-x); };

  
  // End points of interval
  double a = -1.0;
  double b =  1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::size_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::bisection(f, a, b);
  auto [r2, iter2] = nola::bisection(f, a, b, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nroot1 = " << r1                   // r1    = 0.5671432904
            << "\niter1 = " << iter1                // iter1 = 44
            << "\nroot2 = " << r2                   // r2    = 0.5671432904
            << "\niter2 = " << iter2 << std::endl;  // iter2 = 50
}