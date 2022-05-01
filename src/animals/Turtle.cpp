#include "Turtle.hpp"

int Turtle::getDirection(){
    if(rand() % 4 == 0){
        return rand() % 4;
    }
    return -1;
}