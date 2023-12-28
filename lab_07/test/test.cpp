#include <gtest/gtest.h>
#include <memory>
#include "npc.hpp"
#include "thug.hpp"
#include "elf.hpp"
#include "bear.hpp"

TEST(test_01, thug_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Thug>(x, y);

    EXPECT_EQ((a->position()).first, 100);
}

TEST(test_02, thug_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Thug>(x, y);

    EXPECT_EQ((a->position()).second, 100);
}

TEST(test_03, thug_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Thug>(x, y);
    EXPECT_EQ(ThugType, a->get_type());
}

TEST(test_04, thug_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Thug>(x, y);
    EXPECT_TRUE(a->is_alive());
}

TEST(test_05, thug_constructor)
{
    int x1{100};
    int y1{100};

    int x2{90};
    int y2{90};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Thug>(x1, y1);

    std::shared_ptr<NPC> b;
    b = std::make_shared<Thug>(x2, y2);
    EXPECT_TRUE(a->is_close(b, 100));
}

TEST(test_06, thug_constructor)
{
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Thug>(x, y);

    a->move(50, 50, 100, 100);
    EXPECT_EQ((a->position()).first, 60);
}

TEST(test_07, bear_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);

    EXPECT_EQ((a->position()).first, 100);
}

TEST(test_08, bear_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);

    EXPECT_EQ((a->position()).second, 100);
}

TEST(test_09, bear_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);
    EXPECT_EQ(BearType, a->get_type());
}

TEST(test_10, bear_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);
    EXPECT_TRUE(a->is_alive());
}

TEST(test_11, bear_constructor)
{
    int x1{100};
    int y1{100};

    int x2{90};
    int y2{90};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x1, y1);

    std::shared_ptr<NPC> b;
    b = std::make_shared<Thug>(x2, y2);
    EXPECT_TRUE(a->is_close(b, 100));
}

TEST(test_12, bear_constructor)
{
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Bear>(x, y);

    a->move(50, 50, 100, 100);
    EXPECT_EQ((a->position()).first, 60);
}

TEST(test_13, elf_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);

    EXPECT_EQ((a->position()).first, 100);
}

TEST(test_14, elf_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);

    EXPECT_EQ((a->position()).second, 100);
}

TEST(test_15, elf_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);
    EXPECT_EQ(ElfType, a->get_type());
}

TEST(test_16, elf_constructor)
{
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);
    EXPECT_TRUE(a->is_alive());
}

TEST(test_17, elf_constructor)
{
    int x1{100};
    int y1{100};

    int x2{90};
    int y2{90};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x1, y1);

    std::shared_ptr<NPC> b;
    b = std::make_shared<Thug>(x2, y2);
    EXPECT_TRUE(a->is_close(b, 100));
}

TEST(test_18, elf_constructor)
{
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Elf>(x, y);

    a->move(50, 50, 100, 100);
    EXPECT_EQ((a->position()).first, 60);
}