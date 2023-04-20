// implementation file for abstract base class
#include "Racer.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Racer::Racer() { // default constructor
  carNumber = 0;
  speed = 0;
  currentProgress = 0;
}


int Racer::getCarNumber() { // getter
  return carNumber;
}

double Racer::getSpeed() { // getter
  return speed;
}

double Racer::getCurrentProgress() { //getter
  return currentProgress;
}

void Racer::resetProgress() { // resets currentProgress
  currentProgress = 0.0;
}
