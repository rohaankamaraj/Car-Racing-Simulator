// implementation file for ToughRacer
#include "ToughRacer.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;

ToughRacer::ToughRacer(int number) { // constructor
  carNumber = number;
  currentProgress = 0;
  speed = 2.5;
}

void ToughRacer::makeProgress(double modifier) { // overridden method to calculate progress
  double bonusSpeed = 5 * (1.0 - modifier);
  currentProgress += speed + bonusSpeed;
}

string ToughRacer::toString() { // overridden method
  string str = "Racer #" + to_string(carNumber) + " Tough Car - " + to_string(currentProgress) + " units";
  return str;
}
