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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

int n, m, q, a[N], b[N], p[N], T[N];
int Query(int o) {
	int ret = 0;
	for(; o; o -= o & -o)
		ret += T[o];
	return ret;	
}
void Modify(int o, int v) {
	for(; o <= m; o += o & -o) T[o] += v;
}

int seg[N << 3], tag[N << 3];
void Update(int o) {
	seg[o] = (seg[o << 1] + seg[o << 1 | 1]) % Mod;
}
void PushTag(int o) {
	if(tag[o] != 1) {
		tag[o << 1] = 1LL * tag[o << 1] * tag[o] % Mod;
		tag[o << 1 | 1] = 1LL * tag[o << 1 | 1] * tag[o] % Mod;
		seg[o << 1] = 1LL * seg[o << 1] * tag[o] % Mod;
		seg[o << 1 | 1] = 1LL * seg[o << 1 | 1] * tag[o] % Mod;
		tag[o] = 1;
	}
}
void Build(int o, int l, int r) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(o << 1, l, mid); 
		Build(o << 1 | 1, mid + 1, r);
		Update(o);
	} else seg[o] = 0, tag[o] = 1;
}
void Asign(int o, int l, int r, int x, int v) {
	if(l == r) seg[o] = v, tag[o] = 1;
	else {
		PushTag(o);
		int mid = (l + r) >> 1;
		if(x <= mid) Asign(o << 1, l, mid, x, v);
		else Asign(o << 1 | 1, mid + 1, r, x, v);
		Update(o);
	}
}
void Mul(int o, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) {
		seg[o] = 1LL * seg[o] * v % Mod;
		tag[o] = 1LL * tag[o] * v % Mod;
	} else {
		PushTag(o);
		int mid = (l + r) >> 1;
		if(ql <= mid) Mul(o << 1, l, mid, ql, qr, v);
		if(qr > mid) Mul(o << 1 | 1, mid + 1, r, ql, qr, v);
		Update(o);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		srand(time(0));
		q = rand() % Mod;
		rd(n, m); Build(1, 1, m);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= m; ++i) rd(b[i]), p[b[i]] = i;
		int h = 0;
		for(int i = 1, bas = 1; i <= n; ++i, bas = 1LL * bas * q % Mod)
			h = (h + 1LL * a[i] * bas) % Mod;
		int cnt = 0, d = 1LL * (QPow(q, n) - 1) * QPow(q - 1, Mod - 2) % Mod;
		for(int i = 1; i <= m; ++i) {
			int L = Query(p[i]), cur_h;
			Modify(p[i], 1);
			Mul(1, 1, m, p[i], m, q);
			Asign(1, 1, m, p[i], 1LL * i * QPow(q, L) % Mod);
			if(i >= n) { 
				if((seg[1] - 1LL * (i - n) * d % Mod + Mod) % Mod == h)
					++cnt;
				Modify(p[i - n + 1], -1);
				Mul(1, 1, m, p[i - n + 1], m, QPow(q, Mod - 2));
				Asign(1, 1, m, p[i - n + 1], 0);
			}
		}
		printf("%d\n", cnt);
	} return 0;
}