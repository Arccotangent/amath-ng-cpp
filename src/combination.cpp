#include "combination.hpp"
using namespace std;

mpz_int ncr(mpz_int n, mpz_int r)
{
	mpz_int nf = afct(n);
	mpz_int rfnrf = afct(r) * afct(n - r);
	return nf / rfnrf;
}


