#define _USE_MATH_DEFINES
#include <cmath>
#include "runner.h"
#include "mc.h"
#include <array>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

runner::runner()
{
    business = NULL;
}

short runner::run(int _N)
{
    business = new HoM(_N);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    business->calc();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    float duration = duration_cast<microseconds>(t2 - t1).count();
    float rError = fabs(1.0 - (business->getEstPi()) / M_PI);

    cout << "Used " + to_string(business->getTotThreads()) + " threads\n"
         << "Estimated PI: " << business->getEstPi() << "\n"
         << "Relative error: " << rError << "\n"
         << "Hits: " << ((HoM *)business)->getHits() << "\n"
         << "Miss: " << ((HoM *)business)->getMiss() << "\nTempo di elaborazione: " << duration / 1000 << "ms";

    array<double, 2> conf = business->getC()->getConf();
    cout << "\nAS: " << business->getAS() << "\nDev. St.: " << business->getDevSt() << "\nConfidenza Left: " << conf[0] << "\nConfidenza Right: " << conf[1] << "\n";
    delete business;
    business = NULL;
    return 0;
}
