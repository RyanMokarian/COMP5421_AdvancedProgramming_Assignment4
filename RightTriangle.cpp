#include "RightTriangle.h"
#include <typeinfo>

// RightTriangle constructor
RightTriangle::RightTriangle(int b, string n, string desc)
{
    idNumber = idCount;
    name = n;
    description = desc;
    base = b;
    height = b;

    resize(grid, b, b);
    grid = draw('*', ' ');
}

// returns box height 
int RightTriangle::getBoxHeight() const {
    return height;
}

// returns box width
int RightTriangle::getBoxWidth() const {
    return base;
}

// returns geometric perimeter
double RightTriangle::findGeoPerimeter() const {
    return (2 + sqrt(2.0)) * height;
}

// returns screen area
int RightTriangle::findScreenArea() const {
    return (height * (height + 1)) / 2.0;
}

// returns screen perimeter
int RightTriangle::findScreenPerimeter() const {
    return 3 * (height - 1);
}

// draws RightTriangle
Grid RightTriangle::draw(char fChar, char bChar) const
{
    Grid drawGrid = grid;
    for (unsigned int x = 0; x < drawGrid.size(); x++) {
        for (unsigned int y = 0; y < drawGrid[0].size(); y++) {
            if (y <= x)
                drawGrid[x][y] = fChar;
            else
                drawGrid[x][y] = bChar;
        }
    }
    return drawGrid;
}