
#ifndef PAR_HXX
#define PAR_HXX



namespace stat
{

/*
template <class ExecutionPolicy, class Real>
inline Real
mean(ExecutionPolicy&& exec, int n, Real x[ ]);
*/


template <class Real>
inline Real
mean_par(int n, Real x[ ])
{
  std::cout << "\ninside mean_par(int n, Real x[])" << std::endl;

  double mean{0.0};

  for (int i = 0; i < n; ++i)
    mean += x[i];

  return mean / n;
}


} // namespace stat


#endif