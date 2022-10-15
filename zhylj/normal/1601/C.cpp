#include <bits/stdc++.h>

#define gc() getchar()
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
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e6 + 5;

int n, m, c, a[N], b[N], d[N];

struct Bit {
	int tr[N];
	void Init(int x) {
		for(int i = 1; i <= x; ++i)
			tr[i] = 0;
	}
	void Modify(int o, int v) {
		for(; o <= c; o += o & -o)
			tr[o] += v;
	}
	int Query(int o) {
		int ret = 0;
		for(; o; o -= o & -o) ret += tr[o];
		return ret;
	}
} A;
ll Solve1() {
	ll ret = 0;
	for(int i = 1; i <= n; ++i) {
		ret += A.Query(c) - A.Query(a[i]);
		A.Modify(a[i], 1);
	}
	return ret;
}

struct Seg {
	int seg[N << 3], tag[N << 3];
	void Update(int o) {
		seg[o] = std::min(seg[o << 1], seg[o << 1 | 1]);
	}
	void PushTag(int o) {
		if(tag[o]) {
			seg[o << 1] += tag[o];
			seg[o << 1 | 1] += tag[o];
			tag[o << 1] += tag[o];
			tag[o << 1 | 1] += tag[o];
			tag[o] = 0;
		}
	}
	void Init(int x) {
		for(int i = 1; i <= x << 3; ++i)
			seg[i] = 0, tag[i] = 0;
	}
	void Modify(int o, int l, int r, int ql, int qr, int v) {
		if(ql <= l && r <= qr) tag[o] += v, seg[o] += v;
		else {
			int mid = (l + r) >> 1;
			PushTag(o);
			if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
			if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
			Update(o);
		}
	}
	void Output(int o, int l, int r) {
		if(l < r) {
			int mid = (l + r) >> 1;
			PushTag(o);
			Output(o << 1, l, mid);
			Output(o << 1 | 1, mid + 1, r);
		} else printf("%d ", seg[o]);
	}
} B;
std::vector <int> pos[N];
ll Solve2() {
	ll ret = 0;
	for(int i = 1; i <= n; ++i)
		B.Modify(1, 0, n, i, i, i);
	for(int i = 1; i <= m; ++i) {
		if(b[i - 1] != b[i]) {
			for(int j = b[i - 1]; j <= b[i]; ++j) {
				for(int k : pos[j]) {
					if(j != b[i]) B.Modify(1, 0, n, 0, k - 1, 1);
					if(j != b[i - 1]) B.Modify(1, 0, n, k, n, -1);
				}
			}
		}
		ret += B.seg[1];
	}
	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]), d[i] = a[i];
		for(int i = 1; i <= m; ++i) rd(b[i]), d[i + n] = b[i];
		std::sort(d + 1, d + n + m + 1);
		c = std::unique(d + 1, d + n + m + 1) - d - 1;
		for(int i = 1; i <= n; ++i) {
			a[i] = std::lower_bound(d + 1, d + c + 1, a[i]) - d;
			pos[a[i]].push_back(i);
		}
		for(int i = 1; i <= m; ++i)
			b[i] = std::lower_bound(d + 1, d + c + 1, b[i]) - d;
		std::sort(b + 1, b + m + 1);
		ll ans = Solve1() + Solve2();
		printf("%lld\n", ans);
		A.Init(n + m); B.Init(n);
		for(int i = 1; i <= n + m; ++i)
			pos[i].clear();
	} return 0;
}