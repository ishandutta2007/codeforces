#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector <int> e[N];

int T, n, d[N], f[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			f[i] = d[i] = 0;	
		}
		
		for (int k, i = 1; i <= n; i++) {
			scanf("%d", &k);
			
			for (int x, j = 1; j <= k; j++) {
				scanf("%d", &x);
				e[x].push_back(i);
				d[i]++;
			}
		}
		
		queue <int> q;
		
		for (int i = 1; i <= n; i++) {
			if (!d[i]) {
				q.push(i);
				f[i] = 1;
			}
		}
		
		while (!q.empty()) {
			int u = q.front(); q.pop();
			
			for (int v : e[u]) {
				f[v] = max(f[v], f[u] + (v < u));
				
				if (!--d[v]) {
					q.push(v);
				}
			}
		} 
		
		int ans = 0, ok = 1;
		
		for (int i = 1; i <= n; i++) {
			if (d[i]) {
				ok = 0;
			} else {
				ans = max(ans, f[i]);
			}
		}
		
		printf("%d\n", ok ? ans : -1);
	}
}