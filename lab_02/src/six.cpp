#include "six.h"
#include <algorithm>
#include <exception>

bool SixCheck(char c){
    return (0 <= c - '0') && (6 > c - '0');
}

Six::Six() : _size{0}, _array{nullptr} {}

Six::Six(const size_t & n, unsigned char t){
    _size = n;
    _array = new unsigned char [_size];
    for (int i = 0; i < _size; i++){
        _array[i] = t;
    }
}

Six::Six(const std::initializer_list<unsigned char> &t){
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i{0};
    for (unsigned char c: t){
        if (!SixCheck(c)) throw std::logic_error("Не 6СС");
        _array[i++] = c;
    }
}

Six::Six(const std::string & t) {
    _size = t.size();
    _array = new unsigned char [_size];
    for (size_t i{0}; i < _size; i++){
        _array[i] = t[i];
    }
    
}

Six::Six(const Six &other) noexcept{
    _size  = other._size;
    _array = new unsigned char[_size];
    for(size_t i{0};i<_size;++i){
         _array[i] = other._array[i];
    }
} 

Six::Six(Six&& other) noexcept{
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

Six::~Six() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}


size_t Six::GetSize() const noexcept{
    return _size;
}

unsigned char* Six::GetArray() const noexcept{
    return _array;
}

std::ostream& operator<<(std::ostream & os, const Six & t) {
    size_t i = t.GetSize();
    while(i != 0) {
        i--;
        os << t.GetArray()[i];
    }
    return os;
}
