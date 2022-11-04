#include <stdio.h>
#include <stdlib.h>
#define mo 1000000007
#define ll long long

ll X[10] = {0, 0, 0, 0, 0, 1, 1, 1, 2, 2};
ll m, i, j, tot, now, t2, Ans, a[160];
ll f[105][105];
ll Num[16], Now[16];

void dfs(ll i, ll s1, ll s2, ll s);

int main()
{
	scanf("%I64d", &m);
	f[0][0] = 1;
	for (i = 1; i <= 10; i++)
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				f[i][j] = f[i - 1][j] * 8 % mo; 
			else
			{
				f[i][j] = f[i - 1][j] * 8 % mo;
				f[i][j] += (f[i - 1][j - 1] * 2) % mo;
				f[i][j] %= mo;
			}
		}
	
	while (m > 0)
	{
		a[++tot] = m % 10;
		m /= 10;
	}
	
	
	for (i = tot; i >= 1; i--)
	{
		now = a[i];
		for (j = 0; j <= 10; j++)
		{
			Num[j + 1 + t2] += (X[now] * f[i - 1][j] % mo);
			Num[j + 1 + t2] %= mo;
			Num[j + t2] += ((now - X[now]) * f[i - 1][j] % mo);
			Num[j + t2] %= mo;
		}
		
		if (now == 4 || now == 7)
			t2++;
	}
	
	Num[t2]++;
	Num[0]--;
	Ans = 0;
	dfs(1, 0, 0, 1);
	printf("%I64d\n", Ans);
	return 0;
}

void dfs(ll i, ll s1, ll s2, ll s)
{
	ll x;
	if (i > 7)
	{
		Ans += s;
		Ans %= mo;
		return;
	}
	
	if (i == 1)
	{
		for (x = 1; x <= tot; x++)
		{
			Now[x]++;
			dfs(i + 1, x, s2, (s * Num[x] % mo));
			Now[x]--;
		}
	}
	
	else
	{
		for (x = 0; x <= tot && x < s1 - s2; x++)
		{
			Now[x]++;
			dfs(i + 1, s1, s2 + x, (s * ((Num[x] - Now[x] + 1 + mo) % mo) % mo));
			Now[x]--;
		}
	}
	
	return;
}