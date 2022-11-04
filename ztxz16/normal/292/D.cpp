#include <stdio.h>
#include <stdlib.h>

int n, m, a[10005], b[10005];
int i, j, k, s, fa, fb, aa, bb, Ans, f[505];
int f1[10005][505], f2[10005][505];

int find(int i);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (i = 1; i <= n; i++)
		f[i] = i, f1[0][i] = f2[m + 1][i] = i;
	for (i = 1; i <= m; i++)
	{
		fa = find(a[i]), fb = find(b[i]);
		if (fa != fb)
			f[fa] = fb;
		for (j = 1; j <= n; j++)
			f1[i][j] = f[j];
	}
	
	for (i = 1; i <= n; i++)
		f[i] = i;
	for (i = m; i >= 1; i--)
	{
		fa = find(a[i]), fb = find(b[i]);
		if (fa != fb)
			f[fa] = fb;
		for (j = 1; j <= n; j++)
			f2[i][j] = f[j];
	}
	
	scanf("%d", &k);
	for (i = 1; i <= k; i++)
	{
		scanf("%d %d", &aa, &bb);
		for (j = 1; j <= n; j++)
			f[j] = j;
		for (j = 1; j <= n; j++)
		{
			fa = find(j), fb = find(f1[aa - 1][j]);
			if (fa != fb)
				f[fa] = fb;
			fa = find(j), fb = find(f2[bb + 1][j]);
			if (fa != fb)
				f[fa] = fb;
		}
		
		Ans = 0;
		for (j = 1; j <= n; j++)
			if (f[j] == j)
				Ans++;
		printf("%d\n", Ans);
	}
	
	return 0;
}

int find(int i)
{
	if (f[i] == i)
		return i;
	f[i] = find(f[i]);
	return f[i];
}