// header file for StreetRacer
#include "Racer.h"
#include <string>
#pragma once

using namespace std;

class StreetRacer : public Racer { // inherited class

  //public methods
public:
  StreetRacer(int);
  void makeProgress(double modifier);
  string toString();

};
