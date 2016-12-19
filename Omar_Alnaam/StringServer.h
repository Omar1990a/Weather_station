#pragma once
#include <string>
#ifndef StringServer_h
#define StringServer_h

using namespace std;
class StringServer
{
	string mystring[40];
public:
	StringServer();
	~StringServer();
	string getString(int id){
		return mystring[id];
	};
	void language(string filename);
	void print();

};
#endif


