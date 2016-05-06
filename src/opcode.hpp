#ifndef OPCODE_HPP
#define OPCODE_HPP
#include <cstring>
#include <iostream>
#include <ncurses.h>
#include <vector>
#include "amath-ng.hpp"
using namespace std;
int opcode, args;

int getOpCode(int argcount, string op)
{
	const char* op_c = op.c_str();
	args = argcount - 2;
	if (strcmp(op_c, "add") == 0)
	{
		if (args >= 2)
			opcode = 1;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sub") == 0)
	{
		if (args >= 2)
			opcode = 2;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "mul") == 0)
	{
		if (args >= 2)
			opcode = 3;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "div") == 0)
	{
		if (args >= 2)
			opcode = 4;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "exp") == 0)
	{
		if (args == 2)
			opcode = 5;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sqrt") == 0)
	{
		if (args == 1)
			opcode = 6;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "qdr") == 0)
	{
		if (args == 3)
			opcode = 7;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sf") == 0)
	{
		if (args == 1)
			opcode = 8;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "aoc") == 0)
	{
		if (args == 1)
			opcode = 9;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "mod") == 0)
	{
		if (args == 2)
			opcode = 10;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "prm") == 0)
	{
		opcode = 11;
		/*
		if (args == 1)
			opcode = 11;
		else
			opcode = -1;
		*/
	}
	else if (strcmp(op_c, "rand") == 0)
	{
		if (args == 2 || args == 3)
			opcode = 12;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "fac") == 0)
	{
		if (args == 1)
			opcode = 13;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "gcd") == 0)
	{
		if (args >= 2)
			opcode = 14;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "vtx") == 0)
	{
		if (args == 3)
			opcode = 15;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "hypot") == 0)
	{
		if (args == 2)
			opcode = 16;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "fct") == 0)
	{
		if (args == 1)
			opcode = 17;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sin") == 0)
	{
		if (args == 1)
			opcode = 18;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "cos") == 0)
	{
		if (args == 1)
			opcode = 19;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "tan") == 0)
	{
		if (args == 1)
			opcode = 20;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "asin") == 0)
	{
		if (args == 1)
			opcode = 21;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "acos") == 0)
	{
		if (args == 1)
			opcode = 22;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "atan") == 0)
	{
		if (args == 1)
			opcode = 23;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "cbrt") == 0)
	{
		if (args == 1)
			opcode = 24;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "log") == 0)
	{
		if (args == 1)
			opcode = 25;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "log10") == 0)
	{
		if (args == 1)
			opcode = 26;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "psq") == 0)
	{
		if (args == 1)
			opcode = 27;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "ppwr") == 0)
	{
		if (args == 2)
			opcode = 28;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "pcr") == 0)
	{
		if (args == 2)
			opcode = 29;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "cpi") == 0)
	{
		if (args == 4)
			opcode = 30;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "avg") == 0)
	{
		if (args >= 2)
			opcode = 31;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "stdev") == 0)
	{
		if (args >= 2)
			opcode = 32;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "zsc") == 0)
	{
		if (args == 3)
			opcode = 33;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "ord") == 0)
	{
		if (args >= 2)
			opcode = 34;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "ccm") == 0)
	{
		if (args == 1)
			opcode = 35;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "los") == 0)
	{
		if (args == 3)
			opcode = 36;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "loc") == 0)
	{
		if (args == 3)
			opcode = 37;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "pprm") == 0)
	{
		if (args == 1)
			opcode = 38;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "hl") == 0)
	{
		if (args == 1)
			opcode = 39;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "csc") == 0)
	{
		if (args == 1)
			opcode = 40;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "sec") == 0)
	{
		if (args == 1)
			opcode = 41;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "cot") == 0)
	{
		if (args == 1)
			opcode = 42;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "acsc") == 0)
	{
		if (args == 1)
			opcode = 43;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "asec") == 0)
	{
		if (args == 1)
			opcode = 44;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "acot") == 0)
	{
		if (args == 1)
			opcode = 45;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "logb") == 0)
	{
		if (args == 2)
			opcode = 46;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "lcm") == 0)
	{
		if (args == 2)
			opcode = 47;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "getf") == 0)
	{
		if (args == 1)
			opcode = 48;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "cbc") == 0)
	{
		if (args == 4)
			opcode = 49;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "st") == 0)
	{
		if (args == 3)
			opcode = 50;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "ss") == 0)
	{
		if (args == 4)
			opcode = 51;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "ncr") == 0)
	{
		if (args == 2)
			opcode = 52;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "npr") == 0)
	{
		if (args == 2)
			opcode = 53;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "genprm") == 0)
	{
		if (args == 1)
			opcode = 54;
		else
			opcode = -1;
	}
	else if (strcmp(op_c, "flopstest") == 0)
		opcode = -50;
	else if (strcmp(op_c, "deb") == 0)
		opcode = -100;
	else
		opcode = -2;
	return opcode;
}

#endif // OPCODE_HPP

