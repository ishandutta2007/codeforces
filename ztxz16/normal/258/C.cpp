#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define mo 1000000007
#define ll long long

ll n, i, j, max, xx, Now[100005], xxx, a[100005];
ll list[100005], list2[100005], tot, tot2, Ans;

ll find(ll x);
ll sumi(ll a, ll b);

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	std::sort(a + 1, a + n + 1);
	max = a[n];
	for (i = 1; i <= max; i++)
	{
		tot = 0;
		tot2 = 0;
		xx = 1;
		for (j = 1; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				list[++tot] = j;
				if (i / j != j)
					list2[++tot2] = i / j;
			}
		}
		
		for (j = tot2; j >= 1; j--)
			list[++tot] = list2[j];
		for (j = 1; j <= tot; j++)
			Now[j] = find(list[j]);
		for (j = 2; j <= tot; j++)
		{
			if (Now[j] != Now[j - 1])
			{
				xx *= sumi(j - 1, Now[j - 1] - Now[j]);
				xx %= mo;
			}
		}
		
		xxx = sumi(tot, Now[tot]) - sumi(tot - 1, Now[tot]);
		xxx %= mo;
		xxx += mo;
		xxx %= mo;
		xx *= xxx;
		xx %= mo;
		
		Ans += xx;
		Ans %= mo;
	}
	
	Ans += mo;
	Ans %= mo;
	printf("%I64d\n", Ans);
	return 0;
}

ll find(ll x)
{
	ll l, r, mid;
	l = 1, r = n;
	while (l < r)
	{
		mid = ((l + r) >> 1);
		if (a[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	
	return n - l + 1;
}

ll sumi(ll a, ll b)
{
	ll i, ret = 1, x = a;
	for (i = 1; i <= b; (i <<= 1))
	{
		if ((b & i) > 0)
		{
			ret *= x;
			ret %= mo;
		}
		
		x *= x;
		x %= mo;
	}
	
	return ret;
}