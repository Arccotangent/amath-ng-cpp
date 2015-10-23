#include <boost/algorithm/string/erase.hpp>
#include <boost/math/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/multiprecision/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/random_device.hpp>
#include <cstdio>
#include <iostream>
using namespace std;
using namespace boost::multiprecision;
using boost::multiprecision::backends::gmp_float;
typedef number<gmp_float<2500>> amath_float;

void printAns(amath_float ans)
{
	cout << std::setprecision(std::numeric_limits<amath_float>::max_digits10) << flush << static_cast<string>(ans) << endl << flush;
}

amath_float aexp(amath_float base, cpp_int exponent_r)
{
	amath_float result = 1;
	cpp_int exponent = exponent_r;
	for (cpp_int i = 0; i < exponent; i++)
	{
		result = result * base;
	}
	return result;
}

amath_float asqrt(amath_float num)
{
	amath_float res(boost::multiprecision::sqrt(num));
	return res;
}

cpp_int agcf(cpp_int num1, cpp_int num2)
{
	return gcd(num1, num2);
}

cpp_int alcd(cpp_int num1, cpp_int num2)
{
	return lcm(num1, num2);
}

void afactor(cpp_int num)
{
	cout << static_cast<string>(num) << ": ";
	//string factors = "";
	while (num % 2 == 0)
	{
		num /= 2;
		//factors = factors + "2 ";
		cout << "2 ";
	}
	//num is odd
	cpp_int sqrt_num = boost::multiprecision::sqrt(num);
	//cout << "Testing divisibility by numbers 3 to " << sqrt_num << endl << flush;
	for (cpp_int z = 3; z <= sqrt_num; z += 2)
	{
		//cout << "[" << z << " / " << sqrt_num << "]\r" << flush;
		while (num % z == 0)
		{
			num /= z;
			//factors = factors + static_cast<string>(z) + " ";
			cout << z << " ";
		}
	}

	if (num > 2)
	{
		cout << num;
	}
	cout << endl;
	//cout << "Finished." << endl;
	//return factors;
}

int getOpCode(unsigned short argcount, string op)
{
	const char* op_c = op.c_str();
	int opcode, arg;
	arg = argcount - 2;
	if (strcmp(op_c, "add") == 0)
	{
		if (arg >= 2)
			opcode = 1;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sub") == 0)
	{
		if (arg >= 2)
			opcode = 2;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "mul") == 0)
	{
		if (arg >= 2)
			opcode = 3;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "div") == 0)
	{
		if (arg >= 2)
			opcode = 4;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "exp") == 0)
	{
		if (arg == 2)
			opcode = 5;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sqrt") == 0)
	{
		if (arg == 1)
			opcode = 6;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "qdr") == 0)
	{
		if (arg == 3)
			opcode = 7;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sf") == 0)
	{
		if (arg == 1)
			opcode = 8;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "aoc") == 0)
	{
		if (arg == 1)
			opcode = 9;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "mod") == 0)
	{
		if (arg == 2)
			opcode = 10;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "prm") == 0)
	{
		if (arg == 1)
			opcode = 11;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "rand") == 0)
	{
		if (arg == 2)
			opcode = 12;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "fac") == 0)
	{
		if (arg == 1)
			opcode = 13;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "gcf") == 0)
	{
		if (arg >= 2)
			opcode = 14;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "vtx") == 0)
	{
		if (arg == 3)
			opcode = 15;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "deb") == 0)
		opcode = -100;
	else
		opcode = -2;
	return opcode;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		//If an operation is removed, do not delete it, but simply comment it out here.
		fprintf(stderr, "AMath-NG 1.0 - A Command Line Calculator by Arccotangent\n\n"
						"Usage: amath-ng <operation> <numbers>\n\n"
						"Valid operations include:\n"
						"add <2+ numbers> - Add numbers together\n"
						"sub <2+ numbers> - Subtract numbers\n"
						"mul <2+ numbers> - Multiply numbers\n"
						"div <2+ numbers> - Divide numbers\n"
						"mod <2 numbers> - Get modulus of numbers (division remainder)\n"
						"exp <base (100 decimal places)> <exponent (whole number)> - Calculate BASE^EXPONENT\n"
						"sqrt <1 number> - Square root\n"
						"qdr <a> <b> <c> - Solve quadratic equation equal to 0\n"
						"sf <1 number> - Get amount of sig figs in number\n"
						"gcf <2+ numbers> - Get GCF of numbers\n"
						//"lcd <2 numbers> - Get LCD of 2 numbers\n"
						"rand <min> <max> - Generate random integer between MIN and MAX with optional SEED\n"
						"aoc <radius> - Calculate approximate area of circle\n"
						"prm <number> - Test if number is prime\n"
						"fac <number> - Get prime factors of number\n"
						"vtx <a> <b> <c> - Get vertex of quadratic equation equal to y OR 0\n"
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
		//cout << argv[2] << endl;
		//cout << argv[3] << endl;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float addend;
			addend.assign(argv[i + 2]);
			result += addend;
		}
		printAns(result);
	}
	else if (opcode == 2)
	{
		amath_float result;
		//cout << "1" << endl;
		result.assign(argv[2]);
		unsigned int argcount = argc - 3;
		for (unsigned int i = 0; i < argcount; i++)
		{
			amath_float subtrahend;
			//cout << "2" << endl;
			subtrahend.assign(argv[i + 3]);
			//cout << "3" << endl;
			//cout << subtrahend << endl;
			result -= subtrahend;
			//cout << result << endl;
		}
		printAns(result);
		//cout << std::setprecision(std::numeric_limits<amath_float>::max_digits10) << static_cast<string>(result) << endl;
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
		printAns(result);
		//cout << std::setprecision(std::numeric_limits<amath_float>::max_digits10) << static_cast<string>(result) << endl;
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
		printAns(result);
		//cout << std::setprecision(std::numeric_limits<amath_float>::max_digits10) << static_cast<string>(result) << endl;
	}
	else if (opcode == 5)
	{
		amath_float b;
		b.assign(argv[2]);
		cpp_int e;
		e.assign(argv[3]);
		amath_float result = aexp(b, e);
		printAns(result);
		//cout << std::setprecision(std::numeric_limits<amath_float>::max_digits10) << static_cast<string>(result) << endl;
	}
	else if (opcode == 6)
	{
		amath_float num;
		num.assign(argv[2]);
		amath_float result = asqrt(num);
		printAns(result);
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
		//cout << "FPE" << endl;
		amath_float discrim = b2 - fac;
		//cout << "FPE" << endl;
		//cout << static_cast<string>(b2m4ac) << endl;
		if (discrim < 0)
		{
			cout << "[AMATH-NG] ERR: No real solutions! Discriminant is negative. (Discriminant = " << static_cast<string>(discrim) << ")" << endl;
			return 1;
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
			cerr << "[AMATH] Error: Invalid argument!" << endl;
		}
		if (number.find(".") != number.npos)
		{
			boost::algorithm::erase_all(number, ".");
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
		cpp_int num1;
		cpp_int num2;
		num1.assign(argv[2]);
		num2.assign(argv[3]);
		cpp_int res = num1 % num2;
		cout << res << endl;
	}
	else if (opcode == 11)
	{
		cpp_int prm;
		prm.assign(argv[2]);
		//mt11213b base_gen(clock());
		//independent_bits_engine<mt11213b, 256, int_type> gen(base_gen);
		boost::random::mt19937 gen2(clock());
		if (miller_rabin_test(prm, 25, gen2))
		{
			cout << "Number is probably prime. It is recommended you perform another test to confirm." << endl;
			cout << "Perform another test to confirm? (y/n) ";
			char yn;
			cin >> yn;
			if (yn == 'y')
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
	}
	else if (opcode == 12)
	{
		cpp_int min;
		cpp_int max;
		min.assign(argv[2]);
		max.assign(argv[3]);
		boost::random::random_device r;
		signed long initnum = r();
		boost::random::mt19937_64 gen(initnum);
		initnum = 0;
		boost::random::uniform_int_distribution<cpp_int> distrib(min, max);
		cout << distrib(gen) << endl;
	}
	else if (opcode == 13)
	{
		cpp_int num;
		num.assign(argv[2]);
		afactor(num);
		//cout << factors << endl;
	}
	else if (opcode == 14)
	{
		cpp_int num1;
		cpp_int num2;
		num1.assign(argv[2]);
		num2.assign(argv[3]);
		cpp_int gcf = agcf(num1, num2);
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
		cout << static_cast<string>(b2) << endl << static_cast<string>(cs) << endl;
		//End side work
		amath_float neg_cs = -cs;
		amath_float vtx_y = c + neg_cs;
		amath_float vtx_x = sqrt(cs);
		cout << "VERTEX FORM: y = (x + " << static_cast<string>(vtx_x) << ")² + " << static_cast<string>(vtx_y) <<  endl;
		amath_float neg_vtx_x = -vtx_x;
		cout << "VERTEX: (" << static_cast<string>(neg_vtx_x) << ", " << static_cast<string>(vtx_y) << ")" << endl;
		amath_float neg_b = -b;
		amath_float a2 = a * 2;
		amath_float vtx_x_verify = neg_b / a2;
		if (vtx_x_verify == neg_vtx_x)
			cout << "VERIFIED - Good vertex." << endl;
		else
			cout << "NOT VERIFIED - Bad vertex." << endl;
	}
	else if (opcode == -1)
	{
		cerr << "[AMATH-NG] ERR: Review your argument count!" << endl;
	}
	else if (opcode == -2)
	{
		cerr << "[AMATH-NG] ERR: Invalid operation!" << endl;
	}
	else if (opcode == -100)
	{
		//amath_float t;
		//t.assign(3.5);
		//cout << t << endl;
		//string d;
		//cin >> d;
	}
	else
		cerr << "[AMATH-NG] ERR: An unknown error has occurred." << endl;
	return 0;
}
