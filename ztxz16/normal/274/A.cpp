#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, i, k, a[100005];
ll Ans, hash[100005];

void Work(ll k);

int main()
{
	scanf("%I64d %I64d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
	{
		if (hash[i] == 1)
			continue;
		else
			Ans++, Work(a[i] * k);
	}
	
	printf("%I64d\n", Ans);
	return 0;
}

void Work(ll k)
{
	ll l = 1, r = n, mid;
	while (l < r)
	{
		mid = ((l + r) >> 1);
		if (a[mid] < k)
			l = mid + 1;
		else
			r = mid;
	}
	
	if (a[l] == k)
		hash[l] = 1;
	return;
}