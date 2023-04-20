// header file for ToughRacer
#include "Racer.h"
#include <string>
#pragma once

using namespace std;

class ToughRacer : public Racer { // inherited class

  // public methods
public:
  ToughRacer(int);
  void makeProgress(double modifier);
  string toString();

};
