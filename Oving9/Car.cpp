#include "Car.h"
#include <iostream>

bool Car::hasFreeSeats() const{
    if (freeSeats > 0) {
        return true;
    }else{
        return false;
    } 
}

void Car::reserveFreeSeats() {
    freeSeats--;
}