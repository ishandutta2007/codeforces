#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 4e5 + 5;
int n, m;
ld L, lp[N], rp[N], s[N];
ld x[N], y[N], z[N], l[N];
int id[N], pos[N];
ld s1[N << 2], s2[N << 2];
bool lazy[N << 2];
ld ans;
inline void pushup(int p) {
	s1[p] = s1[p << 1] + s1[p << 1 | 1];
	s2[p] = s2[p << 1] + s2[p << 1 | 1];
}
inline void tag(int p) {
	s1[p] = s2[p] = 0;
	lazy[p] = true;
}
inline void pushdown(int p) {
	if (lazy[p]) {
		tag(p << 1);
		tag(p << 1 | 1);
		lazy[p] = false; 
	}
}
void activate(int p, int l, int r, int pos, ld x, ld y) {
	if (l == r) {
		s1[p] += y;
		s2[p] += x * y;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p);
	if (mid >= pos) activate(p << 1, l, mid, pos, x, y);
	else activate(p << 1 | 1, mid + 1, r, pos, x, y);
	pushup(p);
}
void clear(int p, int l, int r, int ll, int rr) {
	if (l >= ll && r <= rr) {
		tag(p);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p);
	if (mid >= ll) clear(p << 1, l, mid, ll, rr);
	if (mid < rr) clear(p << 1 | 1, mid + 1, r, ll, rr);
	pushup(p);
}
void query(int p, int l, int r, ld k) {
	if (l == r) {
		if (l < m) clear(1, 1, m, l + 1, m);
		ld x = ::x[id[l]], y = k / x;
		ans += y;
		activate(1, 1, m, l, x, -y);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p);
	if (s2[p << 1 | 1] >= k) {
		query(p << 1 | 1, mid + 1, r, k);
	} else {
		ans += s1[p << 1 | 1];
		query(p << 1, l, mid, k - s2[p << 1 | 1]);
	}
}
int main() {
	scanf("%d%Lf", &n, &L);
	for (int i = 1; i <= n; ++i)
		scanf("%Lf%Lf%Lf", &lp[i], &rp[i], &s[i]);
	l[++m] = lp[1];
	x[m] = 1;
	y[m] = 1e12, z[m] = l[m] / 2;
	lp[n + 1] = L;
	for (int i = 1; i <= n; ++i) {
		l[++m] = rp[i] - lp[i];
		x[m] = s[i] + 1;
		y[m] = l[m] / s[i], z[m] = l[m] / (s[i] + 2);
		l[++m] = lp[i + 1] - rp[i];
		x[m] = 1;
		y[m] = 1e12, z[m] = l[m] / 2;
	}
	iota(id + 1, id + m + 1, 1);
	sort(id + 1, id + m + 1, [&](int i, int j) {
		return x[i] < x[j];	
	});
	for (int i = 1; i <= m; ++i)
		pos[id[i]] = i;
	for (int i = 1; i <= m; ++i) {
		ans += z[i];
		y[i] -= z[i];
		l[i] -= z[i] * x[i];
		activate(1, 1, m, pos[i], x[i], y[i]);
		query(1, 1, m, l[i]);
	}
	printf("%.15Lf\n", ans);
	return 0;
}