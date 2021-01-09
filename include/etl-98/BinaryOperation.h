#ifndef ETL_98_TYPE_LIST_H__
#define ETL_98_TYPE_LIST_H__


namespace etl98 {

template<typename T>
class BinaryOperand
{
  typedef T ValueType;

  ValueType value;
};

template<typename LeftOperand, typename OperationTag, typename RightOperand>
struct Expresion
{
  const LeftOperand& _lhs;
  const RightOperand& _rhs;

  Expresion(const LeftOperand& lhs, const RightOperand& rhs) : _lhs(lhs), _rhs(rhs)
  {
  }
};

struct ShiftLeft
{
  static Expresion::ValueType Apply(Expresion::ValueType a, Expresion::ValueType b)
  {
    return a << b;
  }
};

}

#endif

