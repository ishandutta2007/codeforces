#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = N << 5, R = 1e9;
int n, c[N], r[N], q;
int tot, rt[N], ls[M], rs[M];
long long sum1[M], sum2[M];
void insert(int &p, int q, int l, int r, int pos, int v1, int v2) {
	p = ++tot;
	sum1[p] = sum1[q] + v1;
	sum2[p] = sum2[q] + v2;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (mid >= pos) 
		rs[p] = rs[q], insert(ls[p], ls[q], l, mid, pos, v1, v2);
	else 
		ls[p] = ls[q], insert(rs[p], rs[q], mid + 1, r, pos, v1, v2);
}
long long query1(int p, int q, int l, int r, int ll, int rr) {
	if (l >= ll && r <= rr) return sum1[p] - sum1[q];
	int mid = (l + r) >> 1;
	long long res = 0;
	if (mid >= ll) res += query1(ls[p], ls[q], l, mid, ll, rr);
	if (mid < rr) res += query1(rs[p], rs[q], mid + 1, r, ll, rr);
	return res;
}
long long query2(int p, int q, int l, int r, int ll, int rr) {
	if (l >= ll && r <= rr) return sum2[p] - sum2[q];
	int mid = (l + r) >> 1;
	long long res = 0;
	if (mid >= ll) res += query2(ls[p], ls[q], l, mid, ll, rr);
	if (mid < rr) res += query2(rs[p], rs[q], mid + 1, r, ll, rr);
	return res;
}
long long query(int l, int r, int t) { // min(r * t, c)
	if (l > r) return 0;
	long long res = query2(rt[r], rt[l - 1], 1, R, 1, min(t, R));
	if (t < R) res += query1(rt[r], rt[l - 1], 1, R, t + 1, R) * t;
	return res;
}
struct node {
	int l, r, tim, offset; // offset + (cur - tim) * c
	inline bool operator<(const node &rhs) const { return l < rhs.l; } 
};
set<node> segs;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &c[i], &r[i]);
		insert(rt[i], rt[i - 1], 1, R, (c[i] + r[i] - 1) / r[i], r[i], c[i]);
	}
	segs.insert({1, n, -R, 0});
	scanf("%d", &q);
	long long ans = 0;	
	while (q--) {
		int cur;
		long long h;
		scanf("%d%lld", &cur, &h);
		while (!segs.empty()) {
			auto it = segs.begin();
			int l = it->l, r = it->r, t = cur - it->tim;
			if (l == r) {
				int x = min(1ll * c[l], it->offset + 1ll * t * ::r[l]);
				segs.erase(it);
				if (h >= x) {
					h -= x;
				} else {
					segs.insert({l, l, cur, x - h}), h = 0;
					break;
				}
			} else {
				long long val = query(l, r, t);
				if (val <= h) {
					h -= val;
					segs.erase(it);
				} else {
					int L = l, R = r, pos = l - 1;
					while (L <= R) {
						int mid = (L + R) >> 1;
						if (query(l, mid, t) <= h) pos = mid, L = mid + 1;
						else R = mid - 1;
					}
					int tmp = it->tim;
					segs.erase(it);
					h -= query(l, pos++, t);
					int x = min(1ll * c[pos], 1ll * t * ::r[pos]);
					segs.insert({pos, pos, cur, x - h}), h = 0;
					if (pos < r) segs.insert({pos + 1, r, tmp, 0});
					break;
				}
			}
		}
		if (segs.empty()) segs.insert({1, n, cur, 0});
		else if (segs.begin()->l != 1) segs.insert({1, segs.begin()->l - 1, cur, 0});
		ans += h;
	}
	printf("%lld\n", ans);
	return 0;
}