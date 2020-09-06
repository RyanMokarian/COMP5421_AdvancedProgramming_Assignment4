#ifndef A4_40080413_RECTANGLE_H
#define A4_40080413_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(int w, int h, string name="Rectangle", string desc="Four right sides");

    virtual int getBoxHeight() const override;
    virtual int getBoxWidth() const override;
    virtual double findGeoArea() const override;
    virtual double findGeoPerimeter() const override;
    virtual int findScreenArea() const override;
    virtual int findScreenPerimeter() const override;

    virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

    int height = 0;
    int width = 0;

};

#endif //A4_40080413_RECTANGLE_H
