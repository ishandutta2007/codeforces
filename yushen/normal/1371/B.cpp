#include <bits/stdc++.h>
using namespace std;

int T, n, r;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &r);
		printf("%lld\n", (r >= n ? 1 : 0) + (long long) min(r, n - 1) * (min(r, n - 1) + 1) / 2);
	}
	return 0;
}