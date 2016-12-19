#include "weatherStation.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <new>
#include <stdlib.h> 
#include "StringServer.h"
#include <fstream>
#include "LineNumber.h"
#include <map>
#include "WeatherMeasurement.h"
#include <fstream>
#include <cstdlib>
#include <map>
#include <list>
#include <stack>
using namespace std;

void weatherStation::printCurrentForAllWeatherStation(int language, string nameOfWeatherStation){
	StringServer myStringServer;
	if (language == 1)
		myStringServer.language("english.txt");
	else
		myStringServer.language("Piglatin.txt");
	
	
	
	   //list<WeatherMeasurement_t>::iterator it;
	   if (l1.empty())
	   {
		  
		   cout << myStringServer.getString(lineninteen) << endl;
		   cout << myStringServer.getString(linethirtythree) << " ";
		   cout << myStringServer.getString(linetwenty);
		   cout << " " << nameOfWeatherStation;
		   cout << "  " << myStringServer.getString(linetwentyone) << endl;
		   cout << "\t************" << endl;
	   
	   }
	   else{
		   cout << "\t****************" << endl;
		   cout << myStringServer.getString(linetwenty);
		   cout << " " << nameOfWeatherStation;
		   cout << "  " << myStringServer.getString(linetwentyone) << endl;
		   weather.print_weatherMeasurement(l1.front(), language);
		   cout << endl;
	   }
	   
	   
	  
		
	
	
	//cout << "\t****************" << endl
		//<< "\t" << myStringServer.getString(linetwentytwo) << endl;

}






weatherStation::weatherStation()
{
	isStringNull = true;
	size = 0;
	
}


weatherStation::~weatherStation()
{
}

void weatherStation::manageWeatherStation(int language, string nameOfWeatherStations){

	
	//string nameOfWeatherStation;
	//4
	string myStr;
	int userOption;
	// to control the second page when the user press 4 go back to the main page.
	bool on = true;
	//bool isStringNull = true;
  // to count how many time user press one to enter information.
	StringServer myStringServer;
	// to let user chooes which language he or she wants
	//int number;
	//cin >> number;
	if (language == 1)
		myStringServer.language("english.txt");
	else
		myStringServer.language("Piglatin.txt");


	if (size == 0)
	{
		//cout << myStringServer.getString(lineone) << endl;
		getSize(size, language);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	while (on)
	{// print action for user to specify which of three actions to take
		PrintActions(language);
		//user input.
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, myStr);
		
		
		stringstream(myStr) >> userOption;

		// switch to let user enter the option 
		switch (userOption)
		{
		case 1:
				weather.read_weatherMeasurement(language);
				l1.push_front(weather);
                isStringNull = false;
			
			break;
		case 2:
			if (isStringNull == true)
			{


				cout << "\t************" << endl;
				cout << myStringServer.getString(lineninteen) << endl;
				cout << "\t************" << endl;
			}
			else
			{
				cout << myStringServer.getString(linetwenty);
				cout << " " << nameOfWeatherStations;
				cout << "  " << myStringServer.getString(linetwentyone) << endl;
				weather.print_weatherMeasurement(l1.front(), language);
				cout << endl;
				


				//cout << "\nThe " << nameOfWeatherStation << " Weather Station" << endl;
				//now.print_weatherMeasure ment();
				//printTheCurrentOutput(nameOfWeatherStation,WeatherMeasurement[loop - 1].temperature.dgree, now.print_weatherMeasurement[loop - 1].wind.Speed, now.print_weatherMeasurement[loop - 1].wind.Direction);
			}
			break;
		case 3:
			if (isStringNull == true)
			{
				cout << "\t************" << endl
					<< myStringServer.getString(lineninteen) << endl
					<< "\t************" << endl;
			}
			else
			{
				int history = l1.size() - size;
				for (int i = 0; i<history; i++){
					l1.pop_back();
				}
				cout << "\t****************" << endl
			    << myStringServer.getString(linetwenty);
				cout << " " << nameOfWeatherStations;
				cout << "  " << myStringServer.getString(linetwentyone) << endl;
				list<WeatherMeasurement_t>::iterator it;
				for (it = l1.begin(); it != l1.end(); ++it){
					weather.print_weatherMeasurement(*it, language);
					cout << endl;
				}
					//cout << "\t****************" << endl
						//<< "\t" << myStringServer.getString(linetwentytwo) << endl;
				
			}
			break;
		case 4:
			on = false;
			break;
		default:
			cout << myStringServer.getString(linetwentythree) << endl;
			break;
		}

	}
	



}
