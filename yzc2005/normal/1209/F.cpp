#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 6, mod = 1e9 + 7;
int n, m, tot, ans[N * M * 2], p[M];
vector <int> to[N * M * 2][10], x, y;
queue <vector <int> > q;
bool vis[N * M * 2];

inline void add(int u, int v, int w) {
	int cnt = 0;
	while(w) p[cnt++] = w % 10, w /= 10;
	if(cnt == 1) return to[u][p[0]].push_back(v), void();
	to[u][p[--cnt]].push_back(++tot);
	for(--cnt; cnt; --cnt) ++tot, to[tot - 1][p[cnt]].push_back(tot);
	to[tot][p[cnt]].push_back(v); 
}

int main() {
	scanf("%d%d", &n, &m); tot = n;
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v, i), add(v, u, i);
	}
	vector <int> tmp; tmp.clear(); tmp.push_back(1);
	vis[1] = 1, q.push(tmp);
	while(!q.empty()) {
		x = q.front(); q.pop();
		for(int i = 0; i < 10; ++i) {
			y.clear();
			for(int j = 0; j < x.size(); ++j) {
				int u = x[j];
				for(int k = 0; k < to[u][i].size(); ++k) {
					int v = to[u][i][k];
					if(!vis[v]) {
						vis[v] = 1;
						ans[v] = (ans[u] * 10ll + i) % mod;
						y.push_back(v);
					}
				} 
			}
			if(!y.empty()) q.push(y);
		}
	}
	for(int i = 2; i <= n; ++i) printf("%d\n", ans[i]);
	return 0;
}