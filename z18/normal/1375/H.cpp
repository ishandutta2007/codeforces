#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define lft first
#define rht second
using namespace std;

typedef pair<int, int> range;
const int maxn = 1 << 13, maxq = 1 << 16;
int n, q, a[maxn + 5], cnt, res[maxq + 5], cur, vis[maxn + 5];
vector<int> seq[maxn + 5];
vector<range> ans;
map<range, int> M[maxn + 5];

#define ls (x << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)

void build(int x, int l, int r) {
	if (l == r) return;
	rep(i, 0, seq[x].size() - 1) {
		int t = seq[x][i];
		if (a[t] <= mid) seq[ls].push_back(t);
		else seq[rs].push_back(t);
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

int query(int x, int l, int r, int lx, int rx) {
	if (l == r) return seq[x][0];
	if (M[x].count(range(lx, rx))) return M[x][range(lx, rx)];
	int &ret = M[x][range(lx, rx)] = 0;
	++cur;
	rep(i, lx, rx) {
		int t = seq[x][i];
		vis[t] = cur;
	}
	int l_lx = -1, l_rx, r_lx = -1, r_rx;
	rep(i, 0, seq[ls].size() - 1) {
		int t = seq[ls][i];
		if (vis[t] == cur) {
			if (l_lx == -1) l_lx = i;
			l_rx = i;
		}
	}
	rep(i, 0, seq[rs].size() - 1) {
		int t = seq[rs][i];
		if (vis[t] == cur) {
			if (r_lx == -1) r_lx = i;
			r_rx = i;
		}
	}
	if (r_lx == -1) return ret = query(ls, l, mid, l_lx, l_rx);
	if (l_lx == -1) return ret = query(rs, mid + 1, r, r_lx, r_rx);
	int p = query(ls, l, mid, l_lx, l_rx);
	int q = query(rs, mid + 1, r, r_lx, r_rx);
	ans.push_back(range(p, q));
	return ret = ++cnt;
}

int main() {
	scanf("%d %d", &n, &q);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) seq[1].push_back(i);
	build(1, 1, n);
	cnt = n;
	for (int i = 1, l, r; i <= q; i++) {
		scanf("%d %d", &l, &r);
		res[i] = query(1, 1, n, l - 1, r - 1);
	}
	printf("%d\n", cnt);
	rep(i, 0, ans.size() - 1) printf("%d %d\n", ans[i].lft, ans[i].rht);
	rep(i, 1, q) printf("%d%c", res[i], " \n"[i == q]);
	return 0;
}