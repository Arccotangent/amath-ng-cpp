# amath-ng
A command line calculator for many different uses, from the basic to the extreme, and more to come.

## Dependencies
+ Boost Random (libboost_random)
+ POSIX Thread Library (libpthread)
+ GMP C (libgmp)

## Building
	./configure
	make all
	make install

### Generating a 'configure' script
To generate the 'configure' script used to build amath-ng, run `autoreconf --install` in the base directory.

## Hacking
amath-ng can be hacked by editing amath-ng.hpp

Currently you can play with:
- The precision of the printed answers in significant figures (default 500)
- The repetitions of the Miller-Rabin primality test (default 50)

## Exact Answer Storage
In some cases, users may need to store the exact answer returned by amath-ng for later usage. This can be done by logging the answer to a file or an environment variable.

Export the square root of 2 to an environment variable named 'ANS': `export ANS=$(amath-ng sqrt 2)`

Log the square root of 2 to a file: `amath-ng sqrt 2 > sqrt2.txt`

