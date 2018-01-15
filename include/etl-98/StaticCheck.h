#ifndef ETL98_STATIC_CHECK_H__
#define ETL98_STATIC_CHECK_H__

namespace etl98
{

// Helpers for STATIC_CHECK macro
template<int>
struct CompileTimeError;

template<>
struct CompileTimeError<true> {};

///////////////////////////////////////////////////////////////////////////////
// STATIC_CHECK
//
// Check a condition at compile-time
//
// Invocation: STATIC_CHECK(expr, id)
//
// where expr is a compile-time integral ro pointer expression
// id is a valid c++ identifier that is used as an error-message.
// If expr is zero, id will appear in a compiler error msg
///////////////////////////////////////////////////////////////////////////////

#define StaticCheck(expr, msg)                                                \
  { etl98::CompileTimeError<((expr) != 0)> ERROR_##msg; (void)ERROR_##msg; }

}

#endif

