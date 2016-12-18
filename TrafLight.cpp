/*
 * Light.cpp
 *
 *  Created on: 14 nov 2016
 *      Author: PontusArfwedson
 */

#include "TrafLight.h"



/**
 * Constructors and destructors
 */
TrafLight::TrafLight(int pperiod, int ggreen){
	time = 0;
	period = pperiod;
	green = ggreen;
}

TrafLight::TrafLight() {
	// TODO Auto-generated constructor stub
	time = 0;
	period = 10;
	green = 5;
}

TrafLight::~TrafLight() {
	// TODO Auto-generated destructor stub
}


/**
 * Public methods
 */
int TrafLight::getTime(){
	return time;
}

void TrafLight::step(){
	time = (time + 1)%period;
}
bool TrafLight::isGreen(){
	return time < green;
}

std::string TrafLight::stringify(){
	if(isGreen()){
		return "(G)";
	}
	else{
		return "(R)";
	}
}

// int main(){
// 	Light * lightW = new Light(5, 3);
// 	Light * lightS = new Light(5, 2);
// 	for (int i=0; i<12; i++) {
// 		std::cout << "***************************" << std::endl;
// 		std::cout << i << ":  (5,3): " << lightW->stringify() << "  (5,2): " << lightS->stringify() << std::endl;
// 		std::cout << i << ":  (5,3): " << lightW->getTime() << "  (5,2): " << lightS->getTime() << std::endl;
// 		std::cout << "***************************" << std::endl;
// 		lightW->step();
// 		lightS->step();
// 	}
// 	return 0;
// }

/* namespace light */
