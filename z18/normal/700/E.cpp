#include <bits/stdc++.h>
#define ls son[x][0]
#define rs son[x][1]
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 2e5, maxm = maxn * 2, maxk = maxn * 40;
int n, tot, at, ch[maxm + 3][26], lnk[maxm + 3], len[maxm + 3], rt[maxm + 3], pnt[maxm + 3];
int cnt, son[maxk + 3][2], sum[maxk + 3], c[maxn + 3], o[maxm + 3], dp[maxm + 3], f[maxm + 3];
char s[maxn + 3];

void modify(int &x, int l, int r, int y) {
	if (!x) x = ++cnt;
	sum[x]++;
	if (l == r) return;
	if (y <= mid) modify(ls, l, mid, y);
	else modify(rs, mid + 1, r, y);
}

int query(int x, int l, int r, int lx, int rx) {;
	if (!x) return 0;
	if (l >= lx && r <= rx) return sum[x];
	int res = 0;
	if (lx <= mid) res += query(ls, l, mid, lx, rx);
	if (rx > mid) res += query(rs, mid + 1, r, lx, rx);
	return res;
}

int merge(int x, int y) {
	if (!x || !y) return x + y;
	int z = ++cnt;
	sum[z] = sum[x] + sum[y];
	son[z][0] = merge(son[x][0], son[y][0]);
	son[z][1] = merge(son[x][1], son[y][1]);
	return z;
}

void extend(int k, int i) {
	int x = ++tot, y = at;
	modify(rt[x], 1, n, i), pnt[x] = i;
	len[x] = len[y] + 1, at = x;
	while (y && !ch[y][k]) ch[y][k] = x, y = lnk[y];
	if (!y) return lnk[x] = 1, void();
	int z = ch[y][k];
	if (len[z] == len[y] + 1) lnk[x] = z; else {
		int t = ++tot;
		len[t] = len[y] + 1, lnk[t] = lnk[z];
		memcpy(ch[t], ch[z], sizeof(ch[t]));
		while (ch[y][k] == z) ch[y][k] = t, y = lnk[y];
		lnk[x] = lnk[z] = t;
	}
}

int main() {
	scanf("%d %s", &n, s + 1);
	tot = at = 1;
	for (int i = 1; i <= n; i++) extend(s[i] - 'a', i);
	for (int i = 1; i <= tot; i++) c[len[i]]++;
	for (int i = 1; i <= n; i++) c[i] += c[i - 1];
	for (int i = 1; i <= tot; i++) o[c[len[i]]--] = i;
	for (int _ = tot, i; i = o[_], _ >= 2; _--) rt[lnk[i]] = merge(rt[lnk[i]], rt[i]), pnt[lnk[i]] = pnt[i];
	dp[1] = 0, f[1] = 1;
	int ans = 0;
	for (int _ = 2, i; i = o[_], _ <= tot; _++) {
		assert(pnt[i] > 0);
		if (lnk[i] == 1 || query(rt[f[lnk[i]]], 1, n, pnt[i] - len[i] + len[f[lnk[i]]], pnt[i]) >= 2) dp[i] = dp[lnk[i]] + 1, f[i] = i;
		else dp[i] = dp[lnk[i]], f[i] = f[lnk[i]];
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}