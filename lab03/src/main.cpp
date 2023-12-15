#include <iostream>
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include <vector>

int main(){
    std::vector<Figure*> figures;
    bool start = 1;
    int type_of_figure;
    while (start){

        std::cout << "Select a type of figure to add to the vector: \n";
        std::cout << " 1 - Triangle \n";
        std::cout << " 2 - Hexagon \n";
        std::cout << " 3 - Octagon \n";
        std::cin >> type_of_figure;

        if (type_of_figure == 1){
            cout << "Enter triangle coordinates: \n";
            Figure* triangle = new Triangle(cin);
            figures.push_back(triangle);
        } else if(type_of_figure == 2){
            cout << "Enter hexagon coordinates: \n";
            Figure* hexagon = new Hexagon(cin);
            figures.push_back(hexagon);
        } else if(type_of_figure == 3){
            cout << "Enter octagon coordinates: \n";
            Figure* octagon = new Octagon(cin);
            figures.push_back(octagon);
        }


        std::cout << "Would you like to continue? \n";
        std::cout << "1 - Yes \n";
        std::cout << "0 - No \n";
        std::cin >> start;
    }
    double totalArea = 0.0;
    cout << "All elements of vector: \n";
    int Number_member_of_vector = 0;
    for (const auto& figure : figures){
        std::cout << Number_member_of_vector << '.';
        figure -> Print(cout);
        totalArea += figure -> Area();
        Number_member_of_vector++;
    }
    std::cout << "Area of all elements: " << totalArea << '\n';
    Number_member_of_vector = 0;
    totalArea = 0.0;
    std::cout << "Which element want to delete? \n";
    int IndexDelete;
    cin >> IndexDelete;
    if (IndexDelete >= 0 && IndexDelete < figures.size()) {
        delete figures[IndexDelete];
        figures.erase(figures.begin() + IndexDelete);
    }
    std::cout << "Vector after deleting: \n";
    for (const auto& figure : figures){
        std::cout << Number_member_of_vector << '.';
        figure -> Print(cout);
        totalArea += figure -> Area();
        Number_member_of_vector++;
    }
    std::cout << "Area of all elements after deleting: " << totalArea << '\n';
}