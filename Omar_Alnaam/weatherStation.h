#pragma once
#include <string>
#include<list>
#include "WeatherMeasurement.h"
#include "StringServer.h"

class weatherStation
{
public:
	weatherStation();
	void manageWeatherStation(int language, string nameOfWeatherStation);
	void printCurrentForAllWeatherStation(int language, string nameOfWeatherStation);
	~weatherStation();
	
private: 
	bool isStringNull;
	int size;
	list<WeatherMeasurement_t> l1;
	//StringServer myStringServer;
	WeatherMeasurement_t weather;
	StringServer mystringServer;
};

