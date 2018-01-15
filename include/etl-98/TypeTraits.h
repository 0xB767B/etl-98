#ifndef ETL98_TYPE_TRAITS_H__
#define ETL98_TYPE_TRAITS_H__

namespace etl98 {

///////////////////////////////////////////////////////////////////////////////
// Class template IsSame
//
// Check if two types are the same.
//
// Invocation:
// IsSame<int, float>::value
//
// Returns a compile-time constant bool. true if types are the same, false
// otherwise.

// Definition of template
template<typename T, typename U>
struct IsSame
{
  // This is the default case. To different types are not the same.
  static const bool value = false;
};

// Specialized implementation for types are the same.
template<typename T>
struct IsSame<T, T>
{
  // Specialization for two equal types. The are the same.
  static const bool value = true;
};
}

#endif

