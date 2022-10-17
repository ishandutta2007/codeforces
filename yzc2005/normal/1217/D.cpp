#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m, ans[N], sta[N];
int to[N], nxt[N], hd[N], cnt;

void dfs(int u) {
	sta[u] = 1;
	for(int i = hd[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if(!sta[v]) ans[i] = 1, dfs(v);
		else if(sta[v] & 1) ans[i] = 2;
		else ans[i] = 1;
	}
	sta[u] = 2;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		to[++cnt] = v, nxt[cnt] = hd[u], hd[u] = cnt;
	}
	for(int i = 1; i <= n; ++i) if(!sta[i]) dfs(i);
	printf("%d\n", *max_element(ans + 1, ans + m + 1));
	for(int i = 1; i <= m; ++i) printf("%d ", ans[i]);
	return 0;
}