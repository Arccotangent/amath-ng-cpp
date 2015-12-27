amath-ng
========

A command line calculator for elementary and algebraic use, and more to come.

BUILDING
--------

Required libraries:

Boost.Random

Boost.Thread

Boost.System

GMP C

This project uses the C++14 standard.

Build by running this command in a Unix terminal: g++ -o amath-ng main.cpp -lgmp -lboost_random -lboost_thread -lboost_system -std=c++1y

You can also build in Qt Creator by importing the project from this repository.
