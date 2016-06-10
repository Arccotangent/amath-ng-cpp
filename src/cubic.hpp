#include <amath-ng.hpp>

amath_float getdiscrim(amath_float a, amath_float b, amath_float c, amath_float d); //Get discriminant of cubic equation
//amath_float getsol_1(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim); //Get first solution of cubic equation, always real
//amath_float getsol_2(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim); //Get second solution of cubic equation
//amath_float getsol_3(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim); //Get third solution of cubic equation
amath_float getP(amath_float a, amath_float b, amath_float c); //Get P value for depressed cubic
amath_float getQ(amath_float a, amath_float b, amath_float c, amath_float d); //Get Q value for depressed cubic
vector<amath_float> get3sol(amath_float p, amath_float q); //Get all 3 solutions in a vector
amath_float get1sol(amath_float a, amath_float b, amath_float c, amath_float d, amath_float discrim); //Get the only real solution (if there are 3, get the first real solution)

