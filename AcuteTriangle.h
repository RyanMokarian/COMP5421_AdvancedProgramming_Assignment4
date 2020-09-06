#ifndef A4_40080413_ACUTETRIANGLE_H
#define A4_40080413_ACUTETRIANGLE_H

#include "Triangle.h"
class AcuteTriangle : public Triangle
{

public:
    AcuteTriangle(int b, string name = "Wedge", string desc = "All acute angles");

    virtual int getBoxHeight() const override;
    virtual int getBoxWidth() const override;
    virtual double findGeoPerimeter() const override;
    virtual int findScreenArea() const override;
    virtual int findScreenPerimeter() const override;

    virtual Grid draw(char fChar = '*', char bChar = ' ') const override;
};


#endif //A4_40080413_ACUTETRIANGLE_H
