#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <memory>
#include "bear.hpp"
#include "thug.hpp"
#include "elf.hpp"
#include "factory.hpp"

TEST(Constructors, Bear)
{
    Bear s(0, 0, "Medved");
    std::stringstream out;
    s.print(out);
    ASSERT_EQ(out.str(), "Bear Medved {0, 0}");
}

TEST(Constructors, Thug)
{
    Thug t(1, 1, "Vor");
    std::stringstream out;
    t.print(out);
    ASSERT_EQ(out.str(), "Thug Vor {1, 1}");
}

TEST(Constructors, Elf)
{
    Elf e(2, 2, "Dobbi");
    std::stringstream out;
    e.print(out);
    ASSERT_EQ(out.str(), "Elf Dobbi {2, 2}");
}

TEST(Fabric, basic)
{
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Bear", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    persons.push_back(factory("Elf", "Name", 0, 0));

    std::stringstream out;
    for (auto &elem : persons)
    {
        elem->print(out);
    }
    ASSERT_EQ(out.str(), "Bear Name {0, 0}Thug Name {0, 0}Elf Name {0, 0}");
}

TEST(Fighting, basic)
{
    std::vector<std::shared_ptr<NPC>> persons;
    persons.push_back(factory("Bear", "Name", 0, 0));
    persons.push_back(factory("Thug", "Name", 0, 0));
    persons.push_back(factory("Elf", "Name", 0, 0));

    for (auto &defender : persons)
    {
        for (auto &attacker : persons)
        {
            defender->accept(attacker.get(), 0);
        }
    }
    for (int elem = 0; elem < 3; ++elem)
    {
        if (elem == 0)
        {
            ASSERT_TRUE(persons[elem]->is_alive());
            continue;
        }
        ASSERT_FALSE(persons[elem]->is_alive());
    }
}