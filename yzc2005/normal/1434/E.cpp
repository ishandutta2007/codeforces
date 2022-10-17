#include <bits/stdc++.h>
using namespace std;
int n, v[100005], nxt[100005];
int pos[455];
struct DSU {
	int par[100005], mx[100005];
	void init(int n) {
		iota(par, par + n + 2, 0);
		memset(mx, -1, (n + 2) * 4);
	}
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	void fill(int l, int r, int x) {
		int cur = find(l);
		while (cur <= r) {
			mx[cur] = x;
			int nxt = find(cur + 1);
			cur = par[cur] = nxt;
		}
	}
} t[455];
int solve() {
	scanf("%d", &n);
	memset(nxt, -1, sizeof nxt);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]), nxt[v[i]] = i;
	int m = v[n];
	nxt[m + 1] = n + 1;
	for (int i = m; ~i; --i)
		if (nxt[i] == -1) nxt[i] = nxt[i + 1];
	int B = sqrt(2 * m) + 3;
	for (int i = 0; i <= B; ++i)
		t[i].init(n); 
	set<int> st;
	pos[0] = m;
	for (int i = n; i; --i) {
		int sg = 0, val = m;
		while (true) {
			int cur = t[sg].mx[i];
			if (cur == -1) break;
			val = min(val, v[cur] - v[i] - 1);
			pos[++sg] = val;
		}
		st.insert(sg);
		pos[sg + 1] = 0;
		for (int x = 0; x <= sg; ++x) {
			int l = max(0, v[i] - pos[x]), r = max(0, v[i] - pos[x + 1] - 1);
			l = nxt[l], r = nxt[r + 1] - 1;
			if (l > r || l > i - 1) continue;
			if (l > r) continue;
			t[x].fill(l, r, i);			
		}
	}
	int ans = 0;
	while (st.count(ans))
		++ans;
	return ans;
}
int main() {
	int t, ans = 0;
	scanf("%d", &t);
	while (t--)
		ans ^= solve();
	puts(ans ? "YES" : "NO");
	return 0;
}