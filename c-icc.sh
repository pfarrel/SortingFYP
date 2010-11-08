#!/bin/bash

export LANG=C
rm sort1
icc -o sort1 sort.cpp payload.cpp insertion.cpp psrs.cpp radix.cpp timer.cpp quicksort.cpp shell.c sortingnetwork.cpp -pthread -openmp -O3
