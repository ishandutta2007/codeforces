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

int n, m, need, s, now, Hash[3005], a[3005];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	need = n - m;
	for (int i = 1; i <= n; i++)
	{
		if (Hash[i])
			continue;
		s++;
		Hash[i] = 1, now = a[i];
		while (now != i)
			Hash[now] = 1, now = a[now];
	}
	
	if (s == need)
	{
		printf("0\n");
		return 0;
	}
	
	if (s < need)
	{
		printf("%d\n", need - s);
		for (int i = 1; i <= need - s; i++)
		{
			for (int j = 1; j <= n; j++)
				if (a[j] != j)
				{
					memset(Hash, 0, sizeof(Hash));
					Hash[j] = 1;
					for (now = a[j]; now != j; now = a[now])
						Hash[now] = 1;
					for (int k = j + 1; k <= n; k++)
					{
						if (Hash[k])
						{
							swap(a[j], a[k]);
							printf("%d %d ", j, k);
							break;
						}
					}
					
					break;
				}
		}
	}
	
	else
	{
		printf("%d\n", s - need);
		for (int i = 1; i <= s - need; i++)
		{
			memset(Hash, 0, sizeof(Hash));
			Hash[1] = 1;
			for (now = a[1]; now != 1; now = a[now])
				Hash[now] = 1;
			for (int j = 1; j <= n; j++)
			{
				if (!Hash[j])
				{
					swap(a[1], a[j]);
					printf("1 %d ", j);
					break;
				}
			}
		}
	}
	
	printf("\n");
	return 0;
}