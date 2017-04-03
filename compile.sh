#!/bin/bash
g++ MonteCarlo.cpp mc.cpp runner.cpp confidenza.cpp -O4 -pthread --std=c++14
