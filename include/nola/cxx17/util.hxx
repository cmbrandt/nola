// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CXX17_UTIL_HXX
#define NOLA_CXX17_UTIL_HXX

#include <algorithm>   // std::max
#include <cmath>       // std::abs
#include <cstdint>     // std::int32_t
#include <iomanip>     // std::setw
#include <iostream>    // std::cout, std::endl
#include <string_view> // std::string_view


namespace nola
{
namespace util
{


//------------------------------------------------------------------------------
// Declarations

template <class Real>
inline Real
compare_containers(std::int32_t size, const Real a[ ], const Real b[ ]);


template <class Real>
inline void
print_vector(std::string_view s, std::int32_t size, const Real a[ ]);

template <class Real>
inline void
print_vector(std::string_view s, std::int32_t size, const Real a[ ], std::int32_t precision, std::int32_t width);


template <class Real>
inline void
print_matrix(std::string_view s, std::int32_t cols, std::int32_t rows, const Real a[ ]);

template <class Real>
inline void
print_matrix(std::string_view s, std::int32_t cols, std::int32_t rows, const Real a[ ], std::int32_t precision, std::int32_t width);


//------------------------------------------------------------------------------
// Defintions


//
// compare_container

// Return the maximum difference between two ordered sequences of values
template <class Real>
Real compare_containers(std::int32_t size, const Real a[ ], const Real b[ ])
{
  Real diff{0.0};

  for (std::int32_t i = 0; i < size; ++i) {
    Real temp = std::abs(a[i] - b[i]);
    diff = std::max(temp, diff);
  }

  return diff;
}


//
// print_vector

// Display all elements of a one-dimensional container
template <class Real>
void print_vector(std::string_view s, std::int32_t size, const Real a[ ], std::int32_t precision, std::int32_t width)
{
  std::cout << s << " = [" << std::endl;

  for (std::int32_t i = 0; i < size; ++i)
    std::cout << " " << std::setprecision(precision)
                     << std::setw(width) << a[i];

  std::cout << "\n]" << std::endl;
}

template <class Real>
void print_vector(std::string_view s, std::int32_t size, const Real a[ ])
{
  return print_vector(s, size, a, 6, 8);
}


//
// print_matrix

// Display all elements of a two-dimensional container
template <class Real>
void print_matrix(std::string_view s, std::int32_t cols, std::int32_t rows, const Real a[ ], std::int32_t precision , std::int32_t width )
{
  std::cout << s << " = [" << std::endl;

  for (std::int32_t i = 0; i < cols; ++i) {
    for (std::int32_t j = 0; j < rows; ++j) {
      std::cout << " " << std::setprecision(precision)
                       << std::setw(width) << a[j*cols+i];
    }

    std::cout << std::endl;
  }

  std::cout << "]" << std::endl;
}

template <class Real>
void print_matrix(std::string_view s, std::int32_t cols, std::int32_t rows, const Real a[ ] )
{
  return print_matrix(s, cols, rows, a, 6, 8);
}


} // namespace util
} // namespace nola


#endif
