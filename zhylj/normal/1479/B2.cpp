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
const int kN = 2e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

#define seg(x) tr[x].seg
#define tag(x) tr[x].tag

struct Node {
	int seg, tag;
} tr[kN << 3];
void Update(int o) {
	seg(o) = std::min(seg(o << 1), seg(o << 1 | 1));
}
void PushTag(int o) {
	if(tag(o)) {
		seg(o << 1) += tag(o);
		seg(o << 1 | 1) += tag(o);
		tag(o << 1) += tag(o);
		tag(o << 1 | 1) += tag(o);
		tag(o) = 0;
	}
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else seg(o) = kInf, tag(o) = 0;
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) {
		seg(o) += v;
		tag(o) += v;
	} else {
		PushTag(o);
		int mid = (l + r) >> 1;
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}
void Assign(int o, int l, int r, int q, int v) {
	if(l == r) {
		seg(o) = std::min(seg(o), v); tag(o) = 0;
	} else {
		PushTag(o);
		int mid = (l + r) >> 1;
		if(q <= mid) Assign(o << 1, l, mid, q, v);
		else Assign(o << 1 | 1, mid + 1, r, q, v);
		Update(o);
	}
}
int Query(int o, int l, int r, int ql, int qr) {
	if(ql > qr) return kInf;
	if(ql <= l && r <= qr) return seg(o);
	PushTag(o);
	int mid = (l + r) >> 1, ret = kInf;
	if(ql <= mid) ret = std::min(ret, Query(o << 1, l, mid, ql, qr));
	if(qr > mid) ret = std::min(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
	return ret;
}

int n, A[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n); Build(1, 1, n + 1);
		for(int i = 1; i <= n; ++i)
			rd(A[i]);
		A[0] = n + 1;
		Assign(1, 1, n + 1, n + 1, 1);
		for(int i = 2; i <= n; ++i) {
			int f_ai = std::min(Query(1, 1, n + 1, 1, A[i] - 1), Query(1, 1, n + 1, A[i] + 1, n + 1)) + 1;
			f_ai = std::min(f_ai, Query(1, 1, n + 1, A[i], A[i]));
			if(A[i] != A[i - 1]) Modify(1, 1, n + 1, 1, n + 1, 1);
			Assign(1, 1, n + 1, A[i - 1], f_ai);
		}
		printf("%d\n", Query(1, 1, n + 1, 1, n + 1));
	} return 0;
}