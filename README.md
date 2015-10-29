amath-ng
========

A command line calculator for elementary and algebraic use, and more to come.

BUILDING
--------

Required libraries:
Boost.Random
Boost.Thread
Boost.System
GMP C/C++

This project uses the C++11 standard.

Build by running this command in a Unix terminal:
g++ -o amath-ng main.cpp -lgmp -lgmpxx -lboost_random -lboost_thread -lboost_system -std=c++1y

You can also build in Qt Creator.
