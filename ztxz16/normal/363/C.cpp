#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int i, j, tot, n;
char str[200005], b[200005];

int main()
{
	gets(str + 1);
	n = strlen(str + 1);
	tot = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n && str[j] == str[i]; j++);
		j--;
		if (j == i)
			b[++tot] = str[i];
		else
		{
			b[++tot] = str[i], b[++tot] = str[i];
			if (tot >= 4 && b[tot - 2] == b[tot - 3])
				tot--;
		}
		
		i = j;
	}
	
	b[++tot] = 0;
	puts(b + 1);
	return 0;
}