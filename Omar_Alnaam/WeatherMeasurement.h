#include "temperature.h"
#include "wind.h"
#ifndef WeatherMeasurement_h
#define WeatherMeasurement_h
using namespace std;

class WeatherMeasurement_t{
public:
	void read_weatherMeasurement(int language);
	void print_weatherMeasurement(WeatherMeasurement_t a ,int language);
private:
	 temperature_t temperature;
	 wind_t wind;

};

void getLanguage(int &language);
void getLanguage(int& size, int language);
void printTheHistory(string NameOfWeatherStation, int Temperature, int WindSpeed, string WindDirection);
void getSize(int& size, int language);
void PrintActions(int language);
void printTheCurrentOutput(string NameOfWeatherStation, int Temperature, int WindSpeed, string WindDirection);
#endif
