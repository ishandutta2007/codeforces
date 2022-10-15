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

int Gcd(int a, int b) {
	return b ? Gcd(b, a % b) : a;
}

int n, cnt, tot, A[N], nxt[N], fa[N], p[N];

int Find(int u) { return fa[u] == u ? u : fa[u] = Find(fa[u]); }
void Merge(int u, int v) {
	if(Find(u) != Find(v)) --tot;
	fa[Find(u)] = Find(v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); cnt = 0; tot = n;
		for(int i = 1; i <= n; ++i) rd(A[i]), nxt[i] = i % n + 1, fa[i] = i;
		for(int i = 1, cur = 1; i <= 2 * n; ++i, cur = nxt[cur]) {
			cur = Find(cur);
			if(Gcd(A[cur], A[nxt[cur]]) == 1) {
				if(Find(nxt[nxt[cur]]) != Find(nxt[cur])) --tot;
				p[++cnt] = nxt[cur];
				nxt[cur] = nxt[nxt[cur]];
			} else Merge(cur, nxt[cur]);
		}
		cnt = std::unique(p + 1, p + cnt + 1) - p - 1;
		printf("%d ", cnt);
		for(int i = 1; i <= cnt; ++i) printf("%d ", p[i]);
		printf("\n");
	} return 0;
}