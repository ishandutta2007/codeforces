#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n, a[N], T;

vector <int> e[N];

void dfs_(int u, int fa, int s) {
	for (int v : e[u]) {
		if (v != fa) {
			dfs_(v, u, s*-1);
		}
	}
	
	int cnt = 0;
	
	for (int v : e[u]) {
		if (v != fa) {
			++cnt;
		}
	}
	
	a[u] = s*(cnt + 1) - (u == 1);
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			e[i].clear();
		}
		
		for (int u, v, i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		dfs_(1, 0, 1);
		
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		
		puts("");
	}
}