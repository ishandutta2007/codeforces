#include <bits/stdc++.h>
using namespace std;
int n, c[100005];
char s[100005], t[100005];
inline void modify(int p) {
	p = n - p + 1;
	for (; p <= n; p += p & -p)
		++c[p];
}
inline int query(int p) {
	int res = 0;
	p = n - p + 1;
	for (; p; p -= p & -p)
		res += c[p];
	return res;
}
vector<int> pos[26];
inline int get(int x) {
	return x + query(x);
}
void solve() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	long long sum = 0;
	long long ans = 1e18;
	memset(c + 1, 0, n * 4);
	for (int i = n; i; --i) 
		pos[s[i] -= 'a'].emplace_back(i);
	for (int i = 1; i <= n; ++i) {
		long long cur = 1e18;
		t[i] -= 'a';
		for (int j = 0; j < t[i]; ++j)
			if (!pos[j].empty()) cur = min(cur, (long long) get(pos[j].back()) - i);
		ans = min(ans, sum + cur);
		if (pos[t[i]].empty()) break;
		int p = pos[t[i]].back();
		pos[t[i]].pop_back();
		sum += get(p) - i;
		modify(p);
	}
	for (int i = 0; i < 26; ++i)
		pos[i].clear();
	printf("%lld\n", ans > 1e12 ? -1 : ans);
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}