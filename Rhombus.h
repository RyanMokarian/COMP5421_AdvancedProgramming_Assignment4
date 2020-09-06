#ifndef A4_40080413_RHOMBUS_H
#define A4_40080413_RHOMBUS_H

#include "Shape.h"
class Rhombus : public Shape
{
public:
    Rhombus(int d, string name = "Diamond", string desc = "A parallelogram with equal sides");

    virtual int getBoxHeight() const override;
    virtual int getBoxWidth() const override;
    virtual double findGeoArea() const override;
    virtual double findGeoPerimeter() const override;
    virtual int findScreenArea() const override;
    virtual int findScreenPerimeter() const override;

    virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

    int depth = 0;

};

#endif //A4_40080413_RHOMBUS_H
