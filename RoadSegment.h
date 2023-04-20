// header file for abtract base class
#include <string>
#pragma once

using namespace std;

class RoadSegment { // class definition

  // protected fields
protected:
  int length;
  double modifier;
  
  // public methods
public:
  virtual RoadSegment* generateNeighbor() = 0; // virtual method to be overridden
  int getLength();
  double getModifier();
  RoadSegment();
  virtual string toString() = 0; // virtual method to be overriden

};
