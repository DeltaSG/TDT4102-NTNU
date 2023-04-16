#include <std_lib_facilities.h>
#include <AnimationWindow.h>
#include <cannonball.hpp>

double acclY() {
    double acc = -9.81;
    return acc;
}
double velY(double initVelocityY , double time) {
    double vel_y = initVelocityY + (time * acclY());
    return vel_y;
}
double posY(double initPositionY , double initVelocityY , double time) {
    double pos_y = initPositionY + (initVelocityY * time) +((acclY()/2) * pow(time , 2));
    return pos_y;
}

double posX(double initPositionX , double initVelocityX , double time) {
    double pos_x = initPositionX + (initVelocityX *time);
    return pos_x;
}

void printTime(double time) {
    int intTime = static_cast<int>(time);

    int timer = (intTime - intTime % 3600) / 3600;
    int initTime     = intTime % 3600;
    int minutter = (intTime - intTime % 60) / 60;
    double tid_i_sek = intTime % 60 + (time - initTime);

    cout << timer << ": Timer " << minutter << ": Minutter " << tid_i_sek << ": Sekunder" << endl;
}

double flightTime(double initVelocityY) {
    double time = -2 * (initVelocityY / acclY());
    return time;
}


//__________________
// 4)

double getUserInputTheta() {
    double grader = 0;
    cout << "Skriv inn vinkel i grader: ";
    cin >> grader;

    return grader;    
}

double getUserInputAbsVelocity() {
    double absVelocity = 0;
    cout << "Skriv inn hastigheten: ";
    cin >> absVelocity;

    return absVelocity;    
}

double degToRad(double deg) {
    const double pi = 3.1415;
    double rad = deg * (pi /180);
    return rad;
}

double getVelocityX(double theta , double absVelocity) {
    double velocityX = absVelocity * cos(degToRad(theta));
    return velocityX;
}

double getVelocityY(double theta , double absVelocity) {
    double velocityY = absVelocity * sin(degToRad(theta));
    return velocityY;
}

vector<double> getVelocityVector(double theta , double absVelocity) {
    vector<double> velocityVector{getVelocityX(theta , absVelocity),getVelocityY(theta , absVelocity)};
    return velocityVector; 
}

double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    double distance = posX(0 , velocityX , time);
    return distance;
}

double targetPractice(double distanceToTarget , double velocityX , double velocityY) {
    double distance = getDistanceTraveled(velocityX , velocityY);
    int error = static_cast<int>(abs(distanceToTarget - distance));
    return error;
}


bool checkIfDistanceToTargetIsCorrect() { //rar kode som ikke lar seg iterere over!
    double error = targetPractice(100,0,0);
    if(error ==0) return true;
    else {
        return false;
    }
}

bool hit(double distanceToTarget , double velocityX , double velocityY) { //Does the same as the one over (4e))
    double maxError = 5; // er gavmild i dag ;) 
    double distance = getDistanceTraveled(velocityX , velocityY);
    double metersOff = abs(distanceToTarget - distance);
    if(metersOff <= maxError) {
        return true;
    }else{
        return false;
    }
}
