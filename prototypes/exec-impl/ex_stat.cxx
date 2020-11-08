// Example script to test <stat.hxx>

#include <iostream>
#include <vector>
#include "stat.hxx"


struct Fake_exec_policy { };

int main()
{
  Fake_exec_policy exec;

  std::vector<double> v{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double m1 = stat::mean(       v.size(), v.data() );
  double m2 = stat::mean( 5,    v.size(), v.data() );
  double m3 = stat::mean( exec, v.size(), v.data() );

  std::cout << "\nmean1 = " << m1
            << "\nmean2 = " << m2
            << "\nmean3 = " << m3 << std::endl;
}