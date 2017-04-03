#ifndef runner_H
#define runner_H

#include "mc.h"

using namespace std;

class runner
{
private:
	mc *business;
public:
	runner();
	short run(int _N);
};
#endif