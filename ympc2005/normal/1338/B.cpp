#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, mn, mx, d[N], tag[2];

vector <int> e[N];

void dfs_(int u, int fa) {
	d[u] = d[fa]^1;
	
	if (e[u].size() == 1) {
		tag[d[u]] = 1;
	}
	
	int tmp = 0;
	
	for (int v : e[u]) {
		if (v != fa) {
			dfs_(v, u);
			
			if (e[v].size() == 1) {
				tmp = 1;
			} else {
				mx++;
			}
		}	
	}
	
	mx += tmp;
}

int main() {
	scanf("%d", &n);
	
	for (int u, v, i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (e[i].size() > 1) {
			dfs_(i, 0);
			break;
		}
	}
	
	if (tag[1] && tag[0]) {
		mn = 3;
	} else {
		mn = 1;
	}
	
	printf("%d %d\n", mn, mx);
}