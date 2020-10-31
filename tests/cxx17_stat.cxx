// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cmath>
#include <iomanip>
#include <iostream>
#include <nola/cxx17/stat.hxx>
#include "cxx17_stat.hxx"


void cxx17_stat()
{
  std::int32_t fail{0};

  //fail = cxx17_arithmetic_mean_float(fail);
  //fail = cxx17_arithmetic_mean_double(fail);
  //fail = cxx17_variance_float(fail);
  //fail = cxx17_variance_double(fail);
  //fail = cxx17_standard_deviation_float(fail);
  //fail = cxx17_standard_deviation_double(fail);
  //fail = cxx17_covariance_float(fail);
  //fail = cxx17_covariance_double(fail);
  //fail = cxx17_correlation_float(fail);
  //fail = cxx17_correlation_double(fail);

  if (fail == 0)
    std::cout << "\ncxx17_stat() passed with zero errors." << std::endl;
  else
    std::cout << "\ncxx17_stat() had " << fail << " errors." << std::endl;
}


//
// Arithmetic Mean








//
// Variance









//
// Standard Deviation









//
// Covariance








//
// Correlation

