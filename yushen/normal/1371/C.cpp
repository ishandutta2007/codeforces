#include <bits/stdc++.h>
using namespace std;

int T;
long long a, b, n, m;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
		if (m > min(a, b))
		{
			puts("No");
			continue;
		}
		if (a + b < n + m)
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}