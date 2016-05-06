#include "amath-ng.hpp"
using namespace std;
using namespace boost::multiprecision;

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

mpz_int msqrt(mpz_int num)
{
	mpz_int res(boost::multiprecision::sqrt(num));
	return res;
}

amath_float acbrt(amath_float num)
{
	amath_float ot = 1 / 3;
	amath_float pwr = aexp(num, ot);
	return pwr;
}

mpz_int agcd(mpz_int num1, mpz_int num2)
{
	return gcd(num1, num2);
}

mpz_int alcm(mpz_int num1, mpz_int num2)
{
	return lcm(num1, num2);
}

int isPrime(mpz_int num)
{
	mpz_t nt;
	mpz_init(nt);
	mpz_set(nt, num.backend().data());
	return mpz_probab_prime_p(nt, PRIME_TEST_REPS); //Miller-Rabin probabilistic primality test
}

void afactor(mpz_int num)
{
	//POLLARD RHO ALGORITHM BELOW
	/*
	mpz_int xfixed = 2, cycle_size = 2, x = 2, factor = 1;
	cout << static_cast<string>(num) << ": " << flush;
	while (num % 2 == 0)
	{
		num /= 2;
		cout << "2 " << flush;
	}
	while (!isPrime(num) && num != 1)
	{
		while (factor == 1)
		{
			factor = 1;
			for (mpz_int count=1; count <= cycle_size && factor <= 1; count++)
			{
				x = (x * x + 1) % num;
				factor = agcf(x - xfixed, num);
			}
			cycle_size *= 2;
			xfixed = x;
			num /= factor;
			cout << static_cast<string>(factor) << " " << flush;
		}
		factor = 1;
	}
	cout << endl;
	*/
	//POLLARD RHO ALGORITHM ABOVE

	if (isPrime(num) == 2) //Number is definitely prime, so factorization would be useless
	{
		cout << static_cast<string>(num) << endl;
		return;
	}

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
		cout << num;
	cout << endl;
}

string getfactors(mpz_int num)
{
	string returned;
	if (num < 2)
	{
		returned = "[AMATH-NG/GETFACTORS] ERR: You cannot input non-positive numbers less than 2.";
		return returned;
	}
	vector<mpz_int> factorz;
	for (mpz_int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			factorz.push_back(i);
			if ((msqrt(num) == i) && (asqrt(num) == i))
				factorz.push_back(i);
		}
	}
	int fc = factorz.size();
	int left = 0, right = fc - 1;
	returned = "FACTOR + FACTOR = SUM, PRODUCT\nFound ";
	returned += to_string(fc);
	returned += " total factors\n----------------------------------------------------\n";
	while (left <= right - 1)
	{
		mpz_int ln = factorz.at(left);
		mpz_int rn = factorz.at(right);
		mpz_int sum = ln + rn;
		mpz_int product = ln * rn;
		string leftbuf = static_cast<string>(ln);
		string rightbuf = static_cast<string>(rn);
		string sumbuf = static_cast<string>(sum);
		string productbuf = static_cast<string>(product);
		returned += leftbuf + " + " + rightbuf + " = " + sumbuf + ", " + productbuf + "\n";
		left++;
		right--;
	}
	return returned;
}

