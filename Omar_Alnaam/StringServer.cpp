#include "StringServer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <new>
#include <stdlib.h> 
#include <fstream>
#include <cstdlib>
#include "WeatherMeasurement.h"

using namespace std;


StringServer::StringServer()
{
}


StringServer::~StringServer()
{
}


void StringServer::language(string filename) {
	fstream myfile;
	int i = 0;
	myfile.open(filename);
	if (!myfile.is_open()){
		cout << "Can not find file" << endl;
		exit(EXIT_FAILURE);

	}
	while (getline(myfile, mystring[i]))
	{
		i++;
	}

}

void StringServer::print() {
	fstream myfile;
	int i = 0;
	if (!myfile.is_open()){
		exit(EXIT_FAILURE);
	}
	myfile >> mystring[i];
	while (getline(myfile, mystring[i]))
	{
		cout << mystring[i] << endl;
		i++;
	}
	

	myfile.close();
}



