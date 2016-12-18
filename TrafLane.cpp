/*
 * Lane.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "TrafLane.h"
#include "Car.h"
#include <vector>
#include <algorithm>
#include <cstddef>

#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <iostream>
using namespace std;

TrafLane::TrafLane() {
}
TrafLane::TrafLane(int length) {
	// TODO Auto-generated constructor stub
  //std::fill(theLane.begin(),theLane.begin()+length, NullVehicle());;
  theLane.resize(length);
  std::fill(theLane.begin(),theLane.begin()+length, Car(' '));
}

std::string TrafLane::stringify() {
  std::string res = "";
  for (int i= 0; i<theLane.size(); i++) {
    res += theLane[i].stringify();
  }
  return "<" + res + ">";
}

// void Lane::step() {
//  for (int i = 1; i<theLane.size(); i++) {
//     if(theLane[i-1].isNull() ) {
//       theLane[i-1] = theLane[i];
//       NullVehicle temp;
//       theLane[i]   = temp;
//     }
//   }
// }

//without using NullVehicle
void TrafLane::step() {
 for (int i = 1; i<theLane.size(); i++) {
    if(theLane[i-1].getDestination() == ' ') {
      theLane[i-1] = theLane[i];
      Car temp = Car(' ');
      theLane[i]   = temp;
    }
  }
}

// Vehicle Lane::removeFirst() {
//   Vehicle result = theLane[0];
//   NullVehicle temp;
//   theLane[0] = temp;
//   return result;
// }

//using without NullVehicle
Car TrafLane::removeFirst() {
  Car result = theLane[0];
  Car temp = Car(' ');
  theLane[0] = temp;
  return result;
}
Car TrafLane::getFirst() {
  return theLane[0];
}

bool TrafLane::lastFree() {
  //return theLane[theLane.size()-1].isNull();
  // I do not want to use NullVehicle class
  return theLane[theLane.size()-1].getDestination() == ' ';
}

void TrafLane::putLast(Car v) {
    theLane[theLane.size()-1] = v;
}

TrafLane::~TrafLane() {
	// TODO Auto-generated destructor stub
}

// int main() {
//   srand(time(0));
//   Lane lane = Lane(10);
//
//   for (int i = 0; i<20; i++) {
//     if (lane.getFirst().getDestination() != ' ') {
//       cout << "Out from lane: " << lane.removeFirst().stringify() << endl;
//     }
//     lane.step();
//     if ((rand()%11)/10.0<0.5) {
//       lane.putLast(Vehicle('x'));
//     }
//     cout << lane.stringify() << endl;
//   }
//   cout << endl;
//   if (lane.lastFree()) {
//     lane.putLast(Vehicle('y'));
//     cout << lane.stringify() << endl;
//   }
//   cout << "Time to crash!" << endl;
//   lane.putLast(Vehicle('z'));
// }
