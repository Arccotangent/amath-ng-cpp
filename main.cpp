//#include <boost/algorithm/string/erase.hpp>
//#include <boost/math/common_factor_rt.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
//#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/random_device.hpp>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "flopstest.hpp"
#include "amath-ng.hpp"
#include "opcode.hpp"
using namespace std;
using namespace boost::multiprecision;
using boost::multiprecision::backends::gmp_float;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		//If an operation is removed, do not delete it, but simply comment it out here.
		//Unless it is permanently removed
		fprintf(stderr, "AMath-NG v20.0.1 - A Command Line Calculator by Arccotangent\n\n"
						"Usage: amath-ng <operation> <numbers>\n\n"
						"Valid operations include:\n"
						"add <2+ numbers> - Add numbers together\n"
						"sub <2+ numbers> - Subtract numbers\n"
						"mul <2+ numbers> - Multiply numbers\n"
						"div <2+ numbers> - Divide numbers\n"
						"mod <2 numbers> - Get modulus of numbers (division remainder)\n"
						"exp <base> <exponent> - Calculate BASE^EXPONENT\n"
						"sqrt <1 number> - Square root\n"
						"cbrt <1 number> - Cube root\n"
						"qdr <a> <b> <c> - Solve quadratic equation equal to 0\n"
						"sf <1 number> - Get amount of sig figs in number\n"
						"gcf <2+ numbers> - Get GCF of numbers\n"
						//"lcd <2 numbers> - Get LCD of 2 numbers\n"
						"rand <min> <max> [seed] - Generate random integer between MIN and MAX with optional SEED\n"
						"aoc <radius> - Calculate approximate area of circle\n"
						"prm <number> - Test if number is prime [TEMPORARILY REMOVED]\n"
						"fac <number> - Get prime factors of number\n"
						"vtx <a> <b> <c> - Get vertex of quadratic equation equal to y OR 0\n"
						//"dst <x1> <y1> <x2> <y2> - Get distance between 2 points\n"
						"hypot <side1> <side2> - Get hypotenuse of right triangle\n"
						"fct <number> - Factorial of number\n"
						"sin <number> - Trigonometric function - Sine\n"
						"cos <number> - Trigonometric function - Cosine\n"
						"tan <number> - Trigonometric function - Tangent\n"
						"asin <number> - Trigonometric function - Arcsine\n"
						"acos <number> - Trigonometric function - Arccosine\n"
						"atan <number> - Trigonometric function - Arctangent\n"
						"log <number> - Natural logarithm\n"
						"log10 <number> - Base 10 logarithm\n"
						"psq <amount> - Print AMOUNT perfect squares starting with 1.\n"
						"ppwr <amount> <exponent> - Print AMOUNT bases to EXPONENT starting with 1.\n"
						"pcr <actual> <experimental> - Calculate percent error\n"
						"cpi <principal> <%% rate> <compounds per year> <time in years> - Calculate compound interest\n"
						"avg <numbers> - Calculate average of numbers\n"
						"stdev <numbers> - Calculate standard deviation of numbers\n"
						"flopstest - How fast can your computer do math? Computational power is measured in floating point operations per second (FLOP/s)\n"
						"\nMAXIMUM NUMBER PRECISION BEFORE SCIENTIFIC NOTATION IS USED IS 2,500 DIGITS."
						"\n");
		return 1;
	}
	cout << std::setprecision(std::numeric_limits<amath_float>::max_digits10) << flush;
	int opcode = getOpCode(argc, argv[1]);
	if (opcode == 1)
	{
		amath_float result = 0;
		unsigned int argcount = argc - 2;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float addend;
			addend.assign(argv[i + 2]);
			result += addend;
		}
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 2)
	{
		amath_float result;
		result.assign(argv[2]);
		unsigned int argcount = argc - 3;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float subtrahend;
			subtrahend.assign(argv[i + 3]);
			result -= subtrahend;
		}
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 3)
	{
		amath_float result = 1;
		unsigned int argcount = argc - 2;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float multiplicand;
			multiplicand.assign(argv[i + 2]);
			result *= multiplicand;
		}
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 4)
	{
		amath_float result;
		result.assign(argv[2]);
		unsigned int argcount = argc - 3;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float divisor;
			divisor.assign(argv[i + 3]);
			result /= divisor;
		}
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 5)
	{
		amath_float b;
		b.assign(argv[2]);
		amath_float e;
		e.assign(argv[3]);
		amath_float result = aexp(b, e);
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 6)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float result = asqrt(num);
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 7)
	{
		amath_float a;
		amath_float b;
		amath_float c;
		a.assign(argv[2]);
		b.assign(argv[3]);
		c.assign(argv[4]);
		amath_float x1;
		amath_float x2;
		amath_float neg_b = -b;
		amath_float b2 = aexp(b, 2);
		amath_float fac = 4 * a * c;
		amath_float discrim = b2 - fac;
		if (discrim < 0)
		{
			cout << "[AMATH-NG] ERR: No real solutions! Discriminant is negative. (Discriminant = " << static_cast<string>(discrim) << ")" << endl;
			return 1;
		}
		else
		{
			cout << "Discriminant = " << static_cast<string>(discrim) << endl;
		}
		amath_float dsqrt = asqrt(discrim);
		x1 = (neg_b + dsqrt) / 2 * a;
		x2 = (neg_b - dsqrt) / 2 * a;
		cout << "x = " << static_cast<string>(x1) << endl << flush;
		cout << "x = " << static_cast<string>(x2) << endl << flush;
	}
	else if (opcode == 8)
	{
		string number = argv[2];
		amath_float num;
		num.assign(number);
		if (num < 0)
		{
			cerr << "[AMATH-NG] Error: Invalid argument!" << endl;
		}
		if (number.find(".") != number.npos)
		{
			number.erase(remove(number.begin(), number.end(), '.'), number.end());
			size_t fnz = number.find_first_not_of("0");
			string sf = number.substr(fnz, number.npos);
			cout << sf << endl;
			cout << "Sig Figs: " << sf.length() << endl;
		}
		else
		{
			size_t fnz = number.find_first_not_of("0");
			size_t lnz = number.find_last_not_of("0");
			string sf = number.substr(fnz, lnz - fnz + 1);
			cout << sf << endl;
			cout << "Sig Figs: " << sf.length() << endl;
		}
	}
	else if (opcode == 9)
	{
		const amath_float pi = 3.14159265358979323846264338;
		amath_float radius;
		radius.assign(argv[2]);
		amath_float area = aexp(radius, 2);
		area *= pi;
		cout << "Area: " << aexp(radius, 2) << " * Pi" << endl;
		cout << "Approximately: " << area << endl;
	}
	else if (opcode == 10)
	{
		mpz_int num1;
		mpz_int num2;
		num1.assign(argv[2]);
		num2.assign(argv[3]);
		mpz_int res = num1 % num2;
		cout << static_cast<string>(res) << endl;
	}
	else if (opcode == 11)
	{
		/*
		mpz_int prm;
		prm.assign(argv[2]);
		boost::random::mt19937 gen2(clock());
		if (miller_rabin_test(prm, 25, gen2))
		{
			cout << "Number is probably prime. It is recommended you perform another test to confirm." << endl;
			cout << "Perform another test to confirm? (y/n) ";
			char yn;
			cin >> yn;
			if (yn == 'y' || yn == 'Y')
			{
				cout << "Confirming prime..." << endl;
				if (miller_rabin_test((prm - 1) / 2, 25, gen2))
				{
					cout << "Number is confirmed prime." << endl;
				}
				else
				{
					cout << "Number is not confirmed prime, but this does not mean it is not prime." << endl;
				}
			}
			else
			{
				cout << "Number is not confirmed prime since the test was not performed, but this does not mean it is not prime." << endl;
			}
		}
		else
		{
			cout << "Number is not prime." << endl;
		}
		*/
		cerr << "Prime operation temporarily removed." << endl;
	}
	else if (opcode == 12)
	{
		mpz_int min;
		mpz_int max;
		min.assign(argv[2]);
		max.assign(argv[3]);
		boost::random::random_device r;
		unsigned int initnum;
		char* a;
		if (argc == 5)
		{
			initnum = strtol(argv[4], &a, 10);
			for (unsigned short i = 0; i < strlen(argv[4]); i++)
				argv[4][i] = 0x00;
		}
		else
			initnum = r();
		boost::random::mt19937_64 gen(initnum);
		cout << "Seed: " << initnum << endl;
		initnum = 0;
		boost::random::uniform_int_distribution<mpz_int> distrib(min, max);
		cout << distrib(gen) << endl;
	}
	else if (opcode == 13)
	{
		mpz_int num;
		num.assign(argv[2]);
		afactor(num);
	}
	else if (opcode == 14)
	{
		mpz_int num1;
		mpz_int num2;
		num1.assign(argv[2]);
		num2.assign(argv[3]);
		mpz_int gcf = agcf(num1, num2);
		cout << static_cast<string>(gcf) << endl;
	}
	else if (opcode == 15)
	{
		amath_float a;
		amath_float b;
		amath_float c;
		a.assign(argv[2]);
		b.assign(argv[3]);
		c.assign(argv[4]);
		//Side work
		amath_float b2 = b / a;
		b2 /= 2;
		amath_float cs = aexp(b2, 2);
		//End side work
		//c /= a;
		amath_float neg_cs = anegate(cs);
		amath_float vtx_y = c + neg_cs; //balance equation
		amath_float vtx_x = sqrt(cs);
		if (b < 0)
			vtx_x = anegate(vtx_x); //"Drop" minus sign if b is negative
		cout << "VERTEX FORM: y = (x + " << static_cast<string>(vtx_x) << ")² + " << static_cast<string>(vtx_y) <<  endl;
		amath_float neg_vtx_x = anegate(vtx_x);
		//amath_float neg_vtx_x = vtx_x;
		cout << "VERTEX: (" << static_cast<string>(neg_vtx_x) << ", " << static_cast<string>(vtx_y) << ")" << endl;
		amath_float neg_b;
		//if (b < 0)
		//	neg_b = b;
		//else
			neg_b = anegate(b);
		amath_float a2 = a * 2;
		amath_float vtx_x_verify = neg_b / a2;
		if (vtx_x_verify == neg_vtx_x)
			cout << "VERIFIED - Good vertex." << endl;
		else
		{
			cout << "NOT VERIFIED - Bad vertex. If you can manually verify this vertex (-b / 2a = vertex x) then please report this error on the GitLab repository." << endl;
			cout << a2 << endl << neg_b << endl << neg_vtx_x << endl;
		}
	}
	else if (opcode == 16)
	{
		amath_float side1, side2;
		side1.assign(argv[2]);
		side2.assign(argv[3]);
		amath_float hypot;
		side1 = aexp(side1, 2);
		side2 = aexp(side2, 2);
		hypot = asqrt(side1 + side2);
		cout << static_cast<string>(hypot) << endl;
	}
	else if (opcode == 17)
	{
		mpz_int num;
		num.assign(argv[2]);
		mpz_int fac = afct(num);
		cout << static_cast<string>(fac) << endl;
	}
	else if (opcode == 18)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float oh = boost::multiprecision::sin(toRadians(num));
		cout << static_cast<string>(oh) << endl;
	}
	else if (opcode == 19)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float ah = boost::multiprecision::cos(toRadians(num));
		cout << static_cast<string>(ah) << endl;
	}
	else if (opcode == 20)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float oa = boost::multiprecision::tan(toRadians(num));
		cout << static_cast<string>(oa) << endl;
	}
	else if (opcode == 21)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float as = toDegrees(boost::multiprecision::asin(num));
		cout << static_cast<string>(as) << endl;
	}
	else if (opcode == 22)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float ac = toDegrees(boost::multiprecision::acos(num));
		cout << static_cast<string>(ac) << endl;
	}
	else if (opcode == 23)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float at = toDegrees(boost::multiprecision::atan(num));
		cout << static_cast<string>(at) << endl;
	}
	else if (opcode == 24)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float o = 1;
		amath_float t = 3;
		amath_float odt = o / t;
		amath_float c = aexp(num, odt);
		cout << static_cast<string>(c) << endl;
	}
	else if (opcode == 25)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float nlog = boost::multiprecision::log(num);
		cout << static_cast<string>(nlog) << endl;
	}
	else if (opcode == 26)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float nlog = boost::multiprecision::log10(num);
		cout << static_cast<string>(nlog) << endl;
	}
	else if (opcode == 27)
	{
		amath_float amt;
		amt.assign(argv[2]);
		amath_float base = 1;
		for (base = 1; base <= amt; base++)
		{
			amath_float pwr = aexp(base, 2);
			cout << static_cast<string>(pwr) << endl;
		}
	}
	else if (opcode == 28)
	{
		amath_float amt;
		amt.assign(argv[2]);
		amath_float expo;
		expo.assign(argv[3]);
		amath_float base = 1;
		for (base = 1; base <= amt; base++)
		{
			amath_float pwr = aexp(base, expo);
			cout << static_cast<string>(pwr) << endl;
		}
	}
	else if (opcode == 29)
	{
		amath_float act;
		amath_float exper;
		act.assign(argv[2]);
		exper.assign(argv[3]);
		amath_float uerr = ((exper - act) / act) * 100;
		amath_float err = boost::multiprecision::abs(uerr);
		cout << static_cast<string>(err) << endl;
	}
	else if (opcode == 30)
	{
		amath_float principal, rate, num, time;
		principal.assign(argv[2]);
		rate.assign(argv[3]);
		num.assign(argv[4]);
		time.assign(argv[5]);
		rate /= 100;
		amath_float amt;
		amath_float ttc = num * time;
		amath_float urate = (1 + rate) / num;
		amath_float gfac = aexp(urate, ttc);
		amt = principal * gfac;
		cout << static_cast<string>(amt) << endl;
	}
	else if (opcode == 31)
	{
		amath_float result = 0;
		unsigned int argcount = argc - 2;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float addend;
			addend.assign(argv[i + 2]);
			result += addend;
		}
		amath_float acount = argcount;
		result /= acount;
		cout << static_cast<string>(result) << endl;
	}
	else if (opcode == 32)
	{
		amath_float total = 0;
		unsigned int argcount = argc - 2;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float addend;
			addend.assign(argv[i + 2]);
			total += addend;
		}
		amath_float acount = argcount;
		amath_float avg = total / acount;
		amath_float variance;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float data;
			data.assign(argv[i + 2]);
			amath_float dfm = data - avg;
			variance += aexp(dfm, 2);
		}
		variance /= acount;
		amath_float stdev = asqrt(variance);
		cout << static_cast<string>(stdev) << endl;
	}
	else if (opcode == -1)
	{
		cerr << "[AMATH-NG] ERR: Review your argument count!" << endl;
	}
	else if (opcode == -2)
	{
		cerr << "[AMATH-NG] ERR: Invalid operation!" << endl;
	}
	else if (opcode == -50)
	{
		speedtest();
	}
	else if (opcode == -100)
	{
		cout << "[AMATH-NG] Debug mode not yet complete" << endl;
	}
	else
		cerr << "[AMATH-NG] ERR: An unknown error has occurred." << endl;
	return 0;
}
