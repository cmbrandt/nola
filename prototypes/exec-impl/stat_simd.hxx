
#ifndef UNSEQ_HXX
#define UNSEQ_HXX


namespace stat
{


template <class Real>
inline Real
mean_unseq(int n, Real x[ ])
{
  std::cout << "\ninside mean_unseq(int n, Real x[])" << std::endl;

  double mean{0.0};

  for (int i = 0; i < n; ++i)
    mean += x[i];

  return mean / n;
}


} // namespace stat


#endif