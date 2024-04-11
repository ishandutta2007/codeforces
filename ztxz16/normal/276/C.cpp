#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, q, l, r, a[1000005], b[1000005], c[1000005];
long long i, Ans;

int main()
{
	scanf("%I64d %I64d", &n, &q);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	for (i = 1; i <= q; i++)
		scanf("%I64d %I64d", &l, &r), c[l]++, c[r + 1]--;
	for (i = 1; i <= n; i++)
		b[i] = b[i - 1] + c[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (i = 1; i <= n; i++)
		Ans += (a[i] * b[i]);
	printf("%I64d\n", Ans);
	return 0;
}