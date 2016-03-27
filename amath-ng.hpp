#ifndef AMATHNG_HPP
#define AMATHNG_HPP
#include <boost/multiprecision/gmp.hpp>
#include <boost/sort/sort.hpp>
#include <vector>
#include <iostream>
using namespace std;
using namespace boost::multiprecision;
using boost::multiprecision::backends::gmp_float;
const int AMATH_FLOAT_PRECISION = 500; //Precision of amath_float type in significant figures
typedef number<gmp_float<AMATH_FLOAT_PRECISION>> amath_float;

amath_float* numsort(amath_float num_array[], const unsigned int num_ele); //Sort an array of amath_floats from smallest to largest
amath_float amax(amath_float num1, amath_float num2); //Returns the greatest of the 2 entered numbers
amath_float amin(amath_float num1, amath_float num2); //Returns the least of the 2 entered numbers
amath_float toDegrees(amath_float rad); //Convert radians to degrees
amath_float toRadians(amath_float deg); //Convert degrees to radians
amath_float aexp(amath_float base, amath_float exponent_r); //Exponentiation base^exponent_r
mpz_int afct(mpz_int num); //Factorial (num!) (ex: 5! = 5 * 4 * 3 * 2 * 1)
amath_float anegate(amath_float num); //Negate a number
amath_float asqrt(amath_float num); //Square root
mpz_int msqrt(mpz_int num); //Square root (integer)
amath_float acbrt(amath_float num); //Cube root
mpz_int agcd(mpz_int num1, mpz_int num2); //Greatest common denominator
mpz_int alcm(mpz_int num1, mpz_int num2); //Least common multiple
bool isPrime_sil(mpz_int num); //Check if a number is prime without printing information to the console
bool isPrime(mpz_int num); //Check if a number is prime, while printing information to the console
void afactor(mpz_int num); //Factor an integer by trial division, prints factors straight to console
string getfactors(mpz_int num); //Get a number's factors and return them as a formatted string

#endif //AMATHNG_HPP
