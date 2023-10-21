#pragma once

#include <iostream>
#include "figure.h"

using namespace std;

class Triangle : public Figure
{
private:
    Point p1, p2, p3;
public:    
    Triangle();
    Triangle(float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y);
    Triangle(istream& is);
    double Area();
    void Print(ostream& os);
    size_t VertexesNumber();
    virtual ~Triangle();
    bool operator==(const Triangle& other) const;
    Triangle& operator=(const Triangle& other);
};