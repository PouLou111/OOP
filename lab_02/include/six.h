#pragma once

#include <string>
#include <iostream>

class Six{
    public:
        Six();
        Six(const size_t & n, unsigned char t = 0);
        Six(const std::initializer_list<unsigned char> & t);
        Six(const std::string & t);
        Six(const Six& other);
        Six(Six&& other) noexcept;
        virtual ~Six() noexcept;
        // bool operator<=(const Six & t) const;
        unsigned char* GetArray() const noexcept;
        size_t GetSize() const noexcept;
    private:
        size_t _size;
        unsigned char* _array;
};
std::ostream& operator<<(std::ostream & os, const Six & t);