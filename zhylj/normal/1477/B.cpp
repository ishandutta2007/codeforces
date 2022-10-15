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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int seg[kN << 3], tag[kN << 3];
void Update(int o) {
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid);
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} seg[o] = 0, tag[o] = -1;
}
void PushTag(int o, int l, int r) {
	if(~tag[o]) {
		int mid = (l + r) >> 1;
		tag[o << 1] = tag[o];
		tag[o << 1 | 1] = tag[o];
		seg[o << 1] = tag[o] * (mid - l + 1);
		seg[o << 1 | 1] = tag[o] * (r - mid);
		tag[o] = -1;
	}
}
void Modify(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) {
		seg[o] = v * (r - l + 1);
		tag[o] = v;
	} else {
		int mid = (l + r) >> 1;
		PushTag(o, l, r);
		if(ql <= mid) Modify(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Modify(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}
int Query(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o];
	int mid = (l + r) >> 1, ret = 0;
	PushTag(o, l, r);
	if(ql <= mid) ret += Query(o << 1, l, mid, ql, qr);
	if(qr > mid) ret += Query(o << 1 | 1, mid + 1, r, ql, qr);
	return ret;
}

int n, q, l[kN], r[kN];
char s[kN], f[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		bool flag = true;
		rd(n, q);
		scanf("%s%s", s + 1, f + 1);
		for(int i = 1; i <= q; ++i)
			rd(l[i], r[i]);
		Build(1, 1, n);
		for(int i = 1; i <= n; ++i) {
			if(f[i] == '1') Modify(1, 1, n, i, i, 1);
		}
		for(int i = q; i; --i) {
			int cnt = Query(1, 1, n, l[i], r[i]), len = (r[i] - l[i] + 1);
			if(cnt == len / 2 && len % 2 == 0) {
				flag = false;
				break;
			} else {
				if(cnt > len / 2) Modify(1, 1, n, l[i], r[i], 1);
				else Modify(1, 1, n, l[i], r[i], 0);
			}
		}
		for(int i = 1; i <= n; ++i)
			if(Query(1, 1, n, i, i) != s[i] - '0')
				flag = false;
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}