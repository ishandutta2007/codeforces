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
const int N = 5e5 + 5, INF = 0x3f3f3f3f;

int n, a[N], b[N], f[N], idx[N], nxt[N];
std::vector <int> e[N];
pii tr[N];
void Modify(int o, pii v) {
	o = n - o + 1;
	for(; o < N; o += o & -o)
		tr[o] = std::min(tr[o], v);
}
pii Query(int o) {
	o = n - o + 1;
	pii ret = mkp(INF, INF);
	for(; o; o -= o & -o)
		ret = std::min(ret, tr[o]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(tr, 0x3f, sizeof(tr));
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), idx[i] = i;
		for(int i = 1; i <= n; ++i) {
			rd(b[i]);
			e[i + b[i]].push_back(i);
		}
		std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
			return x - a[x] < y - a[y];
		});
		f[0] = 0; Modify(0, mkp(0, 0));
		for(int i = 1; i <= n; ++i) {
			int x = idx[i]; pii t = Query(x - a[x]);
			f[x] = t.fi + 1; nxt[x] = t.se;
			for(int j : e[x]) {
				Modify(j, mkp(f[x], j));
			}
		}
		if(f[n] < INF) {
			printf("%d\n", f[n]);
			for(int cur = nxt[n]; cur; cur = nxt[cur]) {
				printf("%d ", cur);
				cur += b[cur];
			}
			printf("%d\n", 0);
		} else printf("-1\n");
	} return 0;
}