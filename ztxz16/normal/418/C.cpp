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

const int MAX = 100;
int Hash[1000005];
int a[105], b[105], i, j, n, m;

void get(int a[], int n);

int main()
{
	for (i = 1; i <= 1000; i++)
		Hash[i * i] = 1;
	scanf("%d %d", &n, &m);
	get(a, n), get(b, m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (j == m)
				printf("%d\n", a[i] * b[j]);
			else
				printf("%d ", a[i] * b[j]);
	return 0;
}

void get(int a[], int n)
{
	if (n == 1)
		a[1] = 1;
	else if (n == 2)
		a[1] = 3, a[2] = 4;
	else
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; i + j <= n; j++)
				if (Hash[i + j * 4 + (n - i - j) * 9])
				{
					for (int k = 1; k <= i; k++)
						a[k] = 1;
					for (int k = i + 1; k <= i + j; k++)
						a[k] = 2;
					for (int k = i + j + 1; k <= n; k++)
						a[k] = 3;
					return;
				}
	}
}