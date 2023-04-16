#include "std_lib_facilities.h"
#include <cmath>
#include <AnimationWindow.h>
//------------------------------------------------------------------------------'

// b)
void inputAndPrintInteger(){
    cout << "Skriv inn et tall: " << endl;
    int integer = 0;
    cin >> integer;
    cout << "Du skrev: " << integer << endl;
}
// c)
int inputInteger(){
    cout << "Skriv inn et tall: ";
    int heltall = 0;
    cin >> heltall;
    return heltall;
}
// d)
void inputIntegersAndPrintSum(){
    int number_1 = inputInteger();
    int number_2 = inputInteger();

    cout << "The sum is: " << number_1 + number_2 << endl;
}
// e) heltallet fra oppgave b blir ikke lagret og kan derfor ikke itereres over. derfor lettere å benyttse seg av oppgave c.

// f) 
int isOdd(int n){
    if((n % 2) == 1) {
        return true;
    } else {
        return false;
    }
}

// g)
void printHumanReadableTime(){
    cout << "Skriv inn antall sekunder: ";
    int tid_i_sekunder = 0;
    cin >> tid_i_sekunder;
    int timer = (tid_i_sekunder - tid_i_sekunder % 3600) / 3600;
    tid_i_sekunder = tid_i_sekunder % 3600;
    int minutter = (tid_i_sekunder - tid_i_sekunder % 60) / 60;
    tid_i_sekunder = tid_i_sekunder % 60;
    cout << timer << ": Timer " << minutter << ": Minutter " << tid_i_sekunder << ": Sekunder" << endl;
    
}
//2 a)
int SumAvHeltall(){
    cout << "Hvor mange tall skal summeres: ";
    int n = 0; //antall nummer som skal summes
    cin >> n;
    int sum = 0; //summen
    for(int x = 0; x < n; ++x) {
        int k = inputInteger();
        sum += k;
    }
    cout << "Summen er: " << sum << endl;
    return sum;
}
//2 b)
int SumAvIkkeNull(){
    cout << "Skriv inn første nummer: ";
    int nummer = 0;
    cin >> nummer;
    int sum = 0;
    while(nummer != 0) {
        sum += nummer;
        cout << "Skriv inn det nye nummeret: ";
        cin >> nummer;
    }
    cout << "Summen er: " << sum << endl;
    return sum;
}
// 2 c) I oppgave a er det bedre å bruke en for løkke siden vi vet hvor mange iterasjoner man skal ha.
//      I oppgave b er det bedre med while siden vi ikke vet hvor mange iterasjoner det skal være.

//2 d) 
int inputDouble(){
    double verdi = 0;
    cout << "Skriv in et tall: ";
    cin >> verdi;
    cout << "Du skrev inn: " << verdi;

    return verdi;
}

//2 e)
int NOKtilEuro(){
    cout << "Skriv inn hvor mange kroner du skal veksle inn: ";
    double NOK = 0;
    cin >> NOK;

    while(NOK < 0) {
        cout << "Du må skrive inn positivt antall kroner!" << endl;
        cout << "Skriv in antall kroner: ";
        cin >> NOK;
    }
    double konvergeringsRate = 1 / 9.75;
    double Euro = NOK * konvergeringsRate;

    cout << NOK << "kr er lik: " << Euro << "Euro" << endl;
    return Euro;
}
// 2 f) siden vi skal gange et tall med et flyttal er det greit å definere alt som double for å unngå feil. 

// 2 g)
void gangeTabell(int lengde , int bredde) {
    for(int i = 1; i < lengde+1; i++) {
        for(int j = 1; j < bredde+1; j++) {
            cout << setw(4) <<(i * j);
        }
        cout << endl;
    }
}
// 3 funksjoner i funksjoner 
int discriminant(double a , double b, double c) {
    return((pow(b,2) - (4 * a * c)));
}
void printRealRoots(double a, double b, double c){
    double temp = discriminant(a,b,c);
    if(temp < 0) {
        cout << "No real solutions" << endl;
    } else if(temp == 0) {
        cout << "The solution is: x = " << (-b)/(2*a) << endl;
    }else {
        cout << "Solution #1: x = " << (-b + sqrt(temp)) /(2*a) << endl;
        cout << "Solution #2: x = " << (-b - sqrt(temp)) /(2*a) << endl;
    }
}

void solveQuadraticEquation(){
    cout << "Enter values for a, b and c: ";
    double a =0 , b = 0, c=0;
    cin >> a >> b >> c;
    printRealRoots(a,b,c);
}



// a)
int main() {

    int valg = -1;
    while(valg != 0) {
        cout << ("\n Velg en funksjon: ") << endl;
        cout << "0) Avslutt" << endl;
        cout << "1) Print heltall" << endl;
        cout << "2) Print heltall og lagre variabel" << endl;
        cout << "3) Print sum av to heltall" << endl;
        cout << "4) Oddetallstest" << endl;
        cout << "5) Tid fra sek til t:m:s" << endl;
        cout << "6) Summ av n antall heltall" << endl;
        cout << "7) Summ av tall til du skriver 0" << endl;
        cout << "8) Print ut et flyttall" << endl;
        cout << "9) Konverter fra NOK til Euro" << endl;
        cout << "10) Gangetabell (lengde, bredde)" << endl;
        cout << "11) Losning av abc formel" << endl;



        cin >> valg;
        if(valg == 1){
            inputAndPrintInteger();

        }else if(valg == 2){
            inputInteger();
        }else if(valg == 3) {
            inputIntegersAndPrintSum();
        }else if(valg == 4) {
            cout << (isOdd(inputInteger()) ? "true" : "false");
        }else if(valg == 5) {
            printHumanReadableTime();
        }else if (valg == 6) {
            SumAvHeltall();
        }else if (valg == 7) {
            SumAvIkkeNull();
        }else if (valg == 8) {
            inputDouble();
        }else if (valg == 9){
            NOKtilEuro();
        }else if(valg == 10) {
            int a = 0;
            int b = 0;
            cout << "Skriv inn lengde og bredde: ";
            cin >> a >> b;
            gangeTabell(a,b);

        }else if(valg == 11) {
            solveQuadraticEquation();
        }
        else(valg = 0);
    }
    return 0;
}

//------------------------------------------------------------------------------
