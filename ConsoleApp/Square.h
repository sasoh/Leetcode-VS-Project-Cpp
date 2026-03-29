#pragma once

class Square {
public:
    explicit Square(int sideLength);
    int getSide() const;
    int getPerimeter() const;
    int getArea() const;
    double getDiagonal() const;
private:
    int m_side;
};