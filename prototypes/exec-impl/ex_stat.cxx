// Example script to test <stat.hxx>

#include <iostream>
#include <vector>
#include "stat.hxx"


struct Fake_exec_policy { };

int main()
{
  std::vector<double> v{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double m = nola::stat::mean( v.size(), v.data() );

  std::cout << "\nmean = " << m << std::endl;
}