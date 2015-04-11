#include <string>


//define couple parameters here for grooviness meter
#define INITIAL_DETECTION_RADIUS    200.0f
#define DETECTION_RADIUS_INCREASE   20.0f
#define DETECTION_RADIUS_DECREASE   6.0f
#define MIN_DETECTION_RADIUS 150.0f
#define MAX_DETECTION_RADIUS 400.0f
#define DETECTION_RADIUS_RANGE (MAX_DETECTION_RADIUS - MIN_DETECTION_RADIUS)

#pragma once
class GrooveMeter
{
public:
	GrooveMeter();
	~GrooveMeter();

	//the current detection radius
	float detectionRadius;

	void increaseRadius();
	void decreaseRadius();

	//Returns grooviness in range [0,1]
	float getGrooviness(){
		return (DETECTION_RADIUS_RANGE - (detectionRadius - MIN_DETECTION_RADIUS)) / DETECTION_RADIUS_RANGE;
	}

	std::string getGroovinessDisplay(float value);
};

