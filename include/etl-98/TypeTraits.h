#ifndef ETL98_TYPE_TRAITS_H__
#define ETL98_TYPE_TRAITS_H__

namespace etl98 {
template<typename T, typename U>
struct IsSame
{
  // This is the default case. To different types are not the same.
  static const bool value = false;
};

template<typename T>
struct IsSame<T, T>
{
  // Specialization for two equal types. The are the same.
  static const bool value = true;
};
}

#endif

