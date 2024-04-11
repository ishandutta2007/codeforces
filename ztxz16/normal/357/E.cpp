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

int n, ans, ss, t0, t3, t4;
int s[5], s2[5];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x), s[x]++, ss += x;
	}
	
	ans = OO;
	for (int i = 0; i <= n; i++)
	{
		int now = 0;
		t4 = ss - 3 * i;
		t3 = i - t4;
		t0 = n - t3 - t4;
		if (t4 < 0 || t3 < 0)
			continue;
		for (int j = 1; j <= 4; j++)
			s2[j] = s[j];
		int j;
		for (j = 4; j >= 1; j--)
		{
			if (t4 >= s2[j])
				t4 -= s2[j], now += abs(4 - j) * s2[j];
			else
			{
				now += abs(4 - j) * t4;
				s2[j] -= t4;
				break;
			}
		}
		
		for (; j >= 1; j--)
		{
			if (t3 >= s2[j])
				t3 -= s2[j], now += abs(3 - j) * s2[j];
			else
			{
				now += abs(3 - j) * t3;
				s2[j] -= t3;
				break;
			}
		}
		
		for (; j >= 1; j--)
		{
			if (t0 >= s2[j])
				t0 -= s2[j], now += abs(j) * s2[j];
			else
			{
				now += abs(j) * t0;
				s2[j] -= t0;
				break;
			}
		}
		
		ans = min(ans, now);
	}
	
	if (ans == OO)
		printf("-1\n");
	else
		printf("%d\n", (ans >> 1));
	return 0;
}