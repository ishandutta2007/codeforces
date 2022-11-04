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

int n, m, ans[500005];
set <int> s;
vector <int> v;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		s.insert(i);
	for (int i = 1; i <= m; i++)
	{
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		v.clear();
		for (set <int> :: iterator it = s.lower_bound(l); it != s.end() && *it <= r; ++it)
			if (*it != x)
				v.push_back(*it);
		for (vector <int> :: iterator it = v.begin(); it != v.end(); ++it)
			ans[*it] = x, s.erase(*it);
	}
	
	for (int i = 1; i <= n; i++)
		if (i == n)
			printf("%d\n", ans[i]);
		else
			printf("%d ", ans[i]);
	return 0;
}