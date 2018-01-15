#include <iostream>
#include "etl-98/Typelist.h"

typedef etl98::Typelist<double, etl98::Typelist<float, etl98::NullType> > FloatingTypes;
typedef etl98::Typelist<char, etl98::Typelist<short, etl98::Typelist<int, etl98::NullType> > > IntegerTypes;

int main()
{
  std::cout << etl98::Length<FloatingTypes>::value << std::endl;
  std::cout << etl98::Length<IntegerTypes>::value << std::endl;

  std::cout << etl98::Contains<FloatingTypes, float>::value << std::endl;
  std::cout << etl98::Contains<FloatingTypes, int>::value << std::endl;

  std::cout << etl98::Contains<IntegerTypes, float>::value << std::endl;
  std::cout << etl98::Contains<IntegerTypes, int>::value << std::endl;

  return 0;
}

