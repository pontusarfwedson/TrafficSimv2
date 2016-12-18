/*
 * Vehicle.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <string>
#include "Car.h"
using namespace std;

//Default constructor
Car::Car() {
	// TODO Auto-generated constructor stub
}

Car::Car(char ddest){
	destination = ddest;
	bornTime = 0;
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

int Car::getTime(){
	return bornTime;
}
char Car::getDestination(){
	return destination;
}
std::string Car::stringify(){
	return string(1, destination);
}
