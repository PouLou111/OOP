#include "octagon.h"
#include <cmath>

using namespace std;

Octagon::Octagon(float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float p4_x, float p4_y, float p5_x, 
float p5_y, float p6_x, float p6_y, float p7_x, float p7_y, float p8_x, float p8_y){
    p1 = Point(p1_x, p1_y);
    p2 = Point(p2_x, p2_y);
    p3 = Point(p3_x, p3_y);
    p4 = Point(p4_x, p4_y);
    p5 = Point(p5_x, p5_y);
    p6 = Point(p6_x, p6_y);
    p7 = Point(p7_x, p7_y);
    p8 = Point(p8_x, p8_y);
}

Octagon::Octagon(istream& is)
{
    is >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8;
}

void Octagon::Print(ostream& os)
{
    os << "Octagon: " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6 << " " << p7 << " " << p8 << endl;
}

double Octagon::Area() //правильного восьмиугольника
{
    double a = p1.dist(p2);
    double s = (2 * a * a * ((sqrt(2)) + 1));
    return s;
}

size_t Octagon::VertexesNumber()
{
    return 8;
}

Octagon::~Octagon()
{
    cout << "Done\n";
}
bool Octagon::operator==(const Octagon& other) const{
    return p1 == other.p1 && p2 == other.p2 && p3 == other.p3 && p4 == other.p4 && p5 == other.p5 && p6 == other.p6 && p7 == other.p7 && p8 == other.p8;
}
Octagon& Octagon::operator=(const Octagon& other) {
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    p5 = other.p5;
    p6 = other.p6;
    p7 = other.p7;
    p8 = other.p8;
    return *this;
}