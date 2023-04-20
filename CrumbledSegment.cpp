// implementation file for CrumbledSegment
#include "CrumbledSegment.h"
#include "AsphaltSegment.h"
#include "DirtSegment.h"
#include "GravelSegment.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>

using namespace std;

CrumbledSegment::CrumbledSegment() { // default constructor
  modifier = 0.7; 
}

RoadSegment* CrumbledSegment::generateNeighbor() { // overridden method to generate the next segment

  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(1,100);
  random = generate(gen);

  if (random >= 1 && random <= 40) {
    RoadSegment* segment = new CrumbledSegment();
    return segment;
  } else if (random > 40 && random <= 65) {
    RoadSegment* segment = new AsphaltSegment();
    return segment;
  } else if (random > 65 && random <= 90) {
    RoadSegment* segment = new GravelSegment();
    return segment;
  } else if (random > 90 && random <= 100) {
    RoadSegment* segment = new DirtSegment();
    return segment;
  }
  
  RoadSegment* segment = new CrumbledSegment();
  return segment;

}

string CrumbledSegment::toString() { // overridden method
  string str = "Crumbled - " + to_string(length) + " units ";
  return str;
}
