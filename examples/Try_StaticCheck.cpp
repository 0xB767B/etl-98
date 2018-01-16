#include "etl-98/StaticCheck.h"
#include "Add.h"

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

  int a = Add<int>(17, 27); // Compilation fails due to static check.
  (void)a;
  float b = Add<float>(17.0f, 27.0f); // Static check does not fail
  (void)b;
  double c = Add<double>(17.0, 27.0); // Static check does not fail
  (void)c;

  return 0;
};

