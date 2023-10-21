#pragma once

#include <iostream>
#include "figure.h"

using namespace std;

class Octagon : public Figure
{
private:
    Point p1, p2, p3, p4, p5, p6, p7, p8;
public:    
    Octagon();
    Octagon(float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float p4_x, float p4_y, float p5_x, 
float p5_y, float p6_x, float p6_y, float p7_x, float p7_y, float p8_x, float p8_y);
    Octagon(istream& is);
    double Area();
    void Print(ostream& os);
    size_t VertexesNumber();
    virtual ~Octagon();
    bool operator==(const Octagon& other) const;
    Octagon& operator=(const Octagon& other);
};