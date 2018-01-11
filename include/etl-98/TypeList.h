#ifndef ETL_98_TYPE_LIST_H__
#define ETL_98_TYPE_LIST_H__

namespace etl98 {
class NullType {};

template<typename H, typename T>
struct TypeList
{
  H head;
  T tail;
};
}

#endif

