// Example script to test <exec.hxx>

#include <iostream>
#include <vector>
#include "exec.hxx"
#include "stat.hxx"


int main()
{
  //Fake_exec_policy exec;

  exec::parallel_policy exec1;
  std::vector<double> v{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  double m1 = stat::mean( v.size(), v.data() );
  double m2 = stat::mean( exec::parallel_policy{}, v.size(), v.data() );
  //double m2 = stat::mean( exec1, v.size(), v.data() );
  double m3 = stat::mean( exec::parallel_unsequenced_policy{}, v.size(), v.data() );
  double m4 = stat::mean( exec::unsequenced_policy{},          v.size(), v.data() );
  double m5 = stat::mean( exec::sequenced_policy{},            v.size(), v.data() );
  double m6 = stat::mean( 5, v.size(), v.data() );

  std::cout << "\nmean1 = " << m1
            << "\nmean2 = " << m2
            << "\nmean3 = " << m3
            << "\nmean4 = " << m4 
            << "\nmean5 = " << m5 
            << "\nmean6 = " << m6 << std::endl;
}