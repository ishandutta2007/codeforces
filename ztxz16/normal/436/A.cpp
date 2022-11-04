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

int n, x, i, temp, sel, kind, now, ans, Hash[2005];
int t[2005], h[2005], m[2005];

int main()
{
	scanf("%d %d", &n, &x), temp = x;
	for (i = 1; i <= n; i++)
		scanf("%d %d %d", &t[i], &h[i], &m[i]);
	ans = 0, now = 0;
	kind = 1;
	while (1)
	{
		sel = 0;
		for (i = 1; i <= n; i++)
			if (Hash[i] == 0 && h[i] <= x && t[i] == kind)
			{
				if (sel == 0 || m[i] > m[sel])
					sel = i;	
			}
		if (sel == 0)
			break;
		now++;
		x += m[sel];
		Hash[sel] = 1;
		kind = 1 - kind;
	}
	
	ans = now;
	
	for (i = 1; i <= n; i++)
		Hash[i] = 0;
	x = temp;
	now = 0;
	kind = 0;
	while (1)
	{
		sel = 0;
		for (i = 1; i <= n; i++)
			if (Hash[i] == 0 && h[i] <= x && t[i] == kind)
			{
				if (sel == 0 || m[i] > m[sel])
					sel = i;	
			}
		if (sel == 0)
			break;
		now++;
		x += m[sel];
		Hash[sel] = 1;
		kind = 1 - kind;
	}
	
	ans = max(ans, now);
	printf("%d\n", ans);
	return 0;
}