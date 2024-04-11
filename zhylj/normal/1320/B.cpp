#include <bits/stdc++.h>

typedef long long ll;

const int kN = 4e5 + 5;

int n, m, k, d[kN], p[kN];
std::vector<int> E1[kN], E2[kN];
std::queue<int> que;
void Bfs() {
	//memset(d, 0x3f, sizeof(d));
	que.push(p[k]); d[p[k]] = 0;
	while(!que.empty()) {
		int cur = que.front(); que.pop();
		for(int i = 0; i < E2[cur].size(); ++i)
			if(!d[E2[cur][i]] && E2[cur][i] != p[k]) {
				d[E2[cur][i]] = d[cur] + 1;
				que.push(E2[cur][i]);
			}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		E1[x].push_back(y);
		E2[y].push_back(x);
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i) scanf("%d", p + i);
	Bfs();
	//for(int i = 1; i <= n; ++i)
//		printf("%d ", d[i]);
	//printf("\n");
	int min_r = 0, max_r = 0;
	for(int i = 1; i < k; ++i) {
		if(d[p[i + 1]] != d[p[i]] - 1) ++min_r, ++max_r;
		else {
			for(int j = 0; j < E1[p[i]].size(); ++j)
				if(d[p[i]] - 1 == d[E1[p[i]][j]] && E1[p[i]][j] != p[i + 1])
					{ ++max_r; break; }
		}
		//printf("%d %d %d\n", p[i], min_r, max_r);
	}
	printf("%d %d", min_r, max_r);
	return 0;
}