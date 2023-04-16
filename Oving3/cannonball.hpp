#pragma once

double acclY();
double velY(double initVelocityY , double time);
double posY(double initPositionY , double initVelocityY , double time);

double posX(double initPositionX , double initVelocityX , double time);

void printTime(double time); 
double flightTime(double initVelocityY);


//________________________________
// 4)

double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);

double getVelocityX(double theta , double absVelocity);
double getVelocityY(double theta , double absVelocity);

std::vector<double> getVelocityVector(double theta , double absVelocity);

double getDistanceTraveled(double velocityX , double velocityY);

double targetPractice(double distanceToTarget , double velocityX , double velocityY);

bool checkIfDistanceToTargetIsCorrect();

bool hit(double distanceToTarget , double velocityX , double velocityY);

int getRandomDistance();