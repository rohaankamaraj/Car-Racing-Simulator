// implementation file for SteadyRacer
#include "SteadyRacer.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;

SteadyRacer::SteadyRacer(int number) { // constructor
  carNumber = number;
  currentProgress = 0;
  speed = 3.4;
}

void SteadyRacer::makeProgress(double modifier) { // overridden method to calculate progress
  currentProgress += speed;
}

string SteadyRacer::toString() { // overridden method
  string str = "Racer #" + to_string(carNumber) + " Steady Car - " + to_string(currentProgress) + " units";
  return str;
}
