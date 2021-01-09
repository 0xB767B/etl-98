template <unsigned int N>
class matrix
{
    float data[N*N];
 
public:
    float operator()(unsigned int row, unsigned int col) const
    {
        return data[row + N*col];
    }
 
    float& operator()(unsigned int row, unsigned int col)
    {
        return data[row + N*col];
    }

    // inside the matrix class
    template <typename ExprType>
    matrix<N>& operator=(const ExprType& e)
    {
        for(unsigned int row = 0; row < N; row++)
        {
            for(unsigned int col = 0; col < N; col++)
            {
                (*this)(row, col) = e(row, col);
            }
        }
        return (*this);
    }

};
 
template <unsigned int N>
std::ostream & operator<<(std::ostream& o, const matrix<N>& m)
{
    o << "[";
    for(unsigned int row = 0; row < N; row++)
    {
        for(unsigned int col = 0; col < N; col++)
        {
            o << m(row,col);
            if(col != N-1) o << ";";
        }
        if(row != N-1) o << "\n";
    }
    o << "]";
    return o;
}

