// implementation class for Race
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Race.h"
#include "Racer.h"
#include "StreetRacer.h"
#include "SteadyRacer.h"
#include "RoadSegment.h"
#include "AsphaltSegment.h"
#include "CrumbledSegment.h"
#include "GravelSegment.h"
#include "DirtSegment.h"
#include <random>

using namespace std;

// default constructor
Race::Race() {

  // This block of code is to introduce the user to the race, and determine the length of the race
  srand((unsigned) time(0));
  raceLength = rand() % (50 - 10 + 1) + 10;

  cout << "Welcome to the Racer Derby!" << endl;
  cout << "Would you like to: " << endl;
  cout << "1 - Determine the length of the race" << endl;
  cout << "2 - Run a random race" << endl;
  cout << "-1 - Exit" << endl;
 
  int choice;
  cin >> choice;

  if (choice == 1) {
    cout << "Okay! Enter the length you want to be for the race: ";
    int userLength;
    cin >> userLength;
    raceLength = userLength;
    cout << endl;
  }

  // This block of code is to randomly decide the Racers
  int tracker = 0;
  
  random_device random;
  mt19937 gen(random());
  uniform_int_distribution<> generate(1,3);
  
  while (tracker < 8) {  

    int random = generate(gen);

    if (random == 1) {
      Racer* sr = new StreetRacer(tracker + 1);
      racers[tracker] = sr;
    } else if (random == 2) {
      Racer* sr = new SteadyRacer(tracker + 1);
      racers[tracker] = sr;
    } else if (random == 3) {
      Racer* sr = new ToughRacer(tracker + 1);
      racers[tracker] = sr;
    }

    tracker++;
  }

}

// this method prints out an aesthetic divider for each update
void Race::outputDivider(int update) {

  cout << "#######################################" << endl;
  cout << "Update " + to_string(update) + "!" << endl;
  cout << "----------" << endl;
}

// this method will actually simulate the race itself
void Race::runRace() {
  RoadSegment* segments[raceLength]; // creates the strip of segments
  segments[0] = new AsphaltSegment(); 

  // generates the track of segments

  for (int i = 1; i < raceLength; i++) {
    segments[i] = segments[i-1]->generateNeighbor();
  }

  // print the track out

  cout << "Track:" << endl;
  int littleCounter = 0;

  for (int i = 0; i < raceLength; i++) {
    littleCounter++;    
    if (segments[i]->toString() == ("Asphalt - " + to_string(segments[i]->getLength()) + " units ")) {
      cout << "A: " + to_string(segments[i]->getLength());
    } else if (segments[i]->toString() == ("Crumbled - " + to_string(segments[i]->getLength()) + " units ")) {
      cout << "C: " + to_string(segments[i]->getLength());
    } else if (segments[i]->toString() == ("Gravel - " + to_string(segments[i]->getLength()) + " units ")) {
      cout << "G: " + to_string(segments[i]->getLength());
    } else if (segments[i]->toString() == ("Dirt - " + to_string(segments[i]->getLength()) + " units ")) {
      cout << "D: " + to_string(segments[i]->getLength());
    }

    if (littleCounter != raceLength) {
      cout << " - ";
    }
    
  }

  cout << endl;

  bool noWinner = true;  
  int counter = 0;
  int winnerIndex = 0;
  
  // this while loop simulates the race
  
  while (noWinner) {

    counter++;
    // this is to check if the racer made it to the next segment and if there is a winner
    for (int i = 0; i < 8; i++) {
      if (racers[i]->getCurrentProgress() >= segments[segmentTracker[i]]->getLength()) {
	racers[i]->resetProgress();
	segmentTracker[i]++;
	if (segmentTracker[i] >= raceLength) {
	  winnerIndex = i;
	  noWinner = false;
	  break;
	}
      }
    }
    // if there was a winner, then exit the while loop
    if (segmentTracker[winnerIndex] >= raceLength) {
      break;
    }
    
    // this is to progress the racers
    for (int i = 0; i < 8; i++) {
      racers[i]->makeProgress(segments[segmentTracker[i]]->getModifier());
    }
    
    // output racers

    for (int i = 0; i < 8; i++) {
      cout << racers[i]->toString() << endl;
    }

    // call the outputDivider method

    outputDivider(counter);    
  
  }

  // output the winner
  
  cout << "The winner of this race is Racer #";
  cout << racers[winnerIndex]->getCarNumber();
  cout << "! Congratulations!" << endl;
 
}
  

