#include<iostream>
#include<algorithm>
using namespace std;

struct nod {
	int u, v, nxt;
}e[400010];
int head[200010], cnt;

int vis[200010];
int dfs(int u, int fa) {
	if (vis[u])return 0;
	int ret = 1; vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa)continue;
		ret += dfs(v, u);
	}
	return ret;
}

void add(int u, int v) {
	e[++cnt] = { u,v,head[u] };
	head[u] = cnt;
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		add(u, v); add(v, u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = dfs(i, 0);
		//cout << i << " " << tmp << endl;
		if (tmp >= 1)ans += tmp - 1;
	}
	cout <<m - ans << endl;
}