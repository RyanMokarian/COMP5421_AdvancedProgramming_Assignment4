#include "Shape.h"

using namespace std;
using Grid = vector<vector<char>>;

// returns unique shape object idNumber
int Shape::getID() const {
    return idNumber;
}

// sets shape name
void Shape::setName(const string& n) {
    name = n;
}

// returns shape name
string Shape::getName() const {
    return name;
}

// sets shape description
void Shape::setDescription(const int& desc) {
    description = desc;
}

// returns shape description
string Shape::getDescription() const {
    return description;
}

// creates string describing the attributes of the shape object
string Shape::toString() const {

    ostringstream output;
    output << fixed << setprecision(2);
    output << "id: " << idNumber
           << "\nShape name: " << getName()
           << "\nDescription: " << getDescription()
           << "\nB. box width: " << getBoxWidth()
           << "\nB. box height: " << getBoxHeight()
           << "\nScr area: " << findScreenArea()
           << "\nGeo area: " << findGeoArea()
           << "\nScr perimeter: " << findScreenPerimeter()
           << "\nGeo perimeter: " << findGeoPerimeter()
           << "\nStatic type: " << typeid(this).name()
           << "\nDynamic type: " << typeid(*this).name()
           << endl;
    return output.str();

}

// initializes counter for shape objects
int Shape::idCount = 0;

// overloads << operator
ostream& operator<<(ostream& out, const Shape& str) {

    return out<< str.toString();
}

// resizes grid
void Shape::resize(Grid& grid, int h, int w)
{
    grid.resize(h);
    for (int i = 0; i < h; ++i)
        grid[i].resize(w);
}
