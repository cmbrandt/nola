// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <iomanip>
#include <iostream>
#include <nola/cxx17/root.hxx>
#include "cxx17_root.hxx"


void cxx17_root()
{
  std::int32_t fail{0};

  fail = cxx17_bisection_float(fail);
  fail = cxx17_bisection_double(fail);
  fail = cxx17_brent_float(fail);
  fail = cxx17_brent_double(fail);
  fail = cxx17_fixed_point_float(fail);
  fail = cxx17_fixed_point_double(fail);
  fail = cxx17_newton_float(fail);
  fail = cxx17_newton_double(fail);
  fail = cxx17_secant_float(fail);
  fail = cxx17_secant_double(fail);

  if (fail == 0)
    std::cout << "\ncxx17_root() passed with zero errors." << std::endl;
  else
    std::cout << "\ncxx17_root() had " << fail << " errors." << std::endl;
}


//
// Bisection Method

std::int32_t cxx17_bisection_float(std::int32_t fail)
{
  auto f = [](float x) { return x - std::exp(-x); };

  float a   = -1.0;
  float b   = 1000.0;
  float tol = 1e-06;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::bisection(f, a, b);
  auto [r2, iter2] = nola::root::bisection(f, a, b, tol, maxit);

  bool b1 = std::abs(r1 - 0.56714) > 0.00001;
  bool b2 = std::abs(r2 - 0.56714) > 0.00001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::root::bisection( float )"
              << "\nsoln  = " << 0.56714
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.56714 
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


std::int32_t cxx17_bisection_double(std::int32_t fail)
{
  auto f = [](float x) { return x - std::exp(-x); };

  double a   = -1.0;
  double b   = 1000.0;
  double tol = 1e-12;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::bisection(f, a, b);
  auto [r2, iter2] = nola::root::bisection(f, a, b, tol, maxit);

  bool b1 = std::abs(r1 - 0.567143291) > 0.000000001;
  bool b2 = std::abs(r2 - 0.567143291) > 0.000000001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(11)
              << "\nERROR! nola::root::bisection( double )"
              << "\nsoln  = " << 0.567143291
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.567143291
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


//
// Brent's Method

std::int32_t cxx17_brent_float(std::int32_t fail)
{
  auto f = [](float x) { return x - std::exp(-x); };

  float x0  = -1.0;
  float x1  = 1000.0;
  float tol = 1e-06;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::brent(f, x0, x1);
  auto [r2, iter2] = nola::root::brent(f, x0, x1, tol, maxit);

  bool b1 = std::abs(r1 - 0.56714) > 0.00001;
  bool b2 = std::abs(r2 - 0.56714) > 0.00001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::root::brent( float )"
              << "\nsoln  = " << 0.56714
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.56714 
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


std::int32_t cxx17_brent_double(std::int32_t fail)
{
  auto f = [](double x) { return x - std::exp(-x); };

  double x0  = -1.0;
  double x1  = 1000.0;
  double tol = 1e-12;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::brent(f, x0, x1);
  auto [r2, iter2] = nola::root::brent(f, x0, x1, tol, maxit);

  bool b1 = std::abs(r1 - 0.567143291) > 0.000000001;
  bool b2 = std::abs(r2 - 0.567143291) > 0.000000001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(11)
              << "\nERROR! nola::root::brent( double )"
              << "\nsoln  = " << 0.567143291
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.567143291
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


//
// Fixed-Point Method

std::int32_t cxx17_fixed_point_float(std::int32_t fail)
{
  auto g = [](double x) { return std::exp(-x); };

  float x0  = 1000.0;
  float tol = 1e-06;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::fixed_point(g, x0);
  auto [r2, iter2] = nola::root::fixed_point(g, x0, tol, maxit);

  bool b1 = std::abs(r1 - 0.56714) > 0.00001;
  bool b2 = std::abs(r2 - 0.56714) > 0.00001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::root::fixed_point( float )"
              << "\nsoln  = " << 0.56714
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.56714 
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


std::int32_t cxx17_fixed_point_double(std::int32_t fail)
{
  auto g = [](double x) { return std::exp(-x); };

  double x0  = 1000.0;
  double tol = 1e-12;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::fixed_point(g, x0);
  auto [r2, iter2] = nola::root::fixed_point(g, x0, tol, maxit);

  bool b1 = std::abs(r1 - 0.567143291) > 0.000000001;
  bool b2 = std::abs(r2 - 0.567143291) > 0.000000001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(11)
              << "\nERROR! nola::root::fixed_point( double )"
              << "\nsoln  = " << 0.567143291
              << "\nx1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.567143291
              << "\nx1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


//
// Newton's Method

std::int32_t cxx17_newton_float(std::int32_t fail)
{
  auto f  = [](float x) { return x   - std::exp(-x); };
  auto fp = [](float x) { return 1.0 + std::exp(-x); };

  float x0  = 1000.0;
  float tol = 1e-06;
  std::int32_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::root::newton(f, fp, x0);
  auto [r2, iter2] = nola::root::newton(f, fp, x0, tol, maxit);

  bool b1 = std::abs(r1 - 0.56714) > 0.00001;
  bool b2 = std::abs(r2 - 0.56714) > 0.00001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::root::newton( float )"
              << "\nsoln  = " << 0.56714
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.56714 
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


std::int32_t cxx17_newton_double(std::int32_t fail)
{
  auto f  = [](double x) { return x   - std::exp(-x); };
  auto fp = [](double x) { return 1.0 + std::exp(-x); };

  double x0  = 1000.0;
  double tol = 1e-12;
  std::int32_t maxit = 100;

  // Compute root of f
  auto [r1, iter1] = nola::root::newton(f, fp, x0);
  auto [r2, iter2] = nola::root::newton(f, fp, x0, tol, maxit);

  bool b1 = std::abs(r1 - 0.567143291) > 0.000000001;
  bool b2 = std::abs(r2 - 0.567143291) > 0.000000001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(11)
              << "\nERROR! nola::root::newton( double )"
              << "\nsoln  = " << 0.567143291
              << "\nx1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.567143291
              << "\nx1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


//
// Secant Method

std::int32_t cxx17_secant_float(std::int32_t fail)
{
  auto f = [](float x) { return x - std::exp(-x); };

  float x0  =  900.0;
  float x1  = 1000.0;
  float tol = 1e-12;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::secant(f, x0, x1);  
  auto [r2, iter2] = nola::root::secant(f, x0, x1, tol, maxit);

  bool b1 = std::abs(r1 - 0.56714) > 0.00001;
  bool b2 = std::abs(r2 - 0.56714) > 0.00001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(7)
              << "\nERROR! nola::root::secant( float )"
              << "\nsoln  = " << 0.56714
              << "\nr1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.56714 
              << "\nr1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}


std::int32_t cxx17_secant_double(std::int32_t fail)
{
  auto f = [](double x) { return x - std::exp(-x); };

  double x0  =  900.0;
  double x1  = 1000.0;
  double tol = 1e-12;
  std::int32_t maxit = 100;

  auto [r1, iter1] = nola::root::secant(f, x0, x1);  
  auto [r2, iter2] = nola::root::secant(f, x0, x1, tol, maxit);

  bool b1 = std::abs(r1 - 0.567143291) > 0.000000001;
  bool b2 = std::abs(r2 - 0.567143291) > 0.000000001;

  if (b1 or b2) {
    ++fail;
    std::cout << std::setprecision(11)
              << "\nERROR! nola::root::secant( double )"
              << "\nsoln  = " << 0.567143291
              << "\nx1    = " << r1
              << "\niter1 = " << iter1
              << "\nsoln  = " << 0.567143291
              << "\nx1    = " << r2
              << "\niter2 = " << iter2 << std::endl;
  }

  return fail;
}