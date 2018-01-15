#include <iostream>
#include "etl-98/TypeList.h"

typedef etl98::TypeList<double, etl98::TypeList<float, etl98::NullType> > FloatingTypes;
typedef etl98::TypeList<char, etl98::TypeList<short, etl98::TypeList<int, etl98::NullType> > > IntegerTypes;

int main()
{
  std::cout << etl98::Length<FloatingTypes>::value << std::endl;
  std::cout << etl98::Length<IntegerTypes>::value << std::endl;

  return 0;
}

