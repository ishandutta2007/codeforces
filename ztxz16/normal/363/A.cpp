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

int n;

void print(int n);

int main()
{
	scanf("%d", &n);
	if (n == 0)
		print(0);
	else
	{
		while (n > 0)
			print(n % 10), n /= 10;
	}
	
	return 0;
}

void print(int n)
{
	if (n >= 5)
		printf("-O|"), n -= 5;
	else
		printf("O-|");
	if (n == 0)
		printf("-OOOO\n");
	else if (n == 1)
		printf("O-OOO\n");
	else if (n == 2)
		printf("OO-OO\n");
	else if (n == 3)
		printf("OOO-O\n");
	else if (n == 4)
		printf("OOOO-\n");
}