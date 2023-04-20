// implementation file for CrumbledSegment
#include "GravelSegment.h"
#include "AsphaltSegment.h"
#include "DirtSegment.h"
#include "CrumbledSegment.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;


GravelSegment::GravelSegment() { // default constructor
  modifier = 0.5;
}

RoadSegment* GravelSegment::generateNeighbor() { // overridden method to generate next segment
  
  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(1,100);
  random = generate(gen);

  if (random >= 1 && random <= 50) {
    RoadSegment* segment = new GravelSegment();
    return segment;
  } else if (random > 50 && random <= 85) {
    RoadSegment* segment = new DirtSegment();
    return segment;
  } else if (random > 85 && random <= 95) {
    RoadSegment* segment = new CrumbledSegment();
    return segment;
  } else if (random >95 && random <= 100) {
    RoadSegment* segment = new AsphaltSegment();
    return segment;
  }
  
  RoadSegment* segment = new GravelSegment();
  return segment;

}

string GravelSegment::toString() { // overridden method
  
  string str = "Gravel - " + to_string(length) + " units ";
  return str;

}
