#ifndef mc_H
#define mc_H

#include <random>
#include <thread>
#include "confidenza.h"

using namespace std;

class mc
{
  protected:
    int N;
    int Nt;
    int totThreads;
    vector<thread> threads;
    double estPi;
    default_random_engine gen;
    uniform_real_distribution<> distr;
    double AS;
    confidenza *c;
    double devSt;
    void devStCalc();
    void calcC();
    double standardCalc();
    void finalCalc();

  public:
    mc(int N);
    int getN() { return N; };
    double getEstPi() { return estPi; };
    virtual void calc() = 0;
    double getDevSt();
    confidenza *getC();
    double getAS();
    int getTotThreads();
};

class HoM : public mc
{
  private:
    int *hitsT;
    int hits;
    int miss;

  public:
    HoM(int N);
    void calc();
    void calcMT(int it);
    int getHits() { return hits; };
    int getMiss() { return miss; };
};

class sm : public mc
{
  private:
    double somm;
    int j;

  public:
    sm(int N);
    void calc();
};
#endif