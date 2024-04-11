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
#include <cmath>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int n, s, i;
double x, y;
pair <double, int> a[1005];

int main()
{
	scanf("%d %d", &n, &s);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf %lf %d", &x, &y, &a[i].second);
		a[i].first = sqrt(x * x + y * y);
	}
	
	if (s >= 1000000)
	{
		printf("0\n");
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
	{
		s += a[i].second;
		if (s >= 1000000)
			break;
	}
	
	if (i <= n)
		printf("%.10f\n", a[i].first);
	else
		printf("-1\n");
	return 0;
}