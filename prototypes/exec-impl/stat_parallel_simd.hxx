
#ifndef PAR_UNSEQ_HXX
#define PAR_UNSEQ_HXX


namespace stat
{


template <class Real>
inline Real
mean_par_unseq(int n, Real x[ ])
{
  std::cout << "\ninside mean_par_unseq(int n, Real x[])" << std::endl;

  double mean{0.0};

  for (int i = 0; i < n; ++i)
    mean += x[i];

  return mean / n;
}


} // namespace stat


#endif