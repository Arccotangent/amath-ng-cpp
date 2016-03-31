#include "cubic.hpp"
using namespace std;

amath_float getdiscrim(amath_float a, amath_float b, amath_float c, amath_float d)
{
	amath_float abcd18 = 18 * a * b * c * d;
	amath_float bt3d4 = 4 * aexp(b, 3) * d;
	amath_float b2c2 = aexp(b, 2) * aexp(c, 2);
	amath_float ac3x4 = 4 * a * aexp(c, 3);
	amath_float a2d2x27 = 27 * aexp(a, 2) * aexp(d, 2);
	amath_float discrim = b2c2 - ac3x4 - bt3d4 - a2d2x27 + abcd18;
	return discrim;
}

amath_float getC(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim)
{
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float d1 = (2 * aexp(b, 3)) - (9 * a * b * c) + (27 * aexp(a, 2) * d);
	amath_float d2 = -27 * aexp(a, 2) * discrim;
	amath_float c2 = d1 + asqrt(d2);
	c2 /= 2;
	return acbrt(c2);
}

amath_float getsol_1(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim)
{
	amath_float n1o3a = -1 / (3 * a);
	amath_float u1 = 1;
	amath_float c2 = getC(a, b, c, d, discrim);
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float ukc = u1 * c2;
	amath_float d0oukc = d0 / ukc;
	amath_float t2 = b + ukc + d0oukc;
	amath_float x1 = n1o3a * t2;
	return x1;
}

amath_float getsol_2(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim)
{
	amath_float n1o3a = -1 / (3 * a);
	amath_float u2s = 0.25 + (0.25 * -3); //u2 squared
	amath_float c2 = getC(a, b, c, d, discrim);
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float ukc = u2s * c2;
	amath_float d0oukc = d0 / ukc;
	amath_float t2 = b + ukc + d0oukc;
	amath_float x2 = n1o3a * t2;
	x2 = asqrt(x2);
	return x2;
}

amath_float getsol_3(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim)
{
	amath_float n1o3a = -1 / (3 * a);
	amath_float u3s = 0.25 - (0.25 * -3); //u3 squared
	amath_float c2 = getC(a, b, c, d, discrim);
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float ukc = u3s * c2;
	amath_float d0oukc = d0 / ukc;
	amath_float t2 = b + ukc + d0oukc;
	amath_float x3 = n1o3a * t2;
	x3 = asqrt(x3);
	return x3;
}

