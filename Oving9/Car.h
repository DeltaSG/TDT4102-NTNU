#pragma once

class Car{
    private: 
        int freeSeats;

    public:
        Car(int seats): freeSeats{seats} {};
        bool hasFreeSeats() const;
        void reserveFreeSeats();
};