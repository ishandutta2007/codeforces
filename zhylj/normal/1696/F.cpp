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
const int N = 100 + 5;

struct Dsu {
	int fa[N];
	void Init(int n) {
		for(int i = 1; i <= n; ++i) fa[i] = i;
	}
	int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
	void Merge(int x, int y) { fa[Find(x)] = Find(y); }
} D[N], T;

int n, d[N], buk[N]; bool flag;
char s[N][N][N];
std::vector <int> E[N];
void Add(int u, int v) { E[u].push_back(v); E[v].push_back(u); }
void Dfs(int u, int p, int bg) {
	d[u] = d[p] + 1;
	for(int v : E[u]) if(v != p) {
		Dfs(v, u, bg);
	}
}
void Calc(int _u, int _v) {
	for(int i = 1; i <= n; ++i) E[i].clear();
	T.Init(n);
	int tot = 1;
	std::queue <int> que;
	que.push(_u); que.push(_v);
	Add(_u, _v);
	T.Merge(_u, _v);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int v = 1; v <= n; ++v)
			if(s[E[u][0]][v][u] == '1' && T.Find(u) != T.Find(v)) {
				Add(u, v);
				T.Merge(u, v);
				++tot;
				que.push(v);
			}
	}
	if(tot != n - 1) return;
	for(int i = 1; i <= n; ++i) {
		memset(d, 0, sizeof(d));
		Dfs(i, 0, i);
		for(int j = 1; j <= n; ++j) {
			if(d[D[i].Find(j)] != d[j]) return;
		}
	}
	/*for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k) {
				if(s[i][j][k] == '1' && d[i][k] != d[j][k]) return;
				if(s[i][j][k] == '0' && d[i][k] == d[j][k]) return;
			}
			*/
	flag = true;
	printf("Yes\n");
	for(int i = 1; i <= n; ++i)
		for(int j : E[i]) if(j > i)
			printf("%d %d\n", i, j);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j) {
				scanf("%s", s[i][j] + 1);
				memcpy(s[j][i], s[i][j], sizeof(s[j][i]));
			}
		for(int i = 1; i <= n; ++i) D[i].Init(n);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				for(int k = 1; k <= n; ++k)
					if(s[i][j][k] == '1') D[k].Merge(i, j);
		bool pre_flag = true;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				for(int k = 1; k <= n; ++k)
					if(s[i][j][k] == '0' && D[k].Find(i) == D[k].Find(j)) pre_flag = false;
		flag = false;
		if(pre_flag) {
			for(int i = 2; i <= n; ++i)
				if(!flag) Calc(1, i);
		}
		if(!flag) printf("No\n");
	} return 0;
}