template <typename LeftOperandType, typename OperationTag, typename RightOperandType>
struct Expression
{
    const LeftOperandType& l;
    const RightOperandType& r;
 
    Expression(const LeftOperandType& l_, const RightOperandType& r_) : l(l_), r(r_) { }
 
    float operator() (unsigned int row, unsigned int col) const
    {
        return OperationTag::apply(l(row, col), r(row,col));
    }
};

struct plus
{
    static float apply(float a, float b)
    {
        return a+b;
    }
};

template <typename L, typename R>
Expression<L, plus, R> operator+(const L& l, const R& r)
{
    return Expression<L, plus, R>(l, r);
}

