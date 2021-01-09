#include <iostream>
#include "matrix.h"
#include "expression.h"
 
int main()
{
    matrix<2> m1;
    m1(0,0) = 1.0;
    m1(1,0) = 0.0;
    m1(0,1) = 4.0;
    m1(1,1) = 1.0;
 
    matrix<2> m2;
    m2(0,0) = 0.0;
    m2(1,0) = -1.0;
    m2(0,1) = 1.0;
    m2(1,1) = 2.0;
 
    matrix<2> m3;
    m3(0,0) = 1.0;
    m3(1,0) = -2.0;
    m3(0,1) = 3.0;
    m3(1,1) = 5.0;
 
    matrix<2> a;
    a = m1 + m2 + m3; 
    std::cout << a << std::endl;
}

