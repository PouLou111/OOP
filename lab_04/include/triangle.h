#pragma once

#include "figure.h"
#include <iostream>
#include "point.h"

template<class T>
class Triangle : public Figure<T> //определение класса треугольник наследуется от Figure
{
    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Triangle<F>& f);
//дружественные операторы << и >> 
    template<class F>
    friend std::istream& operator>>(std::istream& is, Triangle<F>& f);

public:
    Triangle(); // конструктор по умолчанию
    Triangle(Point<T>& p1, Point<T>& p2, Point<T>& p3); //конструктор копировани
    Triangle(const Triangle<T>& other); //конструктор копирования

    virtual T area() const override; //площадь
    virtual Point<T>  center() const override; //центр

    Point<T>  get_point(const int i) const;
    size_t size() const;

    Triangle<T>& operator=(const Triangle<T>& right);//оператор присваивания
    Triangle<T>& operator=(Triangle<T>&& right);
    bool     operator==(const Triangle<T>& right) ;
    virtual  operator double() const override;

    ~Triangle(){}; //деструктор

    Point<T> angles[3];
    size_t size_;
};

template <class T>
Triangle<T>::Triangle() : angles{Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Triangle<T>::Triangle(Point<T>& p1, Point<T>& p2, Point<T>& p3) {
    std::array<Point<T>, 3> points = {p1, p2, p3};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (points[i] == points[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
        angles[i] = points[i];
    }
    size_ = 3;
}

template <class T>
Triangle<T>::Triangle(const Triangle<T>& other){
    if (this != &other) {
        for(size_t i = 0; i < 3; ++i){
            angles[i] = other.angles[i];
        }
        size_ = other.size_;
    }
}

template <class T>
Point<T> Triangle<T>::center() const {
    std::cout << "Triangle center() " << std::endl;
    T x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 3.0, y_c / 3.0);
}

template <class T>
T Triangle<T>::area() const {
    T x1 = angles[0].x_; T y1 = angles[0].y_;
    T x2 = angles[1].x_; T y2 = angles[1].y_;
    T x3 = angles[2].x_; T y3 = angles[2].y_;
    Point center = this->center();
    double a = sqrt(abs((x1 - x2)) * abs((x1 - x2)) + abs(y1 - y2) * abs(y1 - y2));
    double b = sqrt(abs((x1 - x3)) * abs((x1 - x3)) + abs(y1 - y3) * abs(y1 - y3));
    double c = sqrt(abs((x3 - x2)) * abs((x3 - x2)) + abs(y3 - y2) * abs(y3 - y2));
    double p = (a + b + c) / 2;
    double area = sqrt(p(p - a)(p - b)(p - c));
    return area;
}

template <class T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& right){
    if (this != &right) {
        for(size_t i = 0; i < 3; ++i){
            angles[i] = right.angles[i];
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>&& right){
    if (this != &right) {
        for(size_t i = 0; i < 3; ++i){
            angles[i] = std::move(right.angles[i]);
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
bool Triangle<T>::operator==(const Triangle<T>& right) {
    for(size_t i = 0; i < 3; ++i){
        if(angles[i] != right.angles[i]){
            return false;
        }
    }
    return true;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Triangle<T>& f){
    for(size_t i = 0; i < 3; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}

template <class T>
std::istream& operator>>(std::istream& is, Triangle<T>& f){
    for(size_t i = 0; i < 3; ++i){
        is >> f.angles[i];
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (f.angles[i] == f.angles[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
    }
    f.size_ = 3;
    return is;
}

template <class T>
Triangle<T>::operator double() const{
    return area();
}

template <class T>
size_t Triangle<T>::size() const{
    return size_;
}

template <class T>
Point<T> Triangle<T>::get_point(const int i) const{
    if ( i < 0 || i > 2){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}