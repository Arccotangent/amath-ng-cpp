#ifndef AMATHNG_HPP
#define AMATHNG_HPP
#define VERSION "v24.0"
#include <boost/multiprecision/gmp.hpp>
#include <boost/sort/sort.hpp>
#include <iostream>
using namespace std;
using namespace boost::multiprecision;
using boost::multiprecision::backends::gmp_float;
typedef number<gmp_float<2500>> amath_float;

amath_float* numsort(amath_float num_array[], const unsigned int num_ele)
{
	std::vector<amath_float> uvector(num_array, num_array + num_ele);
	boost::sort::spreadsort::float_sort(uvector.begin(), uvector.end());
	amath_float* sorted = (amath_float*) malloc(sizeof(amath_float) * num_ele);
	std::copy(uvector.begin(), uvector.end(), sorted);
	return sorted;
}

amath_float amax(amath_float num1, amath_float num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

amath_float amin(amath_float num1, amath_float num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

amath_float toDegrees(amath_float rad)
{
	return rad * (180 / 3.14159265358979323846264338);
}

amath_float toRadians(amath_float deg)
{
	return deg * (3.14159265358979323846264338 / 180);
}

amath_float aexp(amath_float base, amath_float exponent_r)
{
	return boost::multiprecision::pow(base, exponent_r);
}

mpz_int afct(mpz_int num)
{
	mpz_int result = 1;
	for (mpz_int i = num; i > 1; i--)
	{
		result *= i;
	}
	return result;
}

amath_float anegate(amath_float num)
{
	amath_float onum = num;
	num -= onum;
	num -= onum;
	return num;
}

amath_float asqrt(amath_float num)
{
	amath_float res(boost::multiprecision::sqrt(num));
	return res;
}

mpz_int agcf(mpz_int num1, mpz_int num2)
{
	return gcd(num1, num2);
}

void afactor(mpz_int num)
{
	cout << static_cast<string>(num) << ": " << flush;
	while (num % 2 == 0)
	{
		num /= 2;
		cout << "2 " << flush;
	}
	//num is odd
	mpz_int sqrt_num = boost::multiprecision::sqrt(num);
	for (mpz_int z = 3; z <= sqrt_num; z += 2)
	{
		while (num % z == 0)
		{
			num /= z;
			cout << z << " " << flush;
		}
	}

	if (num > 2)
	{
		cout << num;
	}
	cout << endl;
}

#endif // AMATHNG_HPP

