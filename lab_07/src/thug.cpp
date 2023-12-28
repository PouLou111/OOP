#include "bear.hpp"
#include "elf.hpp"
#include "thug.hpp"

Thug::Thug(int x, int y) : NPC(ThugType, x, y) {}
Thug::Thug(std::istream &is) : NPC(ThugType, is) {}

bool Thug::accept(std::shared_ptr<NPC> visitor)
{
    return visitor->fight(std::shared_ptr<Thug>(this, [](Thug *) {}));
}

void Thug::print()
{
    std::cout << *this;
}

bool Thug::fight(std::shared_ptr<Bear> other)
{
    fight_notify(other, false);
    return false;
}

bool Thug::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return false;
}

bool Thug::fight(std::shared_ptr<Thug> other)
{
    fight_notify(other, true);
    return false;
}

void Thug::save(std::ostream &os)
{
    os << ThugType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Thug &Thug)
{
    os << "Thug: " << *static_cast<NPC *>(&Thug) << std::endl;
    return os;
}