#include "Rhombus.h"
#include <typeinfo>
#include <cmath>

// Rhombus constructor
Rhombus::Rhombus(int d, string n, string desc)
{
    idNumber = idCount;
    name = n;
    description = desc;

    if (d % 2 == 0) {
        d = d + 1;
    }
    depth = d;

    if (depth % 2) { resize(grid, depth, depth); }
    else { resize(grid, depth + 1, depth + 1); }

    grid = draw('*', ' ');
}

// returns box height
int Rhombus::getBoxHeight() const {
    return depth;
}

// returns box width
int Rhombus::getBoxWidth() const {
    return depth;
}

// returns geometric area
double Rhombus::findGeoArea() const {
    return (depth * depth) * 0.5;
}

// returns geometric perimeter
double Rhombus::findGeoPerimeter() const {
    return 2.0 * sqrt(2) * depth;
}

// returns screen area
int Rhombus::findScreenArea() const {
    int n = depth / 2;

    return 2*n*(n+1) + 1;
}

// returns screen perimeter
int Rhombus::findScreenPerimeter() const {
    return 2 * (depth - 1);
}

// draws rhombus
Grid Rhombus::draw(char fChar, char bChar) const
{
    Grid drawGrid = grid;
    for (int x = 0; x < drawGrid.size(); x++) {
        for (int y = 0; y < drawGrid[0].size(); y++) {
            if (abs(x - (depth - 1) / 2) + abs(y - (depth - 1) / 2) < ((depth +2 ) / 2)) {
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