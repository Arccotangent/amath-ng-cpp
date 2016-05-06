#include "combination.hpp"
using namespace std;

mpz_int ncr(mpz_int n, mpz_int r)
{
	mpz_int num = 1, den = 1;
	mpz_int temp = n;
	for (mpz_int i = 0; i < r; i++)
	{
		num *= temp;
		temp--;
	}

	den = afct(r);

	return num / den;
}


