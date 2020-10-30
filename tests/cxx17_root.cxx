// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include "cxx17_root.hxx"


void cxx17_root()
{
  std::int32_t fail{0};

  fail = cxx17_bisection_float(fail);
  fail = cxx17_brent_float(fail);
  fail = cxx17_fixed_point_float(fail);
  fail = cxx17_newton_float(fail);
  fail = cxx17_secant_float(fail);

  fail = cxx17_bisection_double(fail);
  fail = cxx17_brent_double(fail);
  fail = cxx17_fixed_point_double(fail);
  fail = cxx17_newton_double(fail);
  fail = cxx17_secant_double(fail);

  if (fail == 0)
    std::cout << "\ncxx17_root() passed with zero errors." << std::endl;
  else
    std::cout << "\ncxx17_root() had " << fail << " errors." << std::endl;
}