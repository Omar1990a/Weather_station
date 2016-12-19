
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <new>
#include <stdlib.h> 
#include "wind.h"
#include "StringServer.h"
#include <fstream>
#include "LineNumber.h"
using namespace std;

void wind_t::read_wind(int language){
	getWindSpeed(Speed,language);
	getWindDirection(Direction, language);
}


void wind_t::print_wind(wind_t w ,int language){
	StringServer myStringServer;
	if (language == 1)
	{
		myStringServer.language("english.txt");
	}
	else{
		myStringServer.language("PigLatin.txt");
	}

	cout << myStringServer.getString(linesixteen) <<" " <<w.Speed << myStringServer.getString(lineseventeen) << " " << w.Direction<<endl;


	//cout << "The wind speed and direction : " << Speed << "MPH" << " " << Direction << endl;


}

void getWindSpeed(int& WindSpeed, int language)
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
	cout << myStringServer.getString(linetwoelve);
	//cout << "Enter Wind speed (hint: an intger positive number not grater than 253 MPH) :";
	while (checkInput == true)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> WindSpeed;
		// check the input if has letter,simple or less than 0 or greater than 253 because this is maximum degree.
		// if it has invalid input  print invalid value 
		if (cin.fail() || cin.peek() != '\n' || WindSpeed < 0 || WindSpeed >253)
		{
			//cout << "invalid value" << endl;
			//cout << " Enter positive number not grater than 253 MPH : ";
			cout << myStringServer.getString(linethrteen);
		}
		else{
			checkInput = false;
		}
	}
	
}
void getWindDirection(string& WindDirectio, int language)
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
	cout << myStringServer.getString(linefourteen);
	//cout << "Enter Wind direction( hint:  one or two capital letter Ex : N,NE):";
	cin.ignore();
	while (checkInput == true)
	{
		getline(cin, WindDirectio);
		if (language == 1)
		{
			if (WindDirectio.compare("N") && WindDirectio.compare("S") && WindDirectio.compare("W") && WindDirectio.compare("E")
				&& WindDirectio.compare("NE") && WindDirectio.compare("NW") && WindDirectio.compare("SE") && WindDirectio.compare("SW") != 0)
			{
				cout << myStringServer.getString(linefifteen);
				//cout << "invalid value" << endl;
				//cout << "Enter one or two capital letter Ex: N,NE:";
			}
			else{
				checkInput = false;
			}
       }
		else{
			if (WindDirectio.compare("Nay") && WindDirectio.compare("Say") && WindDirectio.compare("Way") && WindDirectio.compare("Eway")
				&& WindDirectio.compare("Enay") && WindDirectio.compare("Nway") && WindDirectio.compare("Esay") && WindDirectio.compare("Sway") != 0)
			{
				cout << myStringServer.getString(linefifteen);
			//cout << "invalid value" << endl;
			//cout << "Enter one or two capital letter Ex: N,NE:";
		    }
		   else{
			checkInput = false;
		}
		
		}
		//// compare the input Str with constant value to make sure user just input one or two capital letter
		// if it has invalid input  print invalid value 
		
	}
}