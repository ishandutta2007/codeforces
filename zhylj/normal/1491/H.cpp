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
const int N = 4e5 + 5, B = 630;

int n, m, a[N], d[N], tag[N / B + 5], f[N];
std::vector <int> res[N / B + 5];

int GetF(int u) {
	int v = std::max(a[u] - tag[u / B], 1);
	return v / B != u / B ? v : f[u];
}

void Remake(int b) {
	if(b == 0) return;
	std::vector <int> _res;
	for(int u : res[b]) {
		int v = std::max(a[u] - tag[b], 1);
		if(v / B == b) _res.push_back(u);
		d[u] = v; f[u] = 0;
	}
	for(int u : res[b]) {
		int v;
		for(v = u; d[v] && !f[v] && v / B == b; v = d[v]);
		int w = v / B == b ? GetF(v) : v;
		for(v = u; d[v] && !f[v] && v / B == b; f[v] = w, v = d[v]);
	}
	res[b] = _res;
}

void Modify(int l, int r, int x) {
	if(l / B == r / B) {
		for(int i = l; i <= r; ++i)
			a[i] = std::max(a[i] - x, 1);
	} else {
		for(int i = l; i < (l / B + 1) * B; ++i)
			a[i] = std::max(a[i] - x, 1);
		for(int i = r / B * B; i <= r; ++i)
			a[i] = std::max(a[i] - x, 1);
		for(int i = l / B + 1; i < r / B; ++i)
			tag[i] = std::min(tag[i] + x, n);
	}
	for(int i = l / B; i <= r / B; ++i)
		Remake(i);
}
int Query(int u, int v) {
	while(u != v) {
		//printf("%d %d %d %d\n", u, v, f[u], f[v]);
		f[u] = GetF(u); f[v] = GetF(v);
		if(f[u] != f[v]) {
			if(f[u] < f[v]) std::swap(u, v);
			u = f[u];
		} else {
			if(u < v) std::swap(u, v);
			u = std::max(a[u] - tag[u / B], 1);
			//u = a[u];
		}
	}
	return u;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		a[1] = 1;
		for(int i = 2; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i)
			if(a[i] / B == i / B) res[i / B].push_back(i);
		for(int i = 0; i <= n / B; ++i)
			Remake(i);
		for(int i = 1, lst_ans = 0; i <= m; ++i) {
			lst_ans = 0;
			int opt, x, y; rd(opt, x, y);
			x ^= lst_ans; y ^= lst_ans;
			if(opt == 1) {
				int z; rd(z);
				z ^= lst_ans;
				Modify(x, y, z);
			} else {
				printf("%d\n", lst_ans = Query(x, y));
			}
			//exit(0);
		}
	} return 0;
}