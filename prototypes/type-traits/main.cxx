// main.cxx

#include <iostream>
#include "traits.hxx"
#include "exec.hxx"


int main()
{
  std::cout << std::endl << is_execution_policy_v<int>
            << std::endl << is_execution_policy_v<float>
            << std::endl << is_execution_policy_v<sequential_policy>
            << std::endl << is_execution_policy_v<parallel_policy>
            << std::endl << is_execution_policy_v<parallel_unsequential_policy>
            << std::endl << is_execution_policy_v<unsequential_policy>
            << std::endl;

  std::cout << "\nDone." << std::endl;
}

