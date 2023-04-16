#include <std_lib_facilities.h>
#include <utuilities.hpp>
#include <cannonball.hpp>
#include "cannonball_viz.h"

int randomWithLimits(int lowerLimit , int  upperLimit) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(lowerLimit , upperLimit);

    double number = distribution(generator);
    int intNumber = static_cast<int> (number);
    return intNumber;
}

void playTargetPractice(){
    int distanceToTarget = randomWithLimits(100 , 1000); //min og max lengde.

 

    for (int counter=0; counter<10; counter++) {
        double deg = getUserInputTheta();
        double absVelocity = getUserInputAbsVelocity();

         double velocityX = getVelocityX( deg , absVelocity);
         double velocityY = getVelocityY(deg , absVelocity);
        

        if(hit(distanceToTarget, velocityX , velocityY)){
            cout << "Flight time is: ";
            printTime(flightTime(velocityY));
            cannonBallViz(distanceToTarget , 1000 , velocityX , velocityY , 100);
            cout << "\nDistance traveled is: " << getDistanceTraveled(velocityX , velocityY) << endl;
            cout << "Distace to target is: " << targetPractice(distanceToTarget , velocityX , velocityY) <<" meters" << endl;
            cout << "Hit congratulations!!" << endl;
            return;
        }else{
            cout << "Flight time is: ";
            printTime(flightTime(velocityY));
            cannonBallViz(distanceToTarget , 1000 , velocityX , velocityY , 100);
            cout << "\nDistance traveled is: " << getDistanceTraveled(velocityX , velocityY) << endl;
            cout << "Target at: " << distanceToTarget << endl;
            cout << "Distace to target is: " << targetPractice(distanceToTarget , velocityX , velocityY) <<" meters" << endl;
            cout<< "Miss, try again." << endl;
        }




    }
    cout << "Du var ikke mye treffsikker...." << endl;
    return;
}