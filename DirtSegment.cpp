// implementation file for DirtSegment
#include "DirtSegment.h"
#include "AsphaltSegment.h"
#include "GravelSegment.h"
#include "CrumbledSegment.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;


DirtSegment::DirtSegment() { // default constructor
  modifier = 0.2;
}

RoadSegment* DirtSegment::generateNeighbor() { // overridden method to generate next segment

  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(1,100);
  random = generate(gen);
  
  if (random >= 1 && random <= 60) {
    RoadSegment* segment = new DirtSegment();
    return segment;
  } else if (random > 60 && random <= 90) {
    RoadSegment* segment = new GravelSegment();
    return segment;
  } else if (random > 90 && random <= 95) {
    RoadSegment* segment = new CrumbledSegment();
    return segment;
  } else if (random > 95 && random <= 100) {
    RoadSegment* segment = new AsphaltSegment();
    return segment;
  }
  
  RoadSegment* segment = new DirtSegment();
  return segment;

}

string DirtSegment::toString() { // overridden method

  string str = "Dirt - " + to_string(length) + " units ";
  return str;

}
