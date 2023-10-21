#include "chocolate.h"

int chocolate(int length, int width){
    int count_division = 0;
    if (length > 0 && width > 0){
        count_division = (length * width) - 1;
    }
    return count_division;
} 