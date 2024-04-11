#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n, p[N], dp[N][2], prv[N][2];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	dp[1][0] = dp[1][1] = -inf;
	for (int i = 2; i <= n; ++i) {
		for (int x = 0; x < 2; ++x) {
			int val[2] = {inf, inf};
			int cur = x ? p[i] : -p[i];
			for (int y = 0; y < 2; ++y) {
				int last[2] = {y ? p[i - 1] : -p[i - 1], dp[i - 1][y]};
				if (last[0] > last[1]) swap(last[0], last[1]);
				if (last[1] == inf || last[0] > cur) continue;
				val[y] = (last[1] < cur ? last[0] : last[1]);
			}
			int id = (val[0] > val[1]);
			dp[i][x] = val[id];
			prv[i][x] = id;
		}
		if (min(dp[i][0], dp[i][1]) == inf)	{
			puts("NO");
			return;
		}
	}
	puts("YES");
	int cur = (dp[n][0] > dp[n][1]);
	for (int i = n; i; --i) {
		if (!cur) p[i] = -p[i];
		cur = prv[i][cur];
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", p[i], " \n"[i == n]);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}