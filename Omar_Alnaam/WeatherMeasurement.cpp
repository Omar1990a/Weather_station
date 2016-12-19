//Omar ALnaam
// Project 5 
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <new>
#include <stdlib.h> 
#include "WeatherMeasurement.h"
#include "StringServer.h"
#include <fstream>
#include "LineNumber.h"
using namespace std;


void WeatherMeasurement_t::read_weatherMeasurement(int language)
{
	
	temperature.read_temperature(language);
	wind.read_wind(language);
	
}


void WeatherMeasurement_t::print_weatherMeasurement(WeatherMeasurement_t a, int language)
{
	
	temperature.print_temperature(a.temperature,language);
	wind.print_wind(a.wind,language);
}





void printTheHistory(string NameOfWeatherStation, int Temperature, int WindSpeed, string WindDirection)
{
	cout << "\nThe " << NameOfWeatherStation << " Weather Station" << endl
		<< "The temperature is : " << Temperature << " degrees Fahrenheit" << endl
		<< "The wind speed and direction : " << WindSpeed << "MPH" << " " << WindDirection << endl;

}


void getSize(int& size, int language)
{
	bool checkInput = true;
	StringServer myStringServer;
	
	if (language == 1)
	{
		myStringServer.language("english.txt");
	}
	else{
		myStringServer.language("PigLatin.txt");
        }
	
	cout << myStringServer.getString(lineone);
	//cout << "Enter the size number of the history measurement: ";
	while (checkInput == true)
	{

		cin >> size;
		// check the input if has letter,simple or grater 0 or less than 10000000 because this is maximum for memory in my computer.
		// if it has invalid input  print invalid value 
		if (cin.fail() || cin.peek() != '\n' || size <1 || size>10000000)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << myStringServer.getString(lineTwo);
			//cout << "invalid value" << endl;
			//cout << "Enter size number grater 0 or less than 10000000 : ";
		}
		else{
			checkInput = false;
		}
	}
}
void getLanguage(int &language)
{
	
	bool checkInput = true;
	while (checkInput == true)
	{

		cin >> language;
		// check the input if has letter,simple or grater 0 or less than 10000000 because this is maximum for memory in my computer.
		// if it has invalid input  print invalid value 
		if (cin.fail() || cin.peek() != '\n' || language <1 || language>2)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "invalid value" << "Invalidway alue ";
			
		}
		else{
			checkInput = false;
		}
	}
}

void PrintActions(int language)
{

	StringServer myStringServer;
	if (language == 1)
	{
		myStringServer.language("english.txt");
	}
	else{
		myStringServer.language("PigLatin.txt");
	}


	cout << myStringServer.getString(lineThree) << endl;
	cout << myStringServer.getString(linefour) << endl;
	cout << myStringServer.getString(linefive) << endl;
	cout << myStringServer.getString(linesix) << endl;
	cout << myStringServer.getString(lineseven) << endl;
	//cout << " \nSelect and enter one number from the following (hit: Ex 1) : " << endl
		//<< "\n1-Input a complete weather reading:temperature, wind speed, and wind direction." << endl
		//<< "2- Print the current weather." << endl
		//<< "3- Print the weather history." << endl
		//<< "4- Exit the program." << endl;

}
void printTheCurrentOutput(string NameOfWeatherStation, int Temperature, int WindSpeed, string WindDirection)
{

	cout << "\n\t**************" << endl
		<< "\nThe " << NameOfWeatherStation << " Weather Station" << endl
		<< "The current temperature is : " << Temperature << " degrees Fahrenheit" << endl
		<< "The current wind speed and direction : " << WindSpeed << "MPH" << " " << WindDirection << endl
		<< "\n\t**************" << endl;
}



