
#include "confidenza.h"
#include <array>

confidenza::confidenza()
{
	c1 = c2 = 0;
}

array <double, 2> confidenza::getConf()
{
	array <double, 2> c = { c1, c2 };
	return c;
}

void confidenza::setConf(array<double, 2> c)
{
	c1 = c[0];
	c2 = c[1];
}
