#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005, p = 1e9 + 7;
int T, n;
long long f[Maxn][2];
int main()
{
	for (int i = 3; i <= 2000000; i++)
	{
		f[i][0] = f[i][1] = (f[i - 1][1] + 2 * f[i - 2][1]) % p;
		if ((i % 3) != 2)
			f[i][1] = (f[i - 1][0] + 2 * f[i - 2][0] + 1) % p;
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		printf("%lld\n", max(f[n][0], f[n][1]) * 4 % p);
	}
	return 0;
}