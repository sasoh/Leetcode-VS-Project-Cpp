#include "Square.h"
#include <cmath>

Square::Square(int sideLength) : m_side{ sideLength } {}

int Square::getSide() const
{
    return m_side;
}

int Square::getPerimeter() const
{
    return 4 * m_side;
}

int Square::getArea() const
{
    return m_side * m_side;
}

double Square::getDiagonal() const
{
    return sqrt(2 * m_side * m_side);
}