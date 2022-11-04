#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, q, v[100005], color[100005];
ll Max[100005], m1, m2, c1, c2, i, a, b, Ans;
ll hash[100005], f[100005], temp;

void Work(ll a, ll b);

int main()
{
	scanf("%I64d %I64d", &n, &q);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &v[i]);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &color[i]);
	for (i = 1; i <= q; i++)
	{
		scanf("%I64d %I64d", &a, &b);
		Work(a, b);
	}
	
	return 0;
}

void Work(ll a, ll b)
{
	ll i;
	memset(hash, 0, sizeof(hash));
	memset(f, 0, sizeof(f));
	memset(Max, 0, sizeof(Max));
	m1 = 0, c1 = 0;
	m2 = 0, c2 = 0;
	Ans = 0;
	f[1] = v[1] * b;
	hash[color[1]] = 1;
	Max[color[1]] = f[1];
	m1 = f[1], c1 = color[1];
	if (f[1] > Ans)
		Ans = f[1];
	for (i = 2; i <= n; i++)
	{
		f[i] = v[i] * b;
		if (hash[color[i]] == 1 && ((v[i] * a) + Max[color[i]]) > f[i])
			f[i] = (v[i] * a) + Max[color[i]];
		if (c1 == color[i])
		{
			if (c2 != 0)
			{
				if (m2 + (v[i] * b) > f[i])
					f[i] = m2 + v[i] * b;
			}
		}
		
		else if (c1 != 0)
		{
			if (m1 + (v[i] * b) > f[i])
				f[i] = m1 + v[i] * b;
		}
		
		if (f[i] > Ans)
			Ans = f[i];
		if (hash[color[i]] == 0)
			hash[color[i]] = 1, Max[color[i]] = f[i];
		if (f[i] >= Max[color[i]])
		{
			Max[color[i]] = f[i];
			if (color[i] == c1)
			{
				m1 = f[i];
				continue;
			}
			
			if (color[i] == c2)
			{
				if (Max[color[i]] > m1)
				{
					temp = c1, c1 = c2, c2 = temp;
					temp = m1, m1 = Max[color[i]], m2 = temp;
				}
				
				else
					m2 = f[i];
			}
			
			else
			{
				if (c2 == 0 || f[i] > m2)
				{
					m2 = f[i], c2 = color[i];
					if (m2 > m1)
					{
						temp = m1, m1 = m2, m2 = temp;
						temp = c1, c1 = c2, c2 = temp;
					}
				}
			}
		}		
	}
	
	printf("%I64d\n", Ans);
	return;
}