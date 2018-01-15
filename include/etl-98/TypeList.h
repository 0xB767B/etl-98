#ifndef ETL_98_TYPE_LIST_H__
#define ETL_98_TYPE_LIST_H__

namespace etl98 {

// A type representing Null. Can be used to mark certain border cases.
// Usually there is no objects created of type NullType. It basically indicates:
// "I am not an interesting type."
class NullType {};

///////////////////////////////////////////////////////////////////////////////
// Class template TypeList
//
// Building block for typelist of any length.
//
// Instantiation example:
// typedef TypeList<float, TypeList<double, NullType> > FloatTypes;
//
// Defines nested types:
// * Head (first element, a non-typelist type by convention)
// * Tail (second element, can be another typelist or NullType)
///////////////////////////////////////////////////////////////////////////////
template<typename H, typename T>
struct TypeList
{
  H head;
  T tail;
};

///////////////////////////////////////////////////////////////////////////////
// Class template Length
//
// Computes the length of a TypeList.
//
// Invocation (TList is a typelist):
// Length<TList>::value
//
// Returns a compile-time constant containing the length of TList. The
// end-terminator is not counted (by convention of type NullType).
///////////////////////////////////////////////////////////////////////////////

// Definition of template
template<typename TList>
struct Length;

// Specialized implementation for tail == NullType
template<>
struct Length<NullType>
{
  static const int value = 0;
};

// Generic implementation
template<typename T, typename U>
struct Length<TypeList<T, U> >
{
  static const int value = 1 + Length<U>::value;
};

}

#endif

