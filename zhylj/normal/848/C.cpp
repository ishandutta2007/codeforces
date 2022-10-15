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
const int N = 5e6 + 5, M = 1e5 + 5;

struct Bit {
	ll tr[M];
	void Modify(int o, int v) {
		for(; o < M; o += o & -o) tr[o] += v;
	}
	ll Query(int o) {
		ll ret = 0;
		for(; o; o -= o & -o) ret += tr[o];
		return ret;
	}
} T;

int n, m, a[M];
std::set <int> s[M];

struct Opt {
	int opt, x, y, idx; ll v;
} Q[N];
int cnt;
void AddModify(int x, int si) {
	auto it = s[a[x]].lower_bound(x);
	int pre = *std::prev(it), nxt = *std::next(it);
	// l in (pre, x]  r in [x, ]
	++cnt; Q[cnt] = (Opt) { 1, pre + 1, x, cnt, -si * x };
	++cnt; Q[cnt] = (Opt) { 1, x + 1, x, cnt, si * x };
	// l in [, x]  r in [x, nxt)
	++cnt; Q[cnt] = (Opt) { 1, 1, x, cnt, si * x };
	++cnt; Q[cnt] = (Opt) { 1, 1, nxt, cnt, -si * x };
	++cnt; Q[cnt] = (Opt) { 1, x + 1, x, cnt, -si * x };
	++cnt; Q[cnt] = (Opt) { 1, x + 1, nxt, cnt, si * x };
	if(nxt != n + 1) {
		++cnt; Q[cnt] = (Opt) { 1, pre + 1, nxt, cnt, si * nxt };
		++cnt; Q[cnt] = (Opt) { 1, x + 1, nxt, cnt, -si * nxt };
	}
	if(pre) {
		++cnt; Q[cnt] = (Opt) { 1, 1, x, cnt, -si * pre };
		++cnt; Q[cnt] = (Opt) { 1, 1, nxt, cnt, si * pre };
		++cnt; Q[cnt] = (Opt) { 1, pre + 1, x, cnt, si * pre };
		++cnt; Q[cnt] = (Opt) { 1, pre + 1, nxt, cnt, -si * pre };
	}
}
void Init() {
	for(int i = 1; i <= n; ++i) { s[i].insert(0); s[i].insert(n + 1); }
	for(int i = 1; i <= n; ++i) {
		s[a[i]].insert(i);
		AddModify(i, 1);
	}	
}
void Div(int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	Div(l, mid); Div(mid + 1, r);
	int j = l;
	for(int i = mid + 1; i <= r; ++i) {
		for(; j <= mid && Q[j].x <= Q[i].x; ++j)
			if(Q[j].opt == 1) T.Modify(Q[j].y, Q[j].v);
		if(Q[i].opt == 2) Q[i].v += T.Query(Q[i].y);
	}
	for(int i = l; i < j; ++i)
		if(Q[i].opt == 1) T.Modify(Q[i].y, -Q[i].v);
	std::sort(Q + l, Q + r + 1,
		[&](const Opt &x, const Opt &y) { return x.x < y.x; }
	);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		Init();
		for(int i = 1; i <= m; ++i) {
			int opt, x, y; rd(opt, x, y);
			if(opt == 1) {
				AddModify(x, -1);
				s[a[x]].erase(x);
				a[x] = y;
				s[y].insert(x);
				AddModify(x, 1);
			} else {
				++cnt; Q[cnt] = (Opt) { 2, x, y, cnt, 0 };
			}
		}
		if(cnt) Div(1, cnt);
		std::sort(Q + 1, Q + cnt + 1, [&](const Opt &x, const Opt &y) {
			return x.idx < y.idx;
		});
		for(int i = 1; i <= cnt; ++i)
			if(Q[i].opt == 2) printf("%lld\n", Q[i].v);
	} return 0;
}