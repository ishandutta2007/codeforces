#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register

const int N = 200005, M = N * 35;
int n, tot, a[N], rt[N], ls[M], rs[M], val[M];
ll ans;

int update(int p, int l, int r, int pos) {
	int q = ++tot;
	val[q] = val[p] + 1;
	ls[q] = ls[p], rs[q] = rs[p];
	if(l == r) return q;
	int mid = l + r >> 1;
	if(mid >= pos) ls[q] = update(ls[p], l, mid, pos);
	else rs[q] = update(rs[p], mid + 1, r, pos);
	return q;
} 

int query(int p, int q, int l, int r, int ql, int qr) {
	if(l >= ql && r <= qr) return val[p] - val[q];
	int mid = l + r >> 1, ret = 0;
	if(mid >= ql) ret += query(ls[p], ls[q], l, mid, ql, qr);
	if(mid < qr) ret += query(rs[p], rs[q], mid + 1, r, ql, qr);
	return ret;
}

int main() {
	scanf("%d", &n);
	for(rg int i = 1; i <= n; ++i) scanf("%d", &a[i]), rt[i] = update(rt[i - 1], 1, 1e9, a[i]);
	for(rg int i = 1; i <= n; ++i) { 
		int l = i + 1, r = min(n, a[i]);
		if(l > r) continue;
		ans += query(rt[r], rt[l - 1], 1, 1e9, i, 1e9);
	}
	printf("%lld\n", ans);
	return 0;
}