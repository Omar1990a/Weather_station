#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <new>
#include <stdlib.h> 
#include "temperature.h"
#include "StringServer.h"
#include <fstream>
#include "LineNumber.h"
using namespace std;



void temperature_t::read_temperature(int language){
	getTemperature(dgree, language);
	
}

void temperature_t::print_temperature(temperature_t t,int language){
	StringServer myStringServer;
	if (language == 1)
	{
		myStringServer.language("english.txt");
	}
	else{
		myStringServer.language("PigLatin.txt");
	}
	cout << myStringServer.getString(lineten) << "  " << t.dgree << " " << myStringServer.getString(lineeleven) << endl;

	//cout << "The temperature is : " << dgree << "F" <<endl;

}



void getTemperature(int& Temperature, int language)
{

	StringServer myStringServer;
	if (language == 1)
	{
		myStringServer.language("english.txt");
	}
	else{
		myStringServer.language("PigLatin.txt");
	}
	bool checkInput = true;
	cout << myStringServer.getString(lineeight);
	//cout << "Enter temperature in degrees Fahrenheit(hint:an intger between -150 to +244):";
	while (checkInput == true)
	{
		cin >> Temperature;
		// check the input if has letter,simple or less than -150 or greater than 244 because this is maximum degree.
		// if it has invalid input print invalid value 
		if (cin.fail() || cin.peek() != '\n' || Temperature < -150 || Temperature > 244)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//cout << "invalid value" << endl;
			//cout << "Enter degrees Fahrenheit between -150 to +244 ...  : ";
			cout << myStringServer.getString(linenine);

		}
		else{
			checkInput = false;
		}
	}
	

}