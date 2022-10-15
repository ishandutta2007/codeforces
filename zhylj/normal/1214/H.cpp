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
const int N = 5e5 + 5;

int n, k, d[N], d_u[N], d_v[N];
std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

void Dfs(int u, int p) {
	d[u] = d[p] + 1;
	for(int v : E[u]) if(v != p)
		Dfs(v, u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		int u = 0, v = 0;
		Dfs(1, 0);
		for(int i = 1; i <= n; ++i)
			if(d[i] > d[u]) u = i;
		Dfs(u, 0);
		memcpy(d_u, d, sizeof(d_u));
		for(int i = 1; i <= n; ++i)
			if(d[i] > d[v]) v = i;
		Dfs(v, 0);
		memcpy(d_v, d, sizeof(d_v));
		int len = d_u[v];
		if(k == 2) {
			printf("Yes\n");
			for(int i = 1; i <= n; ++i)
				printf("%d ", d_u[i] % 2 + 1);
			printf("\n");
		} else {
			for(int i = 1; i <= n; ++i)	
				if((d_u[i] + d_v[i] - len) / 2 % k != 0 && d_u[i] >= k && d_v[i] >= k) {
					printf("No\n");
					return 0;
				}
			printf("Yes\n");
			for(int i = 1; i <= n; ++i) {
				if(d_u[i] > d_v[i]) printf("%d ", d_u[i] % k + 1);
				else printf("%d ", (d_u[v] - d_v[i] % k + 1 + k) % k + 1);
			}
			printf("\n");
		}
	} return 0;
}