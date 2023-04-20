// header file for AsphaltSegment
#include "RoadSegment.h"
#include <string>
#pragma once

using namespace std;

class AsphaltSegment : public RoadSegment { // inherited class 

  // public methods
public:

  AsphaltSegment();
  RoadSegment* generateNeighbor();
  string toString();

};
