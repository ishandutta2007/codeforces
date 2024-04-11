#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int test;
char str[105];

int main()
{
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		if (len <= 10)
			printf("%s\n", str + 1);
		else
		{
			printf("%c%d%c\n", str[1], len - 2, str[len]);
		}
	}
	
	return 0;
}