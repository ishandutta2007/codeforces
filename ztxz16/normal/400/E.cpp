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

int n, m, i, j, x, now, p, v, a[100005];
set <int> s[25];
set <int>::iterator it;
long long ans;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i <= 20; i++)
	{
		s[i].insert(n + 1);
		x = (1 << i);
		now = n + 1;
		for (j = n; j >= 1; j--)
		{
			if ((a[j] & x) == 0)
				s[i].insert(j), now = j;
			else
				ans += (long long)(now - j) * x;
		}
	}
	
	while (m--)
	{
		scanf("%d %d", &p, &v);
		for (i = 0; i <= 20; i++)
		{
			x = (1 << i);
			if ((v & x) == (a[p] & x))
				continue;
			if ((v & x) == 0)
			{
				int next, succ;
				it = s[i].upper_bound(p);
				next = *it;
				if (it == s[i].begin())
					succ = 0;
				else
					it--, succ = *it;
				ans -= (long long)(p - succ) * (long long)(next - p) * x;
				s[i].insert(p);
			}
			
			else
			{
				int next, succ;
				it = s[i].upper_bound(p);
				next = *it;
				it = s[i].lower_bound(p);
				if (it == s[i].begin())
					succ = 0;
				else
					it--, succ = *it;
				ans += (long long)(p - succ) * (long long)(next - p) * x;
				s[i].erase(p);
			}
		}
		
		cout << ans << endl;
		a[p] = v;
	}
	
	return 0;
}