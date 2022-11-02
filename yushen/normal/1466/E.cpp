#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7, Maxn = 5000005;
int T, n;
long long ans, ans1[Maxn], ans2[Maxn], a[Maxn], cnt[65];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		memset(ans1, 0, sizeof(long long[n + 1]));
		memset(ans2, 0, sizeof(long long[n + 1]));
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			for (int j = 0; j <= 60; j++)
				if (a[i] & (1LL << j)) cnt[j]++;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= 60; j++)
			{
				if (a[i] & (1LL << j)) (ans1[i] += (1LL << j) % p * cnt[j]) %= p, (ans2[i] += (1LL << j) % p * n) %= p;
				else (ans2[i] += (1LL << j) % p * cnt[j]) %= p;
			}
		for (int i = 0; i <= n; i++)
			(ans += ans1[i] * ans2[i]) %= p;
		printf("%lld\n", ans);
	}
	return 0;
}