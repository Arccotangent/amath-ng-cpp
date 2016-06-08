#ifndef AMATHNG_HPP
#define AMATHNG_HPP
#include <boost/multiprecision/gmp.hpp>
#include <boost/sort/sort.hpp>

#ifdef HAVE_CONFIG_H
#include <config.h>
#else
#define ENABLE_CUBIC_OP 0
#define PACKAGE_NAME "amath-ng"
#define PACKAGE_VERSION "unknown"
#define PACKAGE_STRING "amath-ng unknown"
#endif

#include <vector>
#include <iostream>
#include <gmp.h>
using namespace std;
using namespace boost::multiprecision;
using boost::multiprecision::backends::gmp_float;
const int AMATH_FLOAT_PRECISION = 500; //Precision of amath_float type in significant figures
const int PRIME_TEST_REPS = 50; //Repetitions for primality test. A reasonable amount of repetitions would be 15-50. Higher reps = higher chance the number is prime (if probable)
typedef number<gmp_float<AMATH_FLOAT_PRECISION>> amath_float;
const amath_float pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679; //100 digits

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
int isPrime(mpz_int num); //Check if a number is prime (RETURNS 0 = Definitely composite (non-prime), 1 = Probably prime, 2 = Definitely prime)
void afactor(mpz_int num); //Factor an integer by trial division, prints factors straight to console
string getfactors(mpz_int num); //Get a number's factors and return them as a formatted string

#endif //AMATHNG_HPP

