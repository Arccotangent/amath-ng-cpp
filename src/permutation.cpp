#include "permutation.hpp"
using namespace std;

mpz_int npr(mpz_int n, mpz_int r)
{
	mpz_int nf = afct(n);
	mpz_int nrf = afct(n - r);
	return nf / nrf;
}
