#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e5 + 5, B = 20, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Node {
	int cnt[B], tot;
	ll Get() {
		ll ret = 0;
		for(int i = 0; i < B; ++i)
			ret += cnt[i] * (1LL << i);
		return ret;
	}
	Node operator +(Node x) {
		Node ret; ret.tot = tot + x.tot;
		for(int i = 0; i < B; ++i)
			ret.cnt[i] = cnt[i] + x.cnt[i];
		return ret;
	}
	Node operator ^(int x) {
		Node ret = *this;
		for(int i = 0; i < B; ++i)
			if((x >> i) & 1)
				ret.cnt[i] = tot - ret.cnt[i];
		return ret;
	}
	Node operator =(int x) {
		tot = 1;
		for(int i = 0; i < B; ++i)
			cnt[i] = (x >> i) & 1;
		return *this;
	}
	Node operator ^=(int x) { return *this = *this ^ x; }
	Node operator +=(Node x) { return *this = *this + x; }
} seg[N << 3];
int tag[N << 3];
void Update(int o) { seg[o] = seg[o << 1] + seg[o << 1 | 1]; }
void PushTag(int o) {
	if(tag[o]) {
		tag[o << 1] ^= tag[o]; tag[o << 1 | 1] ^= tag[o];
		seg[o << 1] ^= tag[o]; seg[o << 1 | 1] ^= tag[o];
		tag[o] = 0;
	}
}
void Build(int o, int l, int r, int A[]) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid, A);
		Build(o << 1 | 1, mid + 1, r, A);
		Update(o);
	} else seg[o] = A[l];
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) tag[o] ^= v, seg[o] ^= v;
	else {
		int mid = (l + r) >> 1;
		PushTag(o);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}
ll Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o].Get();
	int mid = (l + r) >> 1; ll ret = 0;
	PushTag(o);
	if(ql <= mid) ret += Query(o << 1, l, mid, ql, qr);
	if(qr > mid) ret += Query(o << 1 | 1, mid + 1, r, ql, qr);
	return ret;
}

int n, q, A[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		Build(1, 1, n, A);
		rd(q);
		while(q--) {
			int typ, l, r; rd(typ, l, r);
			if(typ == 1) {
				printf("%lld\n", Query(1, 1, n, l, r));
			} else {
				int x; rd(x);
				Modify(1, 1, n, l, r, x);
			}
		}
	} return 0;
}