#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], id[N];
bool vis[N];
vector<int> ans[N];

inline bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		++cnt; int u = i;
		do {
			vis[u] = 1;
			ans[cnt].emplace_back(u);
			u = id[u];
		} while(!vis[u]);
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; ++i) {
		printf("%d ", ans[i].size());
		for(int j = 0; j < ans[i].size(); ++j)
			printf("%d%c", ans[i][j], j == ans[i].size() - 1 ? '\n' : ' ');
	}
}