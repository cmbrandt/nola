// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <nola/root.hxx>


double f(double x)
{ return x - std::exp(-x); }

double fp(double x)
{ return 1.0 + std::exp(-x); }

int main()
{
  std::cout << "\nNewton's Method Nola Interface Example." << std::endl;

  // Callback routine and derivative of callback routine (lambda definitions)
//  auto f  = [](double x) { return x   - std::exp(-x); };
//  auto fp = [](double x) { return 1.0 + std::exp(-x); };

  // Initial point
  double x0 = 1000.0;

  // Stopping tolerance
  double tol = 1e-12;

  // Maximum interations
  std::size_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::newton(f, fp, x0);
  auto [r2, iter2] = nola::newton(f, fp, x0, tol, maxit);

  // Display result
  std::cout << std::setprecision(10)
            << "\nroot1 = " << r1                   // r1    = 0.5671432904
            << "\niter1 = " << iter1                // iter1 = 6
            << "\nroot2 = " << r2                   // r2    = 0.5671432904
            << "\niter2 = " << iter2 << std::endl;  // iter2 = 6
}