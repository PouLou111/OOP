#include <iostream>
#include <string>
#include "vector.h"

#include "point.h"
#include "figure.h"
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"


template<typename T> //шаблонная функция суммы
double sum_area(const Vector<T>& arr){
    double sum = 0;
    for(int i = 0; i < arr.size(); ++i){
        sum += arr.get(i)->area();
    }
    return sum;
}


int main(){
    try{ //создаем умные указатели на наши фигуры затем вводи и выводим
        std::unique_ptr<Triangle<double>> t = std::make_unique<Triangle<double>>();
        std::unique_ptr<Hexagon<double>> h = std::make_unique<Hexagon<double>>();
        std::unique_ptr<Octagon<double>> o = std::make_unique<Octagon<double>>();
        
        std::cin >> *t >> *h >> *o;
        std::cout << *t << *h << *o;


        Vector<std::unique_ptr<Figure<double>>> arr; //вектор из фигур

        arr.push_back(std::move(t));
        arr.push_back(std::move(h));
        arr.push_back(std::move(o));

        for (int i = 0; i < arr.size(); ++i) { //вывод их геометрич центров и площадей
            std::cout << "Geometric center of figure " << i + 1 << ": " << arr.get(i)->center() << std::endl;
            std::cout << "Area of figure " << i + 1 << ": " << arr.get(i)->area() << std::endl;
        }

        std::cout << "Total area of figures: " << sum_area(arr) << std::endl;
        arr.remove(0);
        std::cout << "Total area of figures: " << sum_area(arr) << std::endl;
        
    } catch(const std::exception& e) {//чекаем исключения
        std::cerr << e.what() << '\n';
    }
}