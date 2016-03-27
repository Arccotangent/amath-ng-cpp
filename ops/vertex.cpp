#include "vertex.hpp"

void solve_vertex(amath_float a, amath_float b, amath_float c)
{
	//Side work
	amath_float b2 = b / a;
	b2 /= 2;
	amath_float cs = aexp(b2, 2); //New c value
	//End side work
	amath_float neg_cs = anegate(cs);
	amath_float vtx_y = c + neg_cs; //Balance equation
	amath_float vtx_x = sqrt(cs); //Complete the square
	if (b < 0)
		vtx_x = anegate(vtx_x); //"Drop" minus sign if b is negative
	cout << "VERTEX FORM: y = (x + " << static_cast<string>(vtx_x) << ")² + " << static_cast<string>(vtx_y) <<  endl;
	amath_float neg_vtx_x = anegate(vtx_x);
	cout << "VERTEX: (" << static_cast<string>(neg_vtx_x) << ", " << static_cast<string>(vtx_y) << ")" << endl;
	amath_float neg_b = anegate(b);
	amath_float a2 = a * 2;
	amath_float vtx_x_verify = neg_b / a2;
	if (vtx_x_verify == neg_vtx_x)
		cout << "VERIFIED - Good vertex." << endl;
	else
	{
		cout << "NOT VERIFIED - Bad vertex. If you can manually verify this vertex (-b / 2a = vertex x) then please report this error on the GitHub repository." << endl;
		cout << a2 << endl << neg_b << endl << neg_vtx_x << endl;
	}
}
