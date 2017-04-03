
#include "mc.h"
#include "confidenza.h"
#include <array>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <iterator>
#include <numeric>

using namespace std;

void mc::devStCalc()
{
    devSt = sqrt(AS * (1 - AS) / N);
}

void mc::calcC()
{
    double left = AS - 3 * devSt;
    double right = AS + 3 * devSt;
    array<double, 2> conf = {left, right};
    c->setConf(conf);
}

mc::mc(int N)
{
    this->N = N; //Numero campioni
    totThreads = std::thread::hardware_concurrency();
    Nt = N / totThreads; //campioni per thread
    estPi = 0;
    devSt = 0;
    c = new confidenza();
}

double mc::getDevSt()
{
    return devSt;
}

confidenza *mc::getC()
{
    return c;
}

double mc::getAS()
{
    return AS;
}

int mc::getTotThreads()
{
    return totThreads;
}

double mc::standardCalc()
{
    double x = distr(gen);
    double y = distr(gen);
    return x * x + y * y;
}

void mc::finalCalc()
{
    estPi = AS * 4; //risultato stima
    devStCalc();
    calcC();
}

HoM::HoM(int N) : mc(N)
{
    hitsT = new int[totThreads]{0};
    hits = 0;
    miss = 0;
}

void HoM::calc()
{
    for (int i = 1; i <= totThreads; ++i)
        threads.push_back(thread([=] { calcMT(i - 1); }));
    for (auto &th : threads)
        th.join();
    hits = accumulate(hitsT + 0, hitsT + totThreads, 0);
    miss = (Nt * totThreads) - hits;
    AS = double(hits) / double(N);
    finalCalc();
}

void HoM::calcMT(int it)
{
    for (int i = 0; i < Nt; i++)
    {
        if (standardCalc() <= 1)
        {
            hitsT[it] += 1;
        }
    }
}

sm::sm(int N) : mc(N)
{
    somm = 0.0;
    j = 0;
}

void sm::calc()
{
    for (int i = 0; i < N; i++)
    {
        somm += standardCalc();
        j = i;
    }
    AS = somm / double(N);
    finalCalc();
}