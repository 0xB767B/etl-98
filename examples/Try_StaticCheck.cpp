#include "etl-98/StaticCheck.h"

template<class To, class From>
To safe_reinterpret_cast(From from)
{
  StaticCheck(sizeof(From) <= sizeof(To),
     Destination_Type_Too_Narrow);

  return reinterpret_cast<To>(from);
}

typedef void* toType;
static toType c;

int main()
{
  void* somePointer = 0;
  c = safe_reinterpret_cast<toType>(somePointer);

  return 0;
};

