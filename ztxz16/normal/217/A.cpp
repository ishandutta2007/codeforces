#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int n, i, x[105], y[105], f[105], a, b, fa, fb, Ans;

int find(int i);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		f[i] = i;
	Ans = n - 1;
	for (i = 1; i <= n; i++)
		scanf("%d %d", &x[i], &y[i]);
	for (a = 1; a < n; a++)
		for (b = a + 1; b <= n; b++)
		{
			if (x[a] != x[b] && y[a] != y[b])
				continue;
			fa = find(a), fb = find(b);
			if (fa != fb)
				Ans--, f[fa] = fb;
		}
	printf("%d\n", Ans);
	return 0;
}

int find(int i)
{
	if (f[i] == i)
		return f[i];
	return f[i] = find(f[i]);
}