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

ff ans[N];
int siz[N];
std::vector <int> E[N];

void Dfs(int u) {
	siz[u] = 1;
	for(int v : E[u]) {
		Dfs(v);
		siz[u] += siz[v];
	}
}
void Dfs2(int u) {
	for(int v : E[u]) {
		ans[v] = ans[u] + (siz[u] - siz[v] - 1) / 2.0 + 1;
		Dfs2(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n);
		for(int i = 2; i <= n; ++i) {
			int p; rd(p);
			E[p].push_back(i);
		}
		ans[1] = 1;
		Dfs(1);
		Dfs2(1);
		for(int i = 1; i <= n; ++i)
			printf("%.2lf ", ans[i]);
		printf("\n");
	} return 0;
}