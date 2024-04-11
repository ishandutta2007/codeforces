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
const int N = 6e2 + 5, Inf = 0x3f3f3f3f;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

bool vis[N];
int n, m, p, s_cnt, t_cnt, d[N], in_deg[N], out_deg[N], s_idx[N], t_idx[N], mat[N][N];
std::vector <int> E[N];

std::queue <int> que;
int res_deg[N];
void Bfs(int s) {
	memset(d, 0, sizeof(d));
	memcpy(res_deg, in_deg, sizeof(res_deg));
	d[s] = 1;
	for(int i = 1; i <= s_cnt; ++i) que.push(s_idx[i]);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int v : E[u]) {
			d[v] = (d[v] + d[u]) % p;
			--res_deg[v];
			if(!res_deg[v])
				que.push(v);
		}
	}
}

int Det() {
	int ret = 1, si = 1;
	for(int i = 1; i <= s_cnt; ++i) {
		for(int j = i + 1; j <= s_cnt; ++j)
			while(mat[j][i]) {
				int t = mat[i][i] / mat[j][i];
				for(int k = i; k <= s_cnt; ++k) {
					mat[i][k] = (mat[i][k] - 1LL * t * mat[j][k] % p + p) % p;
					std::swap(mat[i][k], mat[j][k]);
				}
				si *= -1;
			}
		ret = 1LL * ret * mat[i][i] % p;
	}
	return (ret * si + p) % p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, p);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v);
			++out_deg[u]; ++in_deg[v];
		}
		for(int i = 1; i <= n; ++i) {
			if(!in_deg[i]) s_idx[++s_cnt] = i;
			if(!out_deg[i]) t_idx[++t_cnt] = i;
		}
		for(int i = 1; i <= s_cnt; ++i) {
			Bfs(s_idx[i]);
			for(int j = 1; j <= t_cnt; ++j)
				mat[i][j] = d[t_idx[j]];
		}
		printf("%d\n", Det());
	} return 0;
}