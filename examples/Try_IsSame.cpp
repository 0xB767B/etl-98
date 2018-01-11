#include <iostream>
#include "etl-98/TypeTraits.h"

class A
{
};

class B
{
};

int main()
{
  std::cout << etl98::IsSame<char, int>::value  << std::endl;
  std::cout << etl98::IsSame<char, char>::value  << std::endl;
  std::cout << etl98::IsSame<A, B>::value  << std::endl;
  std::cout << etl98::IsSame<A, A>::value  << std::endl;

  return 0;
}

