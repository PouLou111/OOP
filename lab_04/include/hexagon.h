#pragma once

#include "figure.h"
#include <iostream>
#include "point.h"

template<class T>
class Hexagon : public Figure<T> //определение класса шестиугольник наследуется от Figure
{
    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Hexagon<F>& f);
//дружественные операторы << и >> 
    template<class F>
    friend std::istream& operator>>(std::istream& is, Hexagon<F>& f);

public:
    Hexagon(); // конструктор по умолчанию
    Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6); //конструктор копировани
    Hexagon(const Hexagon<T>& other); //конструктор копирования

    virtual T area() const override; //площадь
    virtual Point<T>  center() const override; //центр

    Point<T>  get_point(const int i) const;
    size_t size() const;

    Hexagon<T>& operator=(const Hexagon<T>& right);//оператор присваивания
    Hexagon<T>& operator=(Hexagon<T>&& right);
    bool operator==(const Hexagon<T>& right) ;
    virtual  operator double() const override;

    ~Hexagon(){}; //деструктор

    Point<T> angles[6];
    size_t size_;
};

template <class T>
Hexagon<T>::Hexagon() : angles{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Hexagon<T>::Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6) {
    std::array<Point<T>, 6> points = {p1, p2, p3, p4, p5, p6};
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (points[i] == points[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
        angles[i] = points[i];
    }
    size_ = 6;
}

template <class T>
Hexagon<T>::Hexagon(const Hexagon<T>& other){
    if (this != &other) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = other.angles[i];
        }
        size_ = other.size_;
    }
}

template <class T>
Point<T> Hexagon<T>::center() const {
    std::cout << "Hexagon center() " << std::endl;
    T x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 6.0, y_c / 6.0);
}

template <class T>
T Hexagon<T>::area() const {
    T x1 = angles[0].x_; T y1 = angles[0].y_;
    T x2 = angles[1].x_; T y2 = angles[1].y_;
    T x3 = angles[2].x_; T y3 = angles[2].y_;
    T x4 = angles[0].x_; T y4 = angles[0].y_;
    T x5 = angles[1].x_; T y5 = angles[1].y_;
    T x6 = angles[2].x_; T y6 = angles[2].y_;
    Point center = this->center();
    double a = sqrt(abs((x1 - x2)) * abs((x1 - x2)) + abs(y1 - y2) * abs(y1 - y2));
    double area = ((3 * (sqrt(3))) / (2)) * (a * a);
    return area;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& right){
    if (this != &right) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = right.angles[i];
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& right){
    if (this != &right) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = std::move(right.angles[i]);
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
bool Hexagon<T>::operator==(const Hexagon<T>& right) {
    for(size_t i = 0; i < 6; ++i){
        if(angles[i] != right.angles[i]){
            return false;
        }
    }
    return true;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& f){
    for(size_t i = 0; i < 6; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T>& f){
    for(size_t i = 0; i < 6; ++i){
        is >> f.angles[i];
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (f.angles[i] == f.angles[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
    }
    f.size_ = 6;
    return is;
}

template <class T>
Hexagon<T>::operator double() const{
    return area();
}

template <class T>
size_t Hexagon<T>::size() const{
    return size_;
}

template <class T>
Point<T> Hexagon<T>::get_point(const int i) const{
    if ( i < 0 || i > 5){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}