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

int n, m, ans[100005], ban[100005][5];
vector <int> v[100005];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (ans[a])
		{
			swap(a, c);
			if (ans[c] == 3)
				ans[a] = 1, ans[b] = 2;
			else if (ans[c] == 2)
				ans[a] = 1, ans[b] = 3;
			else
				ans[a] = 2, ans[b] = 3;
		}
		
		else if (ans[b])
		{
			swap(b, c);
			if (ans[c] == 3)
				ans[a] = 1, ans[b] = 2;
			else if (ans[c] == 2)
				ans[a] = 1, ans[b] = 3;
			else
				ans[a] = 2, ans[b] = 3;
		}
		
		else if (ans[c])
		{
			if (ans[c] == 3)
				ans[a] = 1, ans[b] = 2;
			else if (ans[c] == 2)
				ans[a] = 1, ans[b] = 3;
			else
				ans[a] = 2, ans[b] = 3;
		}
		
		else
			ans[a] = 1, ans[b] = 2, ans[c] = 3;
	}
	
	for (int i = 1; i <= n; i++)
		if (i == n)
			printf("%d\n", ans[i]);
		else
			printf("%d ", ans[i]);
	return 0;
}