#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 50, maxm = 5e3, inf = 1e8;
int n, m, q, k, tot, ter[maxm + 3], cap[maxm + 3], wei[maxm + 3], nxt[maxm + 3], lnk[maxn + 3], dist[maxn + 3], pre[maxn + 3], f[maxn + 3];
bool in[maxn + 3];
ll g[maxn + 3], h[maxn + 3];

void add(int u, int v, int c, int w) {
	ter[++tot] = v, cap[tot] = c, wei[tot] = w, nxt[tot] = lnk[u], lnk[u] = tot;
}

void add_flow(int u, int v, int c, int w) {
	add(u, v, c, w), add(v, u, 0, -w);
}

int rev(int x) {
	return x & 1 ? x + 1 : x - 1;
}

bool spfa() {
	fill(dist + 1, dist + n + 1, inf);
	fill(pre + 1, pre + n + 1, 0);
	queue<int> Q;
	Q.push(1), dist[1] = 0, in[1] = true;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop(), in[u] = false;
		for (int i = lnk[u], v, c, w; i; i = nxt[i]) {
			v = ter[i], c = cap[i], w = wei[i];
			if (c > 0 && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w, pre[v] = i;
				if (!in[v]) {
					in[v] = true, Q.push(v);
				}
			}
		}
	}
	return pre[n];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		add_flow(u, v, 1, w);
	}
	while (spfa()) {
		int x = n, t;
		while (x != 1) {
			t = pre[x];
			cap[t]--, cap[rev(t)]++;
			x = ter[rev(t)];
		}
		f[++k] = dist[n];
		g[k] = g[k - 1] + f[k];
		h[k] = 1ll * k * f[k] - g[k];
	}
	scanf("%d", &q);
	for (int x, t; q --> 0; ) {
		scanf("%d", &x);
		t = upper_bound(h + 1, h + k + 1, x) - (h + 1);
		printf("%.9lf\n", 1. * (g[t] + x) / t);
	}
	return 0;
}