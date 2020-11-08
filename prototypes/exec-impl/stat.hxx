
#ifndef STAT_HXX
#define STAT_HXX


namespace stat
{


//
// Declarations

template <class Real>
inline Real
mean(int n, Real x[]);

template <class ExecutionPolicy, class Real>
inline Real
mean(ExecutionPolicy&& exec, int n, Real x[]);


//
// Implementations

template <class Real>
inline Real
mean(int n, Real x[ ])
{
  std::cout << "\ninside mean(int n, Real x[])" << std::endl;

  double mean{0.0};

  for (int i = 0; i < n; ++i)
    mean += x[i];

  return mean / n;
}

/*
template <class ExecutionPolicy, class Real>
inline Real
mean(ExecutionPolicy&&, int n, Real x[ ])
{
  std::cout << "\ninside mean(DummpyExec, int n, Real x[])" << std::endl;

  return mean(n, x);
}
*/

} // namespace stat


#endif