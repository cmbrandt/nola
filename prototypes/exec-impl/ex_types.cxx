// Checking the type information for each exec argument

#include <iostream>
#include "exec.hxx"


int main()
{
  std::cout << "\nint                                      "
            << nola::exec::is_execution_policy_v<int>
            << "\nnola::exec::sequential_policy            "
            << nola::exec::is_execution_policy_v<nola::exec::sequential_policy>
            << "\nnola::exec::parallel_policy              "
            << nola::exec::is_execution_policy_v<nola::exec::parallel_policy>
            << "\nnola::exec::parallel_unsequential_policy "
            << nola::exec::is_execution_policy_v<nola::exec::parallel_unsequential_policy>
            << "\nnola::exec::unsequential_policy          "
            << nola::exec::is_execution_policy_v<nola::exec::unsequential_policy>
            << "\nvoid                                     "
            << nola::exec::is_execution_policy_v<void><< std::endl;  

  std::cout << "\nDone." << std::endl;
}