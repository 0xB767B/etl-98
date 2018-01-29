#ifndef ETL_98_POW_2_H__
#define ETL_98_POW_2_H__

template<int N>
struct Pow2
{
  static const int value = 1 << N;
};

template<>
struct Pow2<0>
{
  static const int value = 1;
};

#endif

