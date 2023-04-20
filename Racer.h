// header file for abstract base class
#include <string>
#pragma once

using namespace std;

class Racer { // class definition

  // protected fields
protected:
  int carNumber;
  double speed;
  double currentProgress;

  // public methods
public:
  int getCarNumber();
  double getSpeed();
  double getCurrentProgress();
  void resetProgress();
  virtual void makeProgress(double modifier) = 0; // virtual method to be overridden
  virtual string toString() = 0; // virtual method to be overridden
  Racer();


};
