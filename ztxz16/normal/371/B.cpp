#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int a, b, c, s;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	scanf("%d %d", &a, &b);
	if (a > b)
		c = gcd(a, b);
	else
		c = gcd(b, a);
	a /= c, b /= c;
	while (a % 2 == 0)
		a /= 2, s++;
	while (a % 3 == 0)
		a /= 3, s++;
	while (a % 5 == 0)
		a /= 5, s++;
	while (b % 2 == 0)
		b /= 2, s++;
	while (b % 3 == 0)
		b /= 3, s++;
	while (b % 5 == 0)
		b /= 5, s++;
	if (a != 1 || b != 1)
		printf("-1\n");
	else
		printf("%d\n", s);
	return 0;
}