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
//
// Note: You should not instantiate Typelists as explained in the instantiation
//       example. Use Typelistops::MakeTypelist instead!
///////////////////////////////////////////////////////////////////////////////
template<typename H, typename T>
struct Typelist
{
  typedef H head;
  typedef T tail;
};

namespace TypelistOps
{

///////////////////////////////////////////////////////////////////////////////
// Class template MakeTypelist
//
// Build a Typelist of types passed as arguments.
///////////////////////////////////////////////////////////////////////////////
template<typename T0  = NullType, typename T1  = NullType, 
         typename T2  = NullType, typename T3  = NullType, 
         typename T4  = NullType, typename T5  = NullType,
         typename T6  = NullType, typename T7  = NullType, 
         typename T8  = NullType, typename T9  = NullType, 
         typename T10 = NullType, typename T11 = NullType,
         typename T12 = NullType, typename T13 = NullType, 
         typename T14 = NullType, typename T15 = NullType, 
         typename T16 = NullType, typename T17 = NullType,
         typename T18 = NullType, typename T19 = NullType
         >
struct MakeTypelist
{
private:
  typedef typename MakeTypelist<T1, T2, T3, T4, T5, 
                                T6, T7, T8, T9, T10,
                                T11, T12, T13, T14, T15, 
                                T16, T17, T18, T19>::Result TailResult;
public:
  typedef Typelist<T0, TailResult> Result;
};

template<>
struct MakeTypelist<>
{
  typedef NullType Result;
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
//
// Inspired by: 
// https://stackoverflow.com/questions/7704589/basic-typelist-functionality
//
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

