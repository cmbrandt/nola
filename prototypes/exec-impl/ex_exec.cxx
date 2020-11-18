// Example script to test <exec.hxx>

#include <iostream>
#include <vector>
#include "exec.hxx"
#include "stat.hxx"


int main()
{
  using nola::exec::seq;
  using nola::exec::par;
  using nola::exec::par_unseq;
  using nola::exec::unseq;

  std::vector<double> v{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double m1 = nola::stat::arithmetic_mean(            v.size(), v.data() );
  double m2 = nola::stat::arithmetic_mean( seq,       v.size(), v.data() );
  double m3 = nola::stat::arithmetic_mean( par,       v.size(), v.data() );
  double m4 = nola::stat::arithmetic_mean( par_unseq, v.size(), v.data() );
  double m5 = nola::stat::arithmetic_mean( unseq,     v.size(), v.data() );

  std::cout << "\nmean1 = " << m1
            << "\nmean2 = " << m2
            << "\nmean3 = " << m3
            << "\nmean4 = " << m4 
            << "\nmean5 = " << m5 
            << std::endl;
}