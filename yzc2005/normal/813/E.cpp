#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, k, a[N], nxt[N], q;
vector <int> b[N];

int rt[N], ls[N << 5], rs[N << 5], val[N << 5], cnt;
void change(int &p, int q, int l, int r, int pos) {
	p = ++cnt, val[p] = val[q] + 1;
	if(l == r) return; int mid = l + r >> 1;
	if(mid >= pos) change(ls[p], ls[q], l, mid, pos), rs[p] = rs[q];
	else change(rs[p], rs[q], mid + 1, r, pos), ls[p] = ls[q];
}
int query(int p, int q, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return val[p] - val[q];
	int mid = l + r >> 1, res = 0;
	if(mid >= ql) res += query(ls[p], ls[q], l, mid, ql, qr);
	if(mid < qr) res += query(rs[p], rs[q], mid + 1, r, ql, qr);
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[a[i]].push_back(i);
	for(int i = 1; i <= N - 5; ++i) 
		for(int j = 0; j < b[i].size(); ++j) {
			if(j + k < b[i].size()) nxt[b[i][j]] = b[i][j + k];
			else nxt[b[i][j]] = n + 1;
		}
	for(int i = 1; i <= n; ++i) change(rt[i], rt[i - 1], 1, n + 1, nxt[i]);
	scanf("%d", &q); 
	for(int i = 1, l, r, ans = 0; i <= q; ++i) {
		scanf("%d%d", &l, &r);
		l = (l + ans) % n + 1, r = (r + ans) % n + 1;
		if(l > r) swap(l, r);
		printf("%d\n", ans = query(rt[r], rt[l - 1], 1, n + 1, r + 1, n + 1));
	}
}