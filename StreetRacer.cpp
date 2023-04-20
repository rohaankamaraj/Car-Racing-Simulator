// implementation file for StreetRacer
#include "StreetRacer.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;

StreetRacer::StreetRacer(int number) { // constructor
  carNumber = number;
  currentProgress = 0;
  speed = 6.3;
}

void StreetRacer::makeProgress(double modifier) { // overridden method to calculate progress
  currentProgress += (speed * modifier) + 0.5;
}

string StreetRacer::toString() { // overridden method
  string str = "Racer #" + to_string(carNumber) + " Street Car - " + to_string(currentProgress) + " units";
  return str;
}
