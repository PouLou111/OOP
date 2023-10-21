#include "hexagon.h"
#include <cmath>

using namespace std;

Hexagon::Hexagon(float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float p4_x, float p4_y, float p5_x, 
float p5_y, float p6_x, float p6_y){
    p1 = Point(p1_x, p1_y);
    p2 = Point(p2_x, p2_y);
    p3 = Point(p3_x, p3_y);
    p4 = Point(p4_x, p4_y);
    p5 = Point(p5_x, p5_y);
    p6 = Point(p6_x, p6_y);
}

Hexagon::Hexagon(istream& is)
{
    is >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
}

void Hexagon::Print(ostream& os)
{
    os << "Hexagon: " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6 << endl;
}

double Hexagon::Area() //правильного вшестиугольника
{
    double a = p1.dist(p2);
    double s = ((3 * (sqrt(3))) / (2)) * (a * a);
    return s;
}

size_t Hexagon::VertexesNumber()
{
    return 6;
}

Hexagon::~Hexagon()
{
    cout << "Done\n";
}
bool Hexagon::operator==(const Hexagon& other) const{
    return p1 == other.p1 && p2 == other.p2 && p3 == other.p3 && p4 == other.p4 && p5 == other.p5 && p6 == other.p6;
}
Hexagon& Hexagon::operator=(const Hexagon& other) {
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    p5 = other.p5;
    p6 = other.p6;
    return *this;
}