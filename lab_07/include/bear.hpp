#pragma once
#include "npc.hpp"

struct Bear : public NPC
{
    Bear(int x, int y);
    Bear(std::istream &is);

    void print() override;

    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Thug> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Bear &bear);
};