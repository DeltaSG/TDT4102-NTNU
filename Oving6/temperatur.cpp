#include <std_lib_facilities.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <istream>


#include "temperatur.h"

Temps::Temps(double max , double min): max{max} , min{min}{}
//Vet ikke hva jeg skal gjøre med denne eller hva den skal gjøre
/*
istream& operator>>(istream& is , Temps& t){
        is >> "t.max =  " >> t.max >> ", t.min = " >> t.min >> '\n';
        return is;
    }
*/
vector<pair<double,double>> readTemps(string filename){
    vector<pair<double,double>> vTemps;
    ifstream fileT(filename);
    string line;
    while(getline(fileT , line)) {
        string delimiter = " ";
        double max = stod(line.substr(0 , line.find(delimiter)));
        line.erase(0, line.find(delimiter) + delimiter.length());
        double min = stod(line);

        vTemps.push_back(pair(max, min));
    }
    return vTemps;
}

void tempStats(vector<pair<double,double>> vT){
    double currentMax = vT.at(0).first;
    double currentMin = vT.at(0).second;
    int cMax = 0;
    int cMin = 0;
    for (int i=0;i < vT.size(); i++)
    {
        if( currentMax < vT.at(i).first){
            currentMax = vT.at(i).first; 
            cMax = i;
        }
        if( currentMin > vT.at(i).second){
            currentMin = vT.at(i).second;
            cMin = i;
        }
}
cout << "Max temp: " << currentMax << ", at pos: " << cMax << endl;
cout << "Min temp: " << currentMin << ", at pos: " << cMin << endl;
}
