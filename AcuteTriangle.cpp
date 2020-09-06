#include "AcuteTriangle.h"
#include <typeinfo>
#include <cmath>

// AcuteTriangle constructor
AcuteTriangle::AcuteTriangle(int b, string n, string desc)
{
    idNumber = idCount;
    name = n;
    description = desc;
    if (b % 2 == 0) {
        b = b + 1;
    }
    base = b;

    height = (b + 1) / 2.0;

    resize(grid, height, b);
    grid = draw('*', ' ');

}

// returns box height
int AcuteTriangle::getBoxHeight() const {
    return height;
}

// returns box width
int AcuteTriangle::getBoxWidth() const {
    return base;
}

// returns geometric perimeter
double AcuteTriangle::findGeoPerimeter() const {
    return base + sqrt(base * base + 4 * height * height);
}

// returns screen area
int AcuteTriangle::findScreenArea() const {
    return height * height;
}

// returns screen perimeter
int AcuteTriangle::findScreenPerimeter() const {
    return 4 * (height - 1);
}

// draws AcuteTriangle
Grid AcuteTriangle::draw(char fChar, char bChar) const
{
    Grid drawGrid = grid;
    for (int x = 0; x < drawGrid.size(); x++) {
        for (int y = 0; y < drawGrid[0].size(); y++) {
            if (abs(x - (2 * height - 1) / 2) + abs(y - (2 * height - 1) / 2) < (height)) {
                drawGrid[x][y] = fChar;
            }
            else
            {
                drawGrid[x][y] = bChar;
            }
        }
    }
    return drawGrid;
}

