#include "triangle.h"
#include <cmath>

using namespace std;

Triangle::Triangle(float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y){
    p1 = Point(p1_x, p1_y);
    p2 = Point(p2_x, p2_y);
    p3 = Point(p3_x, p3_y);
}

Triangle::Triangle(istream& is)
{
    is >> p1 >> p2 >> p3;
}

void Triangle::Print(ostream& os)
{
    os << "Triangle: " << p1 << " " << p2 << " " << p3 << endl;
}

double Triangle::Area()
{
    double a = p1.dist(p2);
    double b = p2.dist(p3);
    double c = p3.dist(p1);
    double p = (a + b + c)/2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

size_t Triangle::VertexesNumber()
{
    return 3;
}

Triangle::~Triangle()
{
    cout << "Done\n";
}
bool Triangle::operator==(const Triangle& other) const{
    return p1 == other.p1 && p2 == other.p2 && p3 == other.p3;
}
Triangle& Triangle::operator=(const Triangle& other) {
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    return *this;
}