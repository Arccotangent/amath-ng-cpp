#ifndef FLOPSTEST_HPP
#define FLOPSTEST_HPP
#include <iostream>
#include <boost/thread.hpp>
#include <unistd.h>
#include <ctime>
using namespace std;
time_t initial = time(0);
double count_int = 0;
float a = 1.5;
float b = 2.5;
float c;

void counter()
{
	time_t current = time(0);
	float diff = current - initial;
	float hps = count_int / diff;
	cout << "\033[1;1H"; //Clear terminal screen
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\r";
	cout << count_int << " total floating point ops (" << hps << " FLOP/s)" << endl;
}

void dsp()
{
	while (true)
	{
		boost::thread helium(counter);
		helium.join();
		usleep(200000);
	}
}

void speedtest()
{
	system("clear");
	boost::thread hydrogen(dsp);
	while (true)
	{
		c = a + b;
		count_int++;
	}
}

#endif // FLOPSTEST_HPP
