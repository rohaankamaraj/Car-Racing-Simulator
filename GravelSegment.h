// header file for GravelSegment
#include "RoadSegment.h"
#include <string>
#pragma once

using namespace std;

class GravelSegment : public RoadSegment { // inherited class

  //public methods
public:
  
  GravelSegment();
  RoadSegment* generateNeighbor();
  string toString();

};
