#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e6 + 5;

int n, m, p;
struct Wp { int a, ca; } W[kN];
struct As { int b, cb; } A[kN];
struct Mt { int x, y, z; } M[kN];

ll seg[5 + (kN << 3)], tag[5 + (kN << 3)];
void Update(int cur) { seg[cur] = std::max(seg[cur << 1], seg[cur << 1 | 1]); }
void PushTag(int cur) {
	seg[cur << 1] += tag[cur]; seg[cur << 1 | 1] += tag[cur];
	tag[cur << 1] += tag[cur]; tag[cur << 1 | 1] += tag[cur];
	tag[cur] = 0;
}
void Modify(int cur, int l, int r, int ql, int qr, ll v) {
	if(ql > qr) return;
	if(ql <= l && r <= qr) seg[cur] += v, tag[cur] += v;
	else {
		PushTag(cur);
		int mid = (l + r) >> 1;
		if(ql <= mid) Modify(cur << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(cur << 1 | 1, mid + 1, r, ql, qr, v);
		Update(cur);
	}
}
void Set(int cur, int l, int r, int q, ll v) {
	if(l == r) seg[cur] = v;
	else {
		int mid = (l + r) >> 1;
		if(q <= mid) Set(cur << 1, l, mid, q, v);
		else Set(cur << 1 | 1, mid + 1, r, q, v);
		Update(cur);
	}
}
ll Query(int cur, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[cur];
	PushTag(cur);
	int mid = (l + r) >> 1; ll ret = -1e9;
	if(ql <= mid) ret = std::max(Query(cur << 1, l, mid, ql, qr), ret);
	if(qr > mid) ret = std::max(Query(cur << 1 | 1, mid + 1, r, ql, qr), ret);
	return ret;
}

int main() {
	memset(seg, ~0x3f, sizeof(seg));
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; ++i) scanf("%d%d", &W[i].a, &W[i].ca);
	for(int i = 1; i <= m; ++i) scanf("%d%d", &A[i].b, &A[i].cb), Set(1, 1, kN, A[i].b, -A[i].cb);
	for(int i = 1; i <= p; ++i) scanf("%d%d%d", &M[i].x, &M[i].y, &M[i].z);
	std::sort(W + 1, W + 1 + n, [](Wp x, Wp y) { return x.a < y.a; });
	//std::sort(A + 1, A + 1 + m, [](As x, As y) { return x.b > y.b; });
	std::sort(M + 1, M + 1 + p, [](Mt x, Mt y) { return x.x < y.x; });
	ll ans = -100000000000;
	for(int i = 1, j = 1; i <= n; ++i) {
		for(; j <= p && M[j].x < W[i].a; ++j)
			Modify(1, 1, kN, M[j].y + 1, kN, M[j].z);
		//for(int j = 1; j <= 5; ++j) printf("%d ", Query(1, 1, kN, j, j));
		//printf("\n");
		ans = std::max(ans, seg[1] - W[i].ca);
	}
	printf("%lld", ans);
	return 0;
}