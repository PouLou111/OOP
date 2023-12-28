#pragma once

#include "figure.h"
#include <iostream>
#include "point.h"

template<class T>
class Octagon : public Figure<T> //определение класса шестиугольник наследуется от Figure
{
    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Octagon<F>& f);
//дружественные операторы << и >> 
    template<class F>
    friend std::istream& operator>>(std::istream& is, Octagon<F>& f);

public:
    Octagon(); // конструктор по умолчанию
    Octagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6, Point<T>& p7, Point<T>& p8); //конструктор копировани
    Octagon(const Octagon<T>& other); //конструктор копирования

    virtual T area() const override; //площадь
    virtual Point<T>  center() const override; //центр

    Point<T>  get_point(const int i) const;
    size_t size() const;

    Octagon<T>& operator=(const Octagon<T>& right);//оператор присваивания
    Octagon<T>& operator=(Octagon<T>&& right);
    bool operator==(const Octagon<T>& right) ;
    virtual  operator double() const override;

    ~Octagon(){}; //деструктор

    Point<T> angles[8];
    size_t size_;
};

template <class T>
Octagon<T>::Octagon() : angles{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Octagon<T>::Octagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6, Point<T>& p7, Point<T>& p8) {
    std::array<Point<T>, 8> points = {p1, p2, p3, p4, p5, p6, p7, p8};
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (points[i] == points[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
        angles[i] = points[i];
    }
    size_ = 8;
}

template <class T>
Octagon<T>::Octagon(const Octagon<T>& other){
    if (this != &other) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = other.angles[i];
        }
        size_ = other.size_;
    }
}

template <class T>
Point<T> Octagon<T>::center() const {
    std::cout << "Octagon center() " << std::endl;
    T x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 8.0, y_c / 8.0);
}

template <class T>
T Octagon<T>::area() const {
    T x1 = angles[0].x_; T y1 = angles[0].y_;
    T x2 = angles[1].x_; T y2 = angles[1].y_;
    T x3 = angles[2].x_; T y3 = angles[2].y_;
    T x4 = angles[3].x_; T y4 = angles[3].y_;
    T x5 = angles[4].x_; T y5 = angles[4].y_;
    T x6 = angles[5].x_; T y6 = angles[5].y_;
    T x7 = angles[4].x_; T y7 = angles[4].y_;
    T x8 = angles[5].x_; T y8 = angles[5].y_;
    Point center = this->center();
    double a = sqrt(abs((x1 - x2)) * abs((x1 - x2)) + abs(y1 - y2) * abs(y1 - y2));
    double area = (2 * a * a * ((sqrt(2)) + 1));
    return area;
}

template <class T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = right.angles[i];
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = std::move(right.angles[i]);
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
bool Octagon<T>::operator==(const Octagon<T>& right) {
    for(size_t i = 0; i < 8; ++i){
        if(angles[i] != right.angles[i]){
            return false;
        }
    }
    return true;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& f){
    for(size_t i = 0; i < 8; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}

template <class T>
std::istream& operator>>(std::istream& is, Octagon<T>& f){
    for(size_t i = 0; i < 8; ++i){
        is >> f.angles[i];
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (f.angles[i] == f.angles[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
    }
    f.size_ = 8;
    return is;
}

template <class T>
Octagon<T>::operator double() const{
    return area();
}

template <class T>
size_t Octagon<T>::size() const{
    return size_;
}

template <class T>
Point<T> Octagon<T>::get_point(const int i) const{
    if ( i < 0 || i > 5){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}