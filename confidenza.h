#ifndef confidenza_H
#define confidenza_H

#include <array>

using namespace std;

class confidenza
{
private:
	double c1;
	double c2;
public:
	confidenza();
	array <double, 2> getConf();
	void setConf(array <double, 2> c);
};
#endif