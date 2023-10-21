#include <iostream>
#include "chocolate.h"

int main(){
    int length, width;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Output: " << chocolate(length, width) << std::endl;
}