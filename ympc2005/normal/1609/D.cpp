#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, sz[N], fa[N], cnt = 1, f[N];

int find_(int x) {
	return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

void work_() {
	int ans = 0, lim = cnt;
	
	for (int i = n; i; i--) {
		if (f[i] < lim) {
			lim -= f[i];
			ans += f[i]*i;
		} else {
			ans += i*lim;
			lim = 0;
			break;
		}
	}
	
	printf("%d\n", ans - 1);
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i, sz[i] = 1;
		f[1]++;
	}
	
	for (int u, v, i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		u = find_(u), v = find_(v);
		
		if (u == v) {
			cnt++;
		} else {
			fa[v] = u, f[sz[u]]--, f[sz[v]]--, sz[u] += sz[v];
			f[sz[u]]++;
		}
		
		work_();
	}
}