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

char str[1005];
int i, j, k, sel, len;

int main()
{
	scanf("%s", str + 1);
	len = strlen(str + 1);
	scanf("%d", &k);
	for (i = 1; i <= len; i++)
	{
		sel = i;
		for (j = 1; j <= k && i + j <= len; j++)
			if (str[i + j] > str[sel])
				sel = i + j;
		printf("%c", str[sel]);
		k -= (sel - i);
		for (j = sel; j > i; j--)
			str[j] = str[j - 1];
	}
	
	printf("\n");
	return 0;
}