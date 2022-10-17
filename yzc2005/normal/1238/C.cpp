#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int t, n, h, b[N], a[N], dp[N];
bool open[N];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d", &h, &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		a[n + 1] = b[n + 1] = 0; for(int i = n; i; --i) a[i] = a[i + 1] + min(b[i] - b[i + 1], 2);
		h = a[1]; for(int i = 1; i <= h; ++i) open[i] = 0, dp[i - 1] = 1e9;
		for(int i = 1; i <= n; ++i) open[a[i]] = 1;
		dp[h] = 0, dp[h + 1] = 1e9;
		for(int i = h - 1; i; --i) {
			if(open[i]) dp[i] = min(dp[i + 1] + 1, dp[i + 2] + 1 - open[i + 1]);
			else dp[i] = min(dp[i + 1], dp[i + 2] + 2 - open[i + 1]);
		}
		printf("%d\n", min(dp[2], dp[1]));
	}
}