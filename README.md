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

## Hacking
amath-ng can be hacked by editing amath-ng.hpp
Currently you can hack:
- The precision of the printed answers in significant figures (default 500)
