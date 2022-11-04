#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, i, j, s1, s2, G, a[100005], s[100005];

long long gcd(long long a, long long b);

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
		s1 += a[i], s[i] = s[i - 1] + a[i];
	for (i = 1; i < n; i++)
		s2 += (s[n] - s[i] - a[i] * (n - i));
	s2 *= 2;
	s2 += s1;
	s1 = n;
	if (s1 > s2)
		G = gcd(s1, s2);
	else
		G = gcd(s2, s1);
	printf("%I64d %I64d\n", s2 / G, s1 / G);
	return 0;
}

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}