#include "etl-98/TypeList.h"

typedef TypeList<double, TypeList<float, NullType> > FloatingTypes;
typedef TypeList<char, TypeList<int, NullType> > IntTypes;

template<typename T>
class OutputClass
{
  void Output(T val)
  {
  }
};

int main()
{
}

