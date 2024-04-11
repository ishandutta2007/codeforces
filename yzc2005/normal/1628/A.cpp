#include <bits/stdc++.h>
using namespace std;
int n, a[200005], suf[200005];
bool vis[200005];
void solve() {
	scanf("%d", &n);
	memset(vis, false, n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	suf[n + 1] = 0;
	for (int i = n; i; --i) {
		suf[i] = suf[i + 1];
		vis[a[i]] = true;
		while (vis[suf[i]]) 
			++suf[i];
	}
	vector<int> b;
	for (int i = 1, j; i <= n; i = j + 1) {
		int val = suf[i];
		int cur = 0;
		set<int> s;
		for (j = i; j <= n; ++j) {
			s.insert(a[j]);
			while (s.count(cur))
				++cur;
			if (cur == val) {
				b.emplace_back(cur);
				break;
			} 
		}
	}
	printf("%u\n", b.size());
	for (auto x : b)
		printf("%d ", x);
	puts("");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}