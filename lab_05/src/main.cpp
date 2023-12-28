#include <iostream>
#include "vector.hpp"
#include "allocator.hpp"
#include <map>
#include <vector>

int main()
{


    std::vector<int, Allocator<int>> v(10);
    v[0] = 1;
    for (size_t i = 1; i < 10; ++i) //заполнение факториалами
    {
        v[i] = v[i - 1] * i;
    }

    std::cout << "Here are the elements of a vector: " << std::endl;
    for (size_t i = 0; i != 10; ++i)
    {
        std::cout << i << " " << v[i] << std::endl;
    }
    std::cout << std::endl;
}