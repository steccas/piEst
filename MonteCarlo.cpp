/*
	Progetto GPGPU
	Luca Steccanella
	W83_000009

	Monte Carlo Hit or Miss
	Generazione numeri casuali
    Versione CPU MultiThreaded
*/

#include <cstdlib>
#include <cstdio>
#include <random>
#include <iostream>
#include <stdlib.h>
#include "mc.h"
#include "runner.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Uso: mcCPU [campioni]\n";
        return 0;
    }
    int N = atoi(argv[1]);

    //long long int N = 100;
    //int m = 1;

    runner r;

    r.run(N);

    return 0;
}
