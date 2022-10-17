#include <bits/stdc++.h>
using namespace std;
int n, p[300005];
struct node {
	long long x;
	int pre;
	node(long long a = 0, int b = 0) : x(a), pre(b) {}
	inline bool operator<(const node &rhs) const {
		return x < rhs.x;
	}
} dp[300005];
vector<int> op;
inline void push(int x) {
	int val = min(p[x], p[x + 1]);
	if (!val) return;
	op.emplace_back(x);
	p[x] -= val;
	p[x + 1] -= val;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 	
		scanf("%d", &p[i]);
	dp[1] = node(p[1], 0);
	node val = node(-1e18, 0);
	for (int i = 2; i <= n; ++i) {
		if (i > 4) val = max(val, node(dp[i - 5].x - max(0, p[i - 4] - p[i - 3]), i - 5));  
		dp[i] = node(val.x - max(0, p[i - 1] - p[i - 2]), val.pre);
		dp[i] = max(dp[i], node(dp[i - 2].x + p[i] - p[i - 1], i - 2));
		if (i > 2) dp[i] = max(dp[i], node(dp[i - 3].x + p[i] - abs(p[i - 1] - p[i - 2]), i - 3));
		if (i > 3) dp[i] = max(dp[i], node(dp[i - 4].x + p[i] - max(0, p[i - 3] + p[i - 1] - p[i - 2]), i - 4));
	}
	int pos = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		long long cur = dp[i].x - max(0, p[i + 1] - p[i + 2]);
		if (cur > ans) ans = cur, pos = i;
	}
	vector<int> v = {n + 1};
	while (pos) {
		v.emplace_back(pos);
		pos = dp[pos].pre;
	}
	v.emplace_back(0);
	reverse(v.begin(), v.end());
	for (int i = 0; i + 1 < (int) v.size(); ++i) {
		int l = v[i] + 1, r = v[i + 1] - 1;
		if (l > r) continue;
		push(l);
		for (int x = r - 1; x > l; --x)
			push(x);
		push(l - 1);
		push(r);
	}
	printf("%d\n", (int) op.size());
	for (auto x : op)
		printf("%d\n", x);
	return 0;
}