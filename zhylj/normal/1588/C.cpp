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
#define mn(o) seg[o].mn
#define mn_cnt(o) seg[o].mn_cnt
#define tag(o) seg[o].tag
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 3e5 + 5;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;

int n; ll a[N];

struct SegTree {
	struct Seg {
		ll mn, tag;
		int mn_cnt;
	} seg[N << 3];
	void Update(int o) {
		mn(o) = std::min(mn(o << 1), mn(o << 1 | 1));
		mn_cnt(o) = 0;
		if(mn(o << 1) == mn(o)) mn_cnt(o) += mn_cnt(o << 1);
		if(mn(o << 1 | 1) == mn(o)) mn_cnt(o) += mn_cnt(o << 1 | 1);
	}
	void PushTag(int o) {
		if(tag(o)) {
			mn(o << 1) += tag(o);
			mn(o << 1 | 1) += tag(o);
			tag(o << 1) += tag(o);
			tag(o << 1 | 1) += tag(o);
			tag(o) = 0;
		}
	}
	void Build(int o, int l, int r, ll s[], int d) {
		if(l < r) {
			int mid = (l + r) >> 1;
			tag(o) = 0;
			Build(o << 1, l, mid, s, d);
			Build(o << 1 | 1, mid + 1, r, s, d);
			Update(o);
		} else {
			mn(o) = (l % 2 == d ? s[l] : INFLL);
			mn_cnt(o) = (l % 2 == d ? 1 : 0);
			tag(o) = 0;
		}
	}
	void Modify(int o, int l, int r, int ql, int qr, ll v) {
		if(ql <= l && r <= qr) tag(o) += v, mn(o) += v;
		else {
			int mid = (l + r) >> 1;
			PushTag(o);
			if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
			if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
			Update(o);
		}
	}
	/*int Query(int o, int l, int r, int ql) {
		if(ql <= l) return mn(o) == 0 ? mn_cnt(o) : 0;
		else if(l == r) return 0;
		else {
			int mid = (l + r) >> 1, ret = 0;
			PushTag(o);
			if(ql <= mid) ret += Query(o << 1, l, mid, ql);
			if(mn(o << 1) >= 0) ret += Query(o << 1 | 1, mid + 1, r, ql);
			return ret;
		}
	}*/
	void Output(int o, int l, int r) {
		if(l == r) {
			if(mn_cnt(o)) printf("%lld ", mn(o));
			else printf("x ");
		} else {
			int mid = (l + r) >> 1;
			PushTag(o);
			Output(o << 1, l, mid);
			Output(o << 1 | 1, mid + 1, r);
		}
	}
} A, B;
int Query(int o, int l, int r, int ql) {
	//if(A.mn(o) > 0 && B.mn(o) > 0) return 0;
	if(l == r) return (A.mn(o) == 0 || B.mn(o) == 0) ? (A.mn_cnt(o) + B.mn_cnt(o)) : 0;
	if(ql <= l && A.mn(o) >= 0 && B.mn(o) >= 0) {
		return (A.mn(o) == 0 ? A.mn_cnt(o) : 0) + (B.mn(o) == 0 ? B.mn_cnt(o) : 0);
	} else {
		int mid = (l + r) >> 1, ret = 0;
		A.PushTag(o); B.PushTag(o);
		if(ql <= mid) ret += Query(o << 1, l, mid, ql);
		if(A.mn(o << 1) >= 0 && B.mn(o << 1) >= 0)
			ret += Query(o << 1 | 1, mid + 1, r, ql);
		return ret;
	}
}

ll s[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), s[i] = a[i];
		for(int i = 1; i <= n; ++i) {
			s[i] -= s[i - 1];
		}
		A.Build(1, 1, n, s, 0);
		B.Build(1, 1, n, s, 1);
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += Query(1, 1, n, i);
			A.Modify(1, 1, n, i, n, i % 2 == 1 ? a[i] : -a[i]);
			B.Modify(1, 1, n, i, n, i % 2 == 0 ? a[i] : -a[i]);
		}
		printf("%lld\n", ans);
	} return 0;
}