#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (1<<20) + 10;

int n, S, K, a[N], b[N], h[N<<1], x[N*20], y[N*20], lim, nex[N*20], tot;

namespace Flow {
	int tot = 1, S = 0, T = 1, h[N], id[N], d[N], las[N], pre[N], f[N], cnt = 1;
	
	bool vis[N];
	
	struct Edge {
		int to, next, w, c;
	} e[N<<2];
	
	void add_(int u, int v, int w, int c) {
		e[++cnt] = (Edge) {v, h[u], w, c};
		h[u] = cnt;
		
		if (!(cnt&1)) {
			add_(v, u, 0, -c);
		}
	}
	
	void link_(int u, int v, int c) {
		if (!id[u]) {
			id[u] = ++tot;
			add_(S, id[u], 1, 0);
		} 
		
		if (!id[v]) {
			id[v] = ++tot;
			add_(id[v], T, 1, 0);
		}
		
		add_(id[u], id[v], 1, c);
	}
	
	bool spfa_() {
		for (int i = 0; i <= tot; i++) {
			pre[i] = -1;
			d[i] = -1e9;
			f[i] = 1e9;
			vis[i] = 0;
		}
		
		queue <int> q;
		d[S] = 0, q.push(S), vis[S] = 1;
		
		while (!q.empty()) {
			int u = q.front(); q.pop();
			vis[u] = 0;
			
			for (int v, i = h[u]; i; i = e[i].next) {
				v = e[i].to;
				
				if (e[i].w && d[v] < d[u] + e[i].c) {
					d[v] = d[u] + e[i].c;
					f[v] = min(f[u], e[i].w);
					pre[v] = u, las[v] = i;
					
					if (!vis[v]) {
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
		
		return ~pre[T];
	}
	
	void work_() {
		ll ans = 0;
		
		while (K && spfa_()) {
			if (d[T] <= 0) {
				break;
			}
			
			K -= f[T], ans += d[T]*f[T];
			
			for (int u = T; u != S; u = pre[u]) {
				e[las[u]].w -= f[T];
				e[las[u]^1].w += f[T];
			}
		}
		
		printf("%lld\n", ans);
	}
}

int main() {
	scanf("%d%d", &n, &K);
	
	S = (1<<n);
	
	for (int i = 0; i < S; i++) {
		scanf("%d", &a[i]);
		b[i] = b[i>>1] + (i&1);
	}
	
	for (int i = 0; i < S; i++) {
		if (b[i]&1) {
			continue;
		}
		
		for (int j = 0; j < n; j++) {
			int k = i^(1<<j);
			nex[++tot] = h[a[i] + a[k]];
			h[a[i] + a[k]] = tot;
			x[tot] = i, y[tot] = k;
		}
	}
	
	lim = min(1ll*S/2*n, 2ll*(K - 1)*n + 1);
	
	for (int i = 2e6; i && lim; i--) {
		for (int j = h[i]; j && lim; j = nex[j]) {
			lim--;
			Flow :: link_(x[j], y[j], a[x[j]] + a[y[j]]);
		}
	}

	Flow :: work_();
	
	return 0;
}