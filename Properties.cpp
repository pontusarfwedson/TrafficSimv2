/*
 * Car.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include <string>
#include <iostream>
using namespace std;

class Properties{
private:
	
public:

	static const int laneLength = 10; //Length of lane before it splits up into S and W
	static const int laneWSLength = 8; //Length of the lanes after it has been split up
	static const int lightPeriod = 14; //Total period of redlight
	static const int lightWestGreen = 6; //Green time on the light towards west
	static const int lightSouthGreen = 4; //Green time on the light towards south 
	static const float probStraight1 = 0.5; //Probability of a car going straight during interval 1
	static const float probStraight2 = 0.7; //Probability of a car going straight during interval 2
	static const float probWest1 = 0.5; //Probability of a car going west during interval 1
	static const float probWest2 = 0.6; //Probability of a car going west during interval 2
	Properties();
	virtual ~Properties();
	std::string stringify();
	void print();
};

Properties::Properties() {
	// TODO Auto-generated constructor stub

}

Properties::~Properties() {
	// TODO Auto-generated destructor stub
}


void Properties::print(){
	cout << "****** SETTINGS FOR LANES AND LIGHTS ******" << endl;
	cout << "Initial lane length: " << laneLength << endl;
	cout << "West/south lanes length: " << laneWSLength << endl;
	cout << "Total light period: " << lightPeriod << endl;
	cout << "Green time west: " << lightWestGreen << endl;
	cout << "Green time south: " << lightSouthGreen << endl;
	cout << " " << endl;
	cout << "******        PROBABILITIES         ******" << endl;
	cout << "Probability straight interval 1: " << probStraight1 << endl;
	cout << "Probability west interval 1: " << probWest1 << endl;
	cout << "Probability straight interval 2: " << probStraight2 << endl;
	cout << "Probability west interval 2: " << probWest2 << endl;
	cout << " " << endl;
	cout << " " << endl;
}

std::string Properties::stringify(){
	return "";
}

