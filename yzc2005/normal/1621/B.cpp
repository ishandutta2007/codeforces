#include <bits/stdc++.h>
using namespace std;
int n, l[100005], r[100005], c[100005];
void solve() {
	scanf("%d", &n);
	int p1 = 0, p2 = 0;
	int pos = 0, len = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &c[i]);
		if (!p1 || l[i] < l[p1] || (l[i] == l[p1] && c[i] < c[p1])) p1 = i;
		if (!p2 || r[i] > r[p2] || (r[i] == r[p2] && c[i] < c[p2])) p2 = i;
		int cl = r[i] - l[i] + 1;
		if (!pos || (cl > len || (cl == len && c[i] < c[pos]))) pos = i, len = cl;
		int ans = c[p1];
		if (p1 != p2) ans += c[p2];
		if (len == r[p2] - l[p1] + 1) ans = min(ans, c[pos]);
		printf("%d\n", ans);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}