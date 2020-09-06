#include "Rectangle.h"
#include <typeinfo>

// Rectangle constructor
Rectangle::Rectangle(int w, int h, string n, string desc)
{
    idNumber = idCount;
    name = n;
    description = desc;
    width = w;
    height = h;

    resize(grid, h, w);
    grid = draw('*', ' ');
}

// returns box height
int Rectangle::getBoxHeight() const {
    return height;
}

// returns box width
int Rectangle::getBoxWidth() const {
    return width;
}

// returns geometric area
double Rectangle::findGeoArea() const {
    return 1.0 * height * width;
}

// returns geometric perimeter
double Rectangle::findGeoPerimeter() const {
    return 2.0 * (height + width);
}

// returns screen area
int Rectangle::findScreenArea() const {
    return height * width;
}

// returns screen perimeter
int Rectangle::findScreenPerimeter() const {
    return 2 * (height + width) - 4;
}

// draws rectangle
Grid Rectangle::draw(char fChar, char bChar) const
{
    Grid drawGrid = grid;
    for (unsigned int x = 0; x < drawGrid.size(); x++) {
        for (unsigned int y = 0; y < drawGrid[0].size(); y++) {
            drawGrid[x][y] = fChar;

        }
    }
    return drawGrid;
}