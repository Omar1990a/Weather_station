#ifndef temperature_h
#define temperature_h
using namespace std;

class temperature_t{
private:
	int dgree;
	string scale;
	
public:
	void read_temperature(int language);
	void print_temperature(temperature_t t,int language);

                  };


void getTemperature(int& Temperature, int language);
#endif