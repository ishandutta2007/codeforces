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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

struct Edge {
	int u, v, c;
} E[kN];
int n, m, fa[kN], s[kN], col[kN], cnt[kN];
std::vector <int> pt[2]; bool flag = false;

int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if(fx == fy) return;
	s[fx] += s[fy];
	fa[fy] = fx;
}

void Solve(int x) {
	memset(col, 0xff, sizeof(col));
	for(int i = 1; i <= 2 * n; ++i) {
		fa[i] = i; s[i] = (i <= n);
	}
	for(int i = 1; i <= m; ++i) {
		int u = E[i].u, v = E[i].v, c = E[i].c ^ x;
		if(c) Merge(u, v), Merge(u + n, v + n);
		else Merge(u + n, v), Merge(u, v + n);
	}
	for(int i = 1; i <= n; ++i)
		if(Find(i) == Find(i + n)) return;
	flag = true;
	for(int i = 1; i <= n; ++i)
		if(col[Find(i)] == -1) {
			col[Find(i)] = (s[Find(i)] < s[Find(i + n)]);
			col[Find(i + n)] = !col[Find(i)];
		}
	cnt[x] = 0;
	for(int i = 1; i <= n; ++i)
		if(col[Find(i)] == 1) {
			++cnt[x];
			pt[x].push_back(i);
		}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m); cnt[0] = cnt[1] = kInf;
		for(int i = 1; i <= m; ++i) {
			char c[5];
			rd(E[i].u, E[i].v); scanf("%s", c + 1);
			E[i].c = (c[1] == 'B');
		}
		for(int i = 0; i < 2; ++i) Solve(i);
		if(flag) {
			if(cnt[0] < cnt[1]) {
				printf("%d\n", cnt[0]);
				for(auto i : pt[0]) printf("%d ", i);
			} else {
				printf("%d\n", cnt[1]);
				for(auto i : pt[1]) printf("%d ", i);
			}
		} else printf("-1");
	} return 0;
}