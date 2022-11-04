#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define mo 1000000007

using namespace std;

struct TN
{
	long long a, b;
}a[100005];

long long n, i, j, Now, A[100005];

long long cmp(TN a, TN b)
{
	if (a.a < b.a || (a.a == b.a && a.b < b.b))
		return 1;
	return 0;
}

void Add(long long a, long long b);
long long Ask(long long a);

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i].a), a[i].b = i;
	sort(a + 1, a + n + 1, cmp);
	Add(1, 1);
	a[n + 1].a = a[n].a + 1;
	for (i = 1; i <= n; i++)
	{
		Now = 0;
		for (j = i; a[j].a == a[i].a; j++)
		{
			long long x = Ask(a[j].b + 1) - Ask(Now);
			x %= mo;
			x *= (a[j].a % mo);
			x %= mo;
			Add(a[j].b + 1, x);
			Now = a[j].b;
		}
		
		i = j - 1;
	}
	
	cout << ((Ask(n + 1) + mo - 1) % mo) << endl;
	return 0;
}

void Add(long long a, long long b)
{
	long long i;
	for (i = a; i <= n + 1; i += (i & (0 - i)))
		A[i] += b, A[i] %= mo;
	return;
}

long long Ask(long long a)
{
	long long i, ret = 0;
	for (i = a; i > 0; i -= (i & (0 - i)))
		ret += A[i], ret %= mo;
	return ret;
}