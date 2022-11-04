#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max 100005

using namespace std;

int hash[Max + 5], ss[Max + 5], tot;
int n, i, j, x;
int a[Max][21];
int f[Max], Now, Ans;

int main()
{
	hash[1] = 1;
	for (i = 2; i * i <= Max; i++)
	{
		if (hash[i] == 1)
			continue;
		for (j = i + i; j <= Max; j += i)
			hash[j] = 1;
	}
	
	for (i = 2; i <= Max; i++)
		if (hash[i] == 0)
			ss[++tot] = i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for (j = 1; ss[j] * ss[j] <= x; j++)
		{
			if (x % ss[j] == 0)
				a[i][++a[i][0]] = ss[j];
			while (x % ss[j] == 0)
				x /= ss[j];
		}
		
		if (x != 1)
			a[i][++a[i][0]] = x;
	}
	
	f[1] = Ans = 1;
	for (j = 1; j <= a[1][0]; j++)
		f[a[1][j]] = 1;
	for (i = 2; i <= n; i++)
	{
		Now = 0;
		for (j = 1; j <= a[i][j]; j++)
			if (f[a[i][j]] > Now)
				Now = f[a[i][j]];
		Now++;
		if (Now > Ans)
			Ans = Now;
		for (j = 1; j <= a[i][j]; j++)
			if (Now > f[a[i][j]])
				f[a[i][j]] = Now;
	}
	
	printf("%d\n", Ans);
	return 0;
}