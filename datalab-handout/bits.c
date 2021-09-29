/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
 /*
  * Instructions to Students:
  *
  * STEP 1: Read the following instructions carefully.
  */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES :

Replace the "return" statement in each function with one
or more lines of C code that implements the function.Your code
must conform to the following style :

int Funct(arg1, arg2, ...) {
	/* brief description of how your implementation works */
	int var1 = Expr1;
	...
		int varM = ExprM;

	varJ = ExprJ;
	...
		varN = ExprN;
	return ExprR;
}

Each "Expr" is an expression using ONLY the following :
1. Integer constants 0 through 255 (0xFF), inclusive.You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables(no global variables).
3. Unary integer operations !~
4. Binary integer operations & ^| +<< >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators.You are not restricted to
one operator per line.

You are expressly forbidden to :
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as&&, || , -, or ? :
	6. Use any form of casting.
	7. Use any data type other than int.This implies that you
	cannot use arrays, structs, or unions.


	You may assume that your machine :
1. Uses 2s complement, 32 - bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE :
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
	/* exploit ability of shifts to compute powers of 2 */
	return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
	/* exploit ability of shifts to compute powers of 2 */
	int result = (1 << x);
	result += 4;
	return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating - point operations,
the coding rules are less strict.You are allowed to use loopingand
conditional control.You are allowed to use both intsand unsigneds.
You can use arbitrary integerand unsigned constants.

You are expressly forbidden to :
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc(data lab checker) compiler(described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators(!~&^| +<< >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc.Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function.If there are any inconsistencies
between the maximum ops in the writeupand in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
 /* Copyright (C) 1991-2018 Free Software Foundation, Inc.
	This file is part of the GNU C Library.

	The GNU C Library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	The GNU C Library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with the GNU C Library; if not, see
	<http://www.gnu.org/licenses/>.  */
	/* This header is separate from features.h so that the compiler can
	   include it implicitly at the start of every compilation.  It must
	   not itself include <features.h> or any other header that includes
	   <features.h> because the implicit include comes before any feature
	   test macros that may be defined in a source file before it first
	   explicitly includes a system header.  GCC knows the name of this
	   header in order to preinclude it.  */
	   /* glibc's intent is to support the IEC 559 math functionality, real
		  and complex.  If the GCC (4.9 and later) predefined macros
		  specifying compiler intent are available, use them to determine
		  whether the overall intent is to support these features; otherwise,
		  presume an older compiler has intent to support these features and
		  define these macros by default.  */
		  /* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
			 synchronized with ISO/IEC 10646:2017, fifth edition, plus
			 the following additions from Amendment 1 to the fifth edition:
			 - 56 emoji characters
			 - 285 hentaigana
			 - 3 additional Zanabazar Square characters */
			 /* We do not support C11 <threads.h>.  */
/*
* bitNot - ~x without using ~
*   Example: bitNot(0) = 0xffffffff
*   Legal ops: ! & ^ | + << >>
*   Max ops: 12
*   Rating: 1
*/
int bitNot(int x) {
	int u = 0xff;
	u = u + (u << 8);
	u = u + (u << 16);
	return u ^ x;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	return (~(x & y)) & (~((~x) & (~y)));
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int mask = 0xaa + (0xaa << 8);
	mask = mask + (mask << 16);
	return !((mask & x) ^ mask);
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {
	int sub32 = 32 + (~n + 1);
	return ((x >> n) & ~((~1 + 1) << sub32)) | (x << sub32);
}
/*
 * palindrome - return 1 if x is palindrome in binary form,
 *   return 0 otherwise
 *   A number is palindrome if it is the same when reversed
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   Example: palindrome(0xff0000ff) = 1,
 *            palindrome(0xff00ff00) = 0
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 40
 *   Rating: 4

 */
int palindrome(int x) {
	int a = x & 0x0000ffff;
	int b = x & 0xffff0000;
	a = ((a & 0x00ff) << 8) | ((a >> 8) & 0x00ff);
	a = ((a & 0x0f0f) << 4) | ((a >> 4) & 0x0f0f);
	a = ((a & 0x3333) << 2) | ((a >> 2) & 0x3333);
	a = ((a & 0x5555) << 1) | ((a >> 1) & 0x5555);
	return !((a << 16) ^ b);
}
/*
 * countConsecutive1 - return the number of consecutive 1‘s
 *   in the binary form of x
 *   Examples: countConsecutive1(0xff00ff00) = 2,
 *             countConsecutive1(0xff10ff10) = 4,
 *             countConsecutive1(0xff80ff80) = 2,
 *             countConsecutive1(0b00101010001111110101110101110101) = 10
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int countConsecutive1(int x) {
	int mask;
	int flag = !((x >> 31) ^ (x & 1)); //1时首尾相等
	int num = x ^ (x << 1);
	//cout << bitset<sizeof(num) * 8>(num) << endl;
	mask = 0x55; mask = (mask << 8) + mask; mask = (mask << 16) + mask;
	num = (num & mask) + ((num >> 1) & mask);
	mask = 0x33; mask = (mask << 8) + mask; mask = (mask << 16) + mask;
	num = (num & mask) + ((num >> 2) & mask);
	mask = 0x0f; mask = (mask << 8) + mask; mask = (mask << 16) + mask;
	num = (num & mask) + ((num >> 4) & mask);
	mask = 0xff; mask = (mask << 16) + mask;
	num = (num & mask) + ((num >> 8) & mask);
	mask = 0xff; mask = (mask << 8) + mask;
	num = (num & mask) + ((num >> 16) & mask);
	num = num + !flag;
	return  (num >> 1) + ((x & 1) & flag);
}
/*
 * counter1To5 - return 1 + x if x < 5, return 1 otherwise, we ensure that 1<=x<=5
 *   Examples counter1To5(2) = 3,  counter1To5(5) = 1
 *   Legal ops: ~ & ! | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int counter1To5(int x) {
	int mask = !((x >> 2) & (x & 1));
	mask = mask | mask << 1 | mask << 2;
	return (mask & x) + 1;
}
/*
 * fullSub - 4-bits sub using bit-wise operations only.
 *   (0 <= x, y < 16)
 *   Example: fullSub(12, 7) = 0x5,
 *            fullSub(7, 8) = 0xf,
 *   Legal ops: ~ | ^ & << >>
 *   Max ops: 35
 *   Rating: 2
 */
int fullSub(int x, int y) {
	int res1, res2, res3, res4, carry;
	y = ~y;
	res1 = y ^ 1;
	carry = y & 1;
	res2 = res1 ^ (carry << 1);
	carry = res1 & (carry << 1);
	res3 = res2 ^ (carry << 1);
	carry = res2 & (carry << 1);
	res4 = res3 ^ (carry << 1);
	carry = res3 & (carry << 1);
	res4 = res4 ^ (carry << 1);
	y = res4;
	res1 = x ^ y;
	carry = x & y;
	res2 = res1 ^ (carry << 1);
	carry = res1 & (carry << 1);
	res3 = res2 ^ (carry << 1);
	carry = res2 & (carry << 1);
	res4 = res3 ^ (carry << 1);
	carry = res3 & (carry << 1);
	res4 = res4 ^ (carry << 1);
	return res4 & 0xf;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	return !(((~(((x ^ y) >> 31) | y) + x) >> 31) + 1);
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
	/*
	int mask = (x >> 31);
	int sign = mask & 1;
	int signmask = ~(sign << 31);
	x = x & signmask;
	cout << hex << sign << endl;
	cout << hex << signmask << endl;
	cout << hex << mask << endl;
	return ((x ^ mask) + sign);
	*/
	int sign = x >> 31;
	int revmask = ~((~0) << 31);
	return (sign & (~(x + revmask + 1) + 1)) | (~sign & x);
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
	/*
	int sum = x + y;
	int xsign = x >> 31;
	int ysign = y >> 31;
	int xysign = sum >> 31;
	int overflow = (~(xsign ^ ysign)) & (xsign ^ xysign);
	*/
	int sum = x + y; int overflow = ((~(x ^ y)) & (sum ^ x)) >> 31;
	return ((~overflow) & sum) | (overflow & (((1 << 31) + (sum >> 31))));
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
	int sign = x >> 31;
	int divide = (x >> 3);
	int remmask = 0x7;
	int rem = x & remmask;
	int times5 = rem + (rem << 2);
	int res = divide + (divide << 2);
	return res + ((times5 + (sign & remmask)) >> 3);
}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{
	/*
	if (expt)
	{
		if ((!expt) && expt != mexp)
			return (uf + 0x00800000);
	}

	else if (expt)
		return ((uf << 1) | signt);
	else return uf;

	if (expt) {
		if (expt != 0x7F800000) {
			uf = uf + 0x00800000;
		}
	}
	else
		uf = (uf << 1) | signt;
	return uf;
	*/
	unsigned frac;
	unsigned expmask = 0x7f800000;
	unsigned sign = uf & (1 << 31);
	unsigned exp = uf & expmask;
	unsigned fracmask = 0x007fffff;
	frac = uf & fracmask;
	if (exp == expmask)return uf;
	else if (!exp)return sign | (frac << 1);
	else if (exp == (0x7f000000))return sign | expmask;
	else return sign | (exp + (1 << 23)) | frac;

}
/*
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
	unsigned expmask = 0x7f800000;
	unsigned sign = uf & (1 << 31);
	unsigned exp = uf & expmask;
	unsigned expthres = 0x00800000;
	int lsb = ((uf & 3) == 3);
	if (exp == expmask)
		return uf;
	else if (exp <= expthres)
		return sign | (((uf ^ sign) + lsb) >> 1);
	else
		return uf - expthres;
}
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
	int INF = 0x80000000u;
	int sign = uf >> 31;
	int exp = ((uf >> 23) & 0xff) - 127;
	int frac = (uf & 0x007fffff) | 0x800000;
	if (exp < 0) return 0;
	else if (exp > 31) return INF;
	else if (exp > 23) frac = frac << (exp - 23);
	else frac = frac >> (23 - exp);
	if (!((frac >> 31) ^ sign))return frac;
	else if (frac >> 31)return INF;
	else return ~frac + 1;
}
/*
 * float_pwr2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_pwr2(int x) {
	/*
	unsigned INF = 0xff << 23;
	if (x < -150) {
		return 0;
	}
	if (x >= -150 && x <= -127) {
		int shift = (-x - 127);
		int frac = 1 << shift;
		return frac;
	}
	if (x >= -126 && x <= 127) {
		int e = (x + 127) << 23;
		return e;
	}
	if (x >= 128) {
		int e = INF;
		return e;
	}
	return 0;
	*/
	unsigned exp;
	if (x < -149)return 0;
	else if (x > 127)return 0x7f800000u;
	else if (x <= -127)return (1 << (x + 149));
	else return (x + 127) << 23;
}
