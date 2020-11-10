
#include <iostream>
#include <vector>
#include <nola/cxx17/util.hxx>


int main()
{
  std::vector<float>  v1{ 1.2, 2.2, 3.2, 4.2, 5.2 };
  std::vector<double> v2{ 0.5, 1.5, 2.5, 3.5, 4.5 };
  std::vector<double> v3{ 0.5, 1.5, 2.5, 3.5, 4.5 };

  std::vector<float>  m1{ 1.2, 2.2, 3.2, 4.2, 5.2, 6.2 };
  std::vector<float>  m2{ 1.2, 2.2, 3.2, 4.2, 5.2, 6.2 };
  std::vector<double> m3{ 0.5, 1.5, 2.5, 3.5, 4.5, 6.5 };

  auto r1 = nola::util::compare_containers( v2.size(), v2.data(), v3.data() );
  auto r2 = nola::util::compare_containers( m1.size(), m1.data(), m2.data() );

  std::cout << "\nr1 = " << r1
            << "\nr2 = " << r2 << std::endl;

  nola::util::print_vector( "\nv1", v1.size(), v1.data() );
  nola::util::print_vector( "\nv2", v2.size(), v2.data() , 2, 3);

  nola::util::print_matrix( "\nm1", 3, 2, m1.data() );
  nola::util::print_matrix( "\nm2", 2, 3, m2.data() , 2, 3);
}