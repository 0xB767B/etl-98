#ifndef ADD_H__
#define ADD_H__

#include "etl-98/Typelist.h"
#include "etl-98/TypeTraits.h"
#include "etl-98/StaticCheck.h"

typedef etl98::Typelist<float, etl98::Typelist<double, etl98::NullType> > SupportedTypes;

template<typename T>
T Add(T a, T b)
{
  StaticCheck((etl98::Contains<SupportedTypes, T>::value == true),
    STATIC_CHECK_ERROR_TYPE_NOT_SUPPORTED);

 return a + b;
}

#endif

