// header file for SteadyRacer
#include "Racer.h"
#include <string>
#pragma once

using namespace std;

class SteadyRacer : public Racer { // inherited class

  // public methods
public:
  SteadyRacer(int);
  void makeProgress(double modifier);
  string toString();

};
