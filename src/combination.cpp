#include "combination.hpp"
using namespace std;

mpz_int ncr(mpz_int n, mpz_int r)
{
	if (n < r)
	{
		cout << PACKAGE_NAME << ": n must be greater than or equal to r in a combination!" << endl;
		return 0;
	}
	mpz_int nf = afct(n);
	mpz_int rfnrf = afct(r) * afct(n - r);
	return nf / rfnrf;
}


