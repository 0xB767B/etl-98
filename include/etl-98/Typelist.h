#ifndef ETL_98_TYPE_LIST_H__
#define ETL_98_TYPE_LIST_H__

#include "TypeTraits.h"

namespace etl98 {

// A type representing Null. Can be used to mark certain border cases.
// Usually there is no objects created of type NullType. It basically indicates:
// "I am not an interesting type."
class NullType {};

///////////////////////////////////////////////////////////////////////////////
// Class template Typelist
//
// Building block for typelist of any length.
//
// Instantiation example:
// typedef Typelist<float, Typelist<double, NullType> > FloatTypes;
//
// Defines nested types:
// * Head (first element, a non-typelist type by convention)
// * Tail (second element, can be another typelist or NullType)
///////////////////////////////////////////////////////////////////////////////
template<typename H, typename T>
struct Typelist
{
  typedef H head;
  typedef T tail;
};

///////////////////////////////////////////////////////////////////////////////
// Class template Length
//
// Computes the length of a Typelist.
//
// Invocation (TList is a typelist):
// Length<TList>::value
//
// Returns a compile-time constant containing the length of TList. The
// end-terminator is not counted (by convention of type NullType).
///////////////////////////////////////////////////////////////////////////////

namespace TypelistOps
{

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
struct Length<Typelist<T, U> >
{
  static const int value = 1 + Length<U>::value;
};

///////////////////////////////////////////////////////////////////////////////
// Class template Contains
//
// Determines whether a type T is in a given Typelist.
//
// Invocation (TList is a typelist):
// Contains<TList, T>
//
// Returns true if T is contained in TList, false otherwise
///////////////////////////////////////////////////////////////////////////////

// Definition of template
template<typename TList, typename T>
struct Contains
{
  static const bool value =
    IsSame<typename TList::head, T>::value       // Base case
    || Contains<typename TList::tail, T>::value; // Recursion
};

// Specialized implementation for tail == NullType
template<typename T>
struct Contains<NullType, T>
{
  static const bool value = false; // Terminal condition
};

}

}

#endif

