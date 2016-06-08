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

amath_float getP(amath_float a, amath_float b, amath_float c)
{
	amath_float tacmb2 = (3 * a * c) - (aexp(b, 2));
	amath_float ta2 = 3 * aexp(a, 2);
	amath_float p = tacmb2 / ta2;
	return p;
}

amath_float getQ(amath_float a, amath_float b, amath_float c, amath_float d)
{
	amath_float tb3 = 2 * aexp(b, 3);
	amath_float nabc = 9 * a * b * c;
	amath_float ta2d = 27 * aexp(a, 2) * d;
	amath_float ta3 = 27 * aexp(a, 3);
	amath_float num = tb3 - nabc + ta2d;
	amath_float q = num / ta3;
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

amath_float* get3sol(amath_float a, amath_float p, amath_float q)
{
	/*
	amath_float n1o3a = -1 / (3 * a);
	amath_float u1 = 1;
	amath_float c2 = getC(a, b, c, d, discrim);
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float ukc = u1 * c2;
	amath_float d0oukc = d0 / ukc;
	amath_float t2 = b + ukc + d0oukc;
	amath_float x1 = n1o3a * t2;
	*/
	amath_float* solutions = (amath_float*) malloc(sizeof(amath_float) * 3 + 16);
	int k2 = 0;
	for (amath_float k = 0; k < 3; k++)
	{
		amath_float var1 = 2 * asqrt(anegate(p) / 3);
		amath_float var2_1 = (3 * q) / (2 * p);
		var2_1 *= asqrt(anegate(3) / p);
		amath_float var2_2 = (2 * pi * k) / 3;
		amath_float var2 = (1 / 3) * boost::multiprecision::acos(var2_1) - var2_2;
		amath_float var3 = boost::multiprecision::cos(var2);
		amath_float sol = var1 * var3;
		solutions[k2] = sol;
		k2++;
	}
	return solutions;
}

/*
amath_float get1sol(amath_float a, amath_float p, amath_float q)
{
	
}

amath_float getsol_2(amath_float a, amath_float p, amath_float q)
{
	amath_float n1o3a = -1 / (3 * a);
	amath_float u2s = 1; //0.25 + (0.25 * -3); //u2 cubed
	amath_float c2 = getC(a, b, c, d, discrim);
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float ukc = u2s * c2;
	amath_float d0oukc = d0 / ukc;
	amath_float t2 = b + ukc + d0oukc;
	amath_float x2 = n1o3a * t2;
	x2 = acbrt(x2);
	return x2;
}
*/

amath_float get1sol(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim)
{
	amath_float n1o3a = -1 / (3 * a);
	amath_float u3s = 1;
	amath_float c2 = getC(a, b, c, d, discrim);
	amath_float d0 = aexp(b, 2) - 3 * a * c;
	amath_float ukc = u3s * c2;
	amath_float d0oukc = d0 / ukc;
	amath_float t2 = b + ukc + d0oukc;
	amath_float x3 = n1o3a * t2;
	return x3;
}

