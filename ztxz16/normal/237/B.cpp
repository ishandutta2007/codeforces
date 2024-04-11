#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, j, k, l, s1, s2, now, tot;
int a[105][105], c[105];
pair <pair <int, int>, pair <int, int> > ans[10005];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= c[i]; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= c[i]; j++)
		{
			s1 = i, s2 = j, now = a[i][j];
			for (k = j + 1; k <= c[i]; k++)
				if (a[i][k] < now)
					now = a[i][k], s1 = i, s2 = k;
			for (k = i + 1; k <= n; k++)
				for (l = 1; l <= c[k]; l++)
					if (a[k][l] < now)
						now = a[k][l], s1 = k, s2 = l;
			if (s1 != i || s2 != j)
				ans[++tot] = make_pair(make_pair(i, j), make_pair(s1, s2)), swap(a[i][j], a[s1][s2]);
		}
	}
	
	printf("%d\n", tot);
	for (i = 1; i <= tot; i++)
		printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
	return 0;
}