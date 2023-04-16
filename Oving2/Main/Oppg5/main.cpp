#include "std_lib_facilities.h"


vector<int> calculateBalance(double innskudd, int rente, int aar) {
    vector<double> saldoDouble(0);
    double effektivRente = (1 + (static_cast<double>(rente)/100));
    for(int i=0; i<aar+1 ; i++) {
        saldoDouble.push_back(innskudd *(pow(effektivRente, i)));
    }
    vector<int> saldo(aar +1);
    for(int j=0; j < aar+1; j++) {
        saldo.at(j) = static_cast<int>(saldoDouble.at(j));
    }
    return saldo;
}

void printBalance(vector<int> balance){
    cout << "AAr" << setw(6) << "Saldo" << endl;
    int j = balance.size();
    for(int i = 0; i < j; i++) {
        cout <<i <<  setw(7) << balance.at(i) << endl;
    }
}

int main() {
    vector<int> a =calculateBalance(5000, 3, 5);
    printBalance(a);
    return 0;
}

//------------------------------------------------------------------------------
