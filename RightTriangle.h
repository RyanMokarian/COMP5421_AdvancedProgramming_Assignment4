#ifndef A4_40080413_RIGHTTRIANGLE_H
#define A4_40080413_RIGHTTRIANGLE_H

#include "Triangle.h"
class RightTriangle : public Triangle
{
public:
    RightTriangle(int b, string name = "Right triangle", string desc = "One right and two acute angles");

    virtual int getBoxHeight() const override;
    virtual int getBoxWidth() const override;
    virtual double findGeoPerimeter() const override;
    virtual int findScreenArea() const override;
    virtual int findScreenPerimeter() const override;

    virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

};

#endif //A4_40080413_RIGHTTRIANGLE_H
