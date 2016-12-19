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
#include "weatherStation.h"

//#include "temperature.h"
//#include "wind.h"
using namespace std;

int main()
{
	map <string, weatherStation*>station;
	//weatherStation *pweather = 0;
	string nameOfWeatherStation;
	string myStr;
	bool isThereStation = false;
	int userOption;
	StringServer myStringServer;
	int number;
	
	cout << "Please Enter 1 for English" << endl;
	cout << "Easeplay enterway 2 orfay igpay atinlay" << endl;
	getLanguage(number);
	if (number == 1)
		myStringServer.language("english.txt");
	else
		myStringServer.language("Piglatin.txt");
	
	


	// switch to let user enter the option 
	while (true)

	{
		cout << myStringServer.getString(linetwentyfive) << endl;
		cout << myStringServer.getString(linetwentysix) << endl;
		cout << myStringServer.getString(linetwentyseven) << endl;
		cout << myStringServer.getString(linetwentyeight) << endl;
		cout << myStringServer.getString(linetwentynine) << endl;

		cin >> userOption;


		switch (userOption){
		case 1:
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//cout << myStringServer.getString(linezero) << endl;
			cout << myStringServer.getString(linezero);
			getline(cin, nameOfWeatherStation);
			auto search = station.find(nameOfWeatherStation);
			if (search != station.end())
			{
				cout << myStringServer.getString(linethirtyone) << endl;
				cout << endl;

			}
			else{
				station[nameOfWeatherStation] = new weatherStation();
			    isThereStation = true; }
			}
		
			break;

		case 2:
		{
			if (isThereStation == true)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//map<string, weatherStation*>::iterator it;
				bool check = true;
				while (check){
					cout << myStringServer.getString(linethirtytwo);
					getline(cin, nameOfWeatherStation);
					auto search = station.find(nameOfWeatherStation);
					if (search != station.end())
					{
						search->first == nameOfWeatherStation;
						search->second->manageWeatherStation(number, nameOfWeatherStation);
						isThereStation = true;
						check = false;

					}
					else
						cout << myStringServer.getString(linethirty) << endl;

				}
			}
			else
			{
				cout << "\t************" << endl
					<< myStringServer.getString(lineninteen) << endl
					<< "\t************" << endl;
			}
		   }
			break;
		



		case 3:
		{
			if (isThereStation == true){

				map<string, weatherStation*>::iterator it;
				for (it = station.begin(); it != station.end(); ++it){
					if (it != station.end())
					{
						
						it->second->printCurrentForAllWeatherStation(number, it->first);
						///cout << it << endl;
					}
					else {
						cout << "\t************" << endl
							<< myStringServer.getString(lineninteen) << endl
							<< "\t************" << endl;
					}
				}
			}
		 else {
				cout << "\t************" << endl
					<< myStringServer.getString(lineninteen) << endl
					<< "\t************" << endl;
			}
			
		}
			break;


		case 4:

			exit(0);
			break;
			//void exit(int exitcode);
		default:
			cout << myStringServer.getString(linetwentythree) << endl;
			break;


		}
	}

	return 0;

		}




		
	
