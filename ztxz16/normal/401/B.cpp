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

int x, k, type, y, i, now, ans1, ans2;
vector <pair <int, int> > a;

int main()
{
	scanf("%d %d", &x, &k);
	a.push_back(make_pair(x, x));
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %d", &x, &y);
			a.push_back(make_pair(x, y));
		}
		
		else
			scanf("%d", &x), a.push_back(make_pair(x, x));
	}
	
	sort(a.begin(), a.end());
	now = 0;
	for (i = 0; i < a.size(); i++)
	{
		x = a[i].first - now - 1;
		ans1 += (x + 1) / 2;
		ans2 += x;
		now = a[i].second;
	}
	
	printf("%d %d\n", ans1, ans2);
	return 0;
}