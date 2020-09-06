#ifndef A4_40080413_TRIANGLE_H
#define A4_40080413_TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape

{
public:
    virtual double findGeoArea() const override;

    // pure virtual
    virtual double findGeoPerimeter() const = 0;
    virtual int findScreenArea() const = 0;
    virtual int findScreenPerimeter() const = 0;

    virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

    int height = 0;
    double base = 0;


};

#endif //A4_40080413_TRIANGLE_H
