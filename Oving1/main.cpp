#include <std_lib_facilities.h>


void maxOfTwo(int a , int b) {
    if( a >  b) {
        cout << "A Is greater than B" << endl;
    } else {
        cout << "B Is greater than or equal to A" << endl;
    }
}


int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << " Fibonacci Numbers: " << endl;
    for (int x = 1; x < n +1; ++x) {
        cout << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for(int i = 1; i<n+1; ++i) {
        totalSum += pow(i,2);
        cout << pow(i,2) << endl;
    }
    cout << "----" << endl;
    cout << totalSum << endl;
    return totalSum;
}


void triangleNumersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while(acc < n) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
}


int isPrime(int n) {
    int prime = 1;
    for(int j = 2; j < n; j++) {
        if ((n%j) == 0) {
            prime = 0;
        }
    }
    return prime;
}


void naivePrimeNumberSearch(int n) {
    for (int num = 2; num < n+1; num++) {
        if (isPrime(num)==1) {
            cout << num << " is a prime" << endl;
        }
    }
}

int findGreatestDivisor(int n) {
    for(int div = (n-1); div > 0; --div) {
        if((n%div)== 0) {
            return div;
        }
    }
    return 0;
}

int main(){
    
    cout << "Oppgave 2 a og b)" << endl;
    maxOfTwo(5,6);
    
    cout << "Oppgave 2c)" << endl;
    cout << fibonacci(8) << endl;

    cout << "Oppgave 2d)" << endl;
    cout << squareNumberSum(8) << endl;
    
    cout << "Oppgave 2e)" << endl;
    triangleNumersBelow(14);

    cout << "Oppgave 2 f og g)" << endl;
    naivePrimeNumberSearch(14);
    
    cout << "Oppgave 2h)" << endl;
    cout << findGreatestDivisor(14) << endl;

    return 0;
}