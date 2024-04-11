#include <bits/stdc++.h>

char buf[1 << 21], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
#define mn(o) tr[o].mn
#define mn_cnt(o) tr[o].mn_cnt
#define a_tag(o) tr[o].a_tag
#define h_tag(o) tr[o].h_tag
#define h_cnt(o) tr[o].h_cnt
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 3e5 + 5, Inf = 0x3f3f3f3f;

struct Seg {
	int mn, mn_cnt, a_tag, h_tag;
	ll h_cnt;
	Seg() { mn = Inf; }
} tr[N << 3];
void Update(int o) {
	mn(o) = std::min(mn(o << 1), mn(o << 1 | 1));
	mn_cnt(o) = (mn(o << 1) == mn(o) ? mn_cnt(o << 1) : 0) +
		(mn(o << 1 | 1) == mn(o) ? mn_cnt(o << 1 | 1) : 0);
	h_cnt(o) = h_cnt(o << 1) + h_cnt(o << 1 | 1);
}
void AddTag(int o, int fa_mn, int h, int a) {
	if(a) {
		mn(o) += a;
		a_tag(o) += a;
	}
	if(h && fa_mn >= mn(o)) {
		h_cnt(o) += h * mn_cnt(o);
		h_tag(o) += h;
	}
}
void PushTag(int o) {
	AddTag(o << 1, mn(o), h_tag(o), a_tag(o));
	AddTag(o << 1 | 1, mn(o), h_tag(o), a_tag(o));
	h_tag(o) = a_tag(o) = 0;
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else mn(o) = l, mn_cnt(o) = 1;
}
void AddItv(int o, int l, int r, int ql, int qr, int h, int a) {
	if(ql <= l && r <= qr) AddTag(o, qr, h, a);
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(ql <= mid) AddItv(o << 1, l, mid, ql, qr, h, a);
		if(qr > mid) AddItv(o << 1 | 1, mid + 1, r, ql, qr, h, a);
		Update(o);
	}
}
ll Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return h_cnt(o);
	int mid = (l + r) >> 1; ll ret = 0;
	PushTag(o);
	if(ql <= mid) ret += Query(o << 1, l, mid, ql, qr);
	if(qr > mid) ret += Query(o << 1 | 1, mid + 1, r, ql, qr);
	return ret;
}

int n, top_1, top_2, p[N], st_1[N], st_2[N]; ll ans[N];
std::vector <pii> query[N];
void Calc() {
	Build(1, 1, n);
	for(int i = 1; i <= n; ++i) {
		while(top_1 && p[st_1[top_1]] < p[i]) {
			int l = st_1[top_1 - 1], r = st_1[top_1];
			AddItv(1, 1, n, l + 1, r, 0, -p[r]);
			--top_1;
		}
		AddItv(1, 1, n, st_1[top_1] + 1, i, 0, p[i]);
		st_1[++top_1] = i;
		while(top_2 && p[st_2[top_2]] > p[i]) {
			int l = st_2[top_2 - 1], r = st_2[top_2];
			AddItv(1, 1, n, l + 1, r, 0, p[r]);
			--top_2;
		}
		AddItv(1, 1, n, st_2[top_2] + 1, i, 0, -p[i]);
		st_2[++top_2] = i;
		AddItv(1, 1, n, 1, i, 1, 0);
		for(pii j : query[i])
			ans[j.fi] = Query(1, 1, n, j.se, i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			int x, y; rd(x, y);
			p[x] = y;
		}
		query[n].push_back(mkp(1, 1));
		Calc();
		printf("%lld\n", ans[1]);
	} return 0;
}