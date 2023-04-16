#pragma once
#include <std_lib_facilities.h>
#include <iostream>
#include <fstream>
#include <vector>

class Temps {
    private:
    double max;
    double min;

    public:
    Temps(double max , double min);
  
    

    friend istream& operator>>(istream& is , Temps& t);
};

vector<pair<double,double>> readTemps(string filename);
void tempStats(vector<pair<double,double>> vT);