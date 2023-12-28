#include "elf.hpp"
#include "thug.hpp"
#include "bear.hpp"
#include <algorithm>

Bear::Bear(const int &_x, const int &_y, const std::string &_name)
{
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

void Bear::print(std::ostream &out)
{
    out << *this;
}

void Bear::accept(NPC *attacker, const int &distance)
{
}

std::ostream &operator<<(std::ostream &out, const Bear &other)
{
    return out << "Bear " << other.name << " {" << other.x << ", " << other.y << '}';
}