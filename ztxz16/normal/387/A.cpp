#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int a, b, c, d;
char str[16];

int main()
{
	gets(str);
	a = (str[0] - 48) * 10 + str[1] - 48;
	b = (str[3] - 48) * 10 + str[4] - 48;
	gets(str);
	c = (str[0] - 48) * 10 + str[1] - 48;
	d = (str[3] - 48) * 10 + str[4] - 48;
	while (c || d)
	{
		if (d == 0)
			c--, d = 59;
		else
			d--;
		if (b == 0)
			a--, b = 59;
		else
			b--;
		if (a < 0)
			a += 24;
	}
	
	printf("%02d:%02d\n", a, b);
	return 0;
}