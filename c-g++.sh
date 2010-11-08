#!/bin/bash

rm sort1
g++ -o sort1 sort.cpp payload.cpp insertion.cpp psrs.cpp radix.cpp timer.cpp quicksort.cpp sortingnetwork.cpp shell.c -lpthread -O3 -fopenmp 
