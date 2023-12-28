#include <iostream>
#include <gtest/gtest.h>
#include "vector.hpp"
#include "allocator.hpp"

TEST(constructors, defaulte)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p;
    EXPECT_EQ(p.size(), 0);
    EXPECT_EQ(p.capacity(), 0);
}

TEST(constructors, size_resize)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p(6, 0);
    EXPECT_EQ(p.size(), 6);
    EXPECT_EQ(p.capacity(), 6);
    EXPECT_EQ(p[0], 0);
    p.push_back(3);
    EXPECT_EQ(p[p.size() - 1], 3);
}

TEST(constructors, init_lst)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p{1, 2, 3, 4};
    int i = 1;
    for (int &elem : p)
    {
        EXPECT_EQ(elem, i++);
    }
}

TEST(constructors, another_vect)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p{1, 2, 3, 4};
    Vector<int, Allocator<int>> m(p);
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_EQ(p[i], m[i]);
    }
}

TEST(constructors, resize)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p(6, 0);
    p.push_back(3);
    p.pop_back();
    EXPECT_EQ(p[p.size() - 1], 0);
    EXPECT_EQ(p.size(), 6);
    EXPECT_EQ(p.capacity(), 12);
}

TEST(constructors, iters)
{
    Allocator<int> alloc;
    Vector<int, Allocator<int>> p(6, 0);
    p.push_back(3);
    EXPECT_EQ(p.begin() + 7, p.end());
}