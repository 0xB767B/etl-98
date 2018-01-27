#ifndef ETL_98_ARRAY_H__
#define ETL_98_ARRAY_H__

#include <assert.h>

template<typename T, int N>
class Array
{
public:
  T elements[N];

  T& operator[](int i)
  {
    RangeCheck(i);
    return elements[i];
  }
private:
  void RangeCheck(int i)
  {
    assert(i < N);
  }
};

#endif

