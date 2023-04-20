// header file for CrumbledSegment
#include "RoadSegment.h"
#include <string>
#pragma once

using namespace std;

class CrumbledSegment : public RoadSegment { // inherited class

  // public methods
public:
  
  CrumbledSegment();
  RoadSegment* generateNeighbor();
  string toString();

};
