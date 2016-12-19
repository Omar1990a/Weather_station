
#ifndef wind_h
#define wind_h
using namespace std;

class wind_t{
private:
	int  Speed;
	string  Direction;
	string unit;
	
public:
	int language;
	void read_wind(int language);
	void print_wind(wind_t w,int language);


};



void getWindSpeed(int& WindSpeed, int language);
void getWindDirection(string& WindDirectio, int language);
#endif

