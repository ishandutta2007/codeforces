#include <bits/stdc++.h>

typedef long long ll;

const int kN = 2e5 + 5;
const ll kInf = 1e18;

int n, a[kN], p[kN];
ll T[kN << 3], tag[kN << 3];
void Update(int cur) { T[cur] = std::min(T[cur << 1], T[cur << 1 | 1]); }
void PushTag(int cur) {
	tag[cur << 1] += tag[cur]; tag[cur << 1 | 1] += tag[cur];
	T[cur << 1] += tag[cur]; T[cur << 1 | 1] += tag[cur];
	tag[cur] = 0;
}
void Build(int cur, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(cur << 1, l, mid);
		Build(cur << 1 | 1, mid + 1, r);
		Update(cur);
	} else T[cur] = 0;
}
void Modify(int cur, int l, int r, int ql, int qr, ll v) {
	if(qr < ql) return;
	if(ql <= l && r <= qr) T[cur] += v, tag[cur] += v;
	else {
		int mid = (l + r) >> 1;
		PushTag(cur);
		if(ql <= mid) Modify(cur << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(cur << 1 | 1, mid + 1, r, ql, qr, v);
		Update(cur);
	}
}

int main() {
	memset(T, 0, sizeof(T));
	scanf("%d", &n);
	Build(1, 1, n + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", p + i);
	for(int i = 1; i <= n; ++i) { scanf("%d", a + i); Modify(1, 1, n + 1, p[i] + 1, n + 1, a[i]); }
	ll ans = kInf;
	for(int i = 1; i < n; ++i) {
		Modify(1, 1, n + 1, 1, p[i], a[i]);
		Modify(1, 1, n + 1, p[i] + 1, n + 1, -a[i]);
		ans = std::min(ans, T[1]);
	}
	printf("%lld", ans);
	return 0;
}