#include <bits/stdc++.h>
using namespace std;
inline void up(int &x, int y) { x < y ? x = y : 0; }
inline void down(int &x, int y) { x > y ? x = y : 0; }
const int N = 2e5 + 5;
int n, h[N], ans[N], dis[N], que[N * 2], nxt[N];
vector<int> e[N], buc[N]; 
bool vis[N];
int main() {
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	memset(ans, -1, sizeof ans);
	int l = 1, r = 0;
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if (x) h[i] = 0, que[++r] = i;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	while (l <= r) {
		int u = que[l++];
		for (auto v : e[u]) {
			if (~h[v]) {
				if (h[u] == h[v]) {
					buc[h[u]].emplace_back(u);
					buc[h[u]].emplace_back(v);
				}
			} else {
				h[v] = h[u] + 1;
				que[++r] = v;
			}
		}
	}
	for (int d = 0; d < n; ++d) {
		if (buc[d].empty()) continue;
		memset(dis, 0x3f, sizeof dis);
		memset(vis, false, sizeof vis);
		int l = 1, r = 0;
		for (auto x : buc[d]) 
			if (!vis[x]) vis[x] = true, dis[x] = 0, que[++r] = x;
		while (r) {
			for (l = 1; l <= r; ) {
				int u = que[l++];
				for (auto v : e[u]) {
					if (h[v] == h[u]) {
						if (dis[v] > dis[u] + 1)
							dis[v] = dis[u] + 1, que[++r] = v;
					} else if (h[v] == h[u] + 1) {
						down(dis[v], max(0, dis[u] - 1));
					}
				}
			}
			int ptr = 0;
			for (int i = 1; i <= r; ++i) {
				int u = que[i];
				for (auto v : e[u])
					if (h[v] == h[u] + 1 && !vis[v])
						vis[v] = true, nxt[++ptr] = v;
			}
			sort(nxt + 1, nxt + ptr + 1, [&](int u, int v) {
				return dis[u] < dis[v];
			});
			memcpy(que + 1, nxt + 1, ptr * 4), r = ptr;
		}		
		for (int u = 1; u <= n; ++u)
			if (dis[u] == 0 && ans[u] == -1) assert(h[u] >= d), ans[u] = d;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", 2 * h[i] - (~ans[i] ? ans[i] : h[i]), " \n"[i == n]);
	return 0;
}