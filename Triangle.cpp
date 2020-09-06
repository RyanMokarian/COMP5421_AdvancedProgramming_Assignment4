#include "Triangle.h"
#include <typeinfo>


// returns geometric area
double Triangle::findGeoArea() const {
    return (height * base) * 0.5;
}

// draws triangle
Grid Triangle::draw(char fChar, char bChar) const
{
    Grid drawGrid = grid;
    for (unsigned int x = 0; x < drawGrid.size(); x++) {
        for (unsigned int y = 0; y < drawGrid[0].size(); y++) {
            drawGrid[x][y] = fChar;
        }
    }
    return drawGrid;
}
