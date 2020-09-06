#ifndef A4_40080413_SHAPE_H
#define A4_40080413_SHAPE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <cmath>

using namespace std;
using Grid = vector<vector<char>>;

class Shape
{
public:
    Shape() {
        ++idCount;
    }
    Shape(const string& name, const string& description) {
        ++idCount;
    }

    int getID() const;
    void setName(const string& n);
    virtual string getName() const;
    void setDescription(const int& desc);
    virtual string getDescription() const;
    virtual string toString() const;

    friend ostream& operator<<(ostream& sout, const Grid& grid);

    virtual int getBoxHeight() const = 0;
    virtual int getBoxWidth() const = 0;
    virtual double findGeoArea() const = 0;
    virtual double findGeoPerimeter() const = 0;
    virtual int findScreenArea() const = 0;
    virtual int findScreenPerimeter() const = 0;

    static int idCount;
    int idNumber = 0;
    string name="";
    string description="";
    double geoArea = 0;
    double geoPerimeter = 0;
    int screenArea = 0;
    int screenPerimeter = 0;

    Grid grid;

    friend ostream& operator<<(ostream& out, const Shape& str);


    virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;

    void resize(Grid& grid, int h, int w);



};

#endif //A4_40080413_SHAPE_H
