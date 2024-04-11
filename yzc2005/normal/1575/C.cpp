#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7; 
int n, m, k, a[200005], tot;
struct node {
	int cnt[200005], res, sum;
	inline int get() {
		int ans = res;
		for (int i = 0; i < k; ++i) 
			ans = (ans + 1ll * cnt[i] * (cnt[i] - 1) / 2) % P;
		if (!tot) ans = (ans + 1) % P;
		return ans;		
	}
} dp[18], ans;
inline node operator+(const node &lhs, const node &rhs) {
	node x;
	x.sum = (lhs.sum + rhs.sum) % k;
	x.res = (lhs.res + rhs.res) % P;
	for (int i = 0; i < k; ++i) {
		x.cnt[i] = (lhs.cnt[i] + rhs.cnt[(i - lhs.sum + k) % k]) % P;
		x.res = (x.res + 1ll * lhs.cnt[(i - tot + k) % k] * rhs.cnt[(i - lhs.sum + k) % k]) % P;
	}
	return x;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		tot = (tot + a[i]) % k;
	}
	dp[0].sum = tot;
	tot = 1ll * tot * m % k;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur = (cur + a[i]) % k;
		int val = dp[0].cnt[(cur - tot + k) % k];
		dp[0].res = (dp[0].res + val) % P;				
		++dp[0].cnt[cur];
	}
	for (int i = 1; i < 18; ++i)
		dp[i] = dp[i - 1] + dp[i - 1];
	for (int i = 17; ~i; --i) 
		if (m >> i & 1) ans = ans + dp[i];
	printf("%d\n", ans.get());
	return 0;
}