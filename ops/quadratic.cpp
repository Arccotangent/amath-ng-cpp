#include "quadratic.hpp"
using namespace std;
using namespace boost::multiprecision;

amath_float getdiscrim(amath_float a, amath_float b, amath_float c)
{
	amath_float neg_b = -b;
	amath_float b2 = aexp(b, 2);
	amath_float fac = 4 * a * c;
	amath_float discrim = b2 - fac;
	return discrim;
}

vector<amath_float> solve(amath_float a, amath_float b, amath_float discrim)
{
	amath_float neg_b = -b;
	amath_float dsqrt = asqrt(discrim);
	amath_float x1 = (neg_b - dsqrt) / (2 * a);
	amath_float x2 = (neg_b + dsqrt) / (2 * a);
	vector<amath_float> sol;
	sol.push_back(x1);
	sol.push_back(x2);
	return sol;
}

