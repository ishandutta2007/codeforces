#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

const int MAX_N = int(1e5) + 10;

struct Edge {
	int t;
	Edge(int t) :
			t(t) {
	}
};

vector<Edge> E[MAX_N];

bool del[MAX_N];

int n;

int size[MAX_N], opt[MAX_N];
vector<int> all;

void dfs(int u, int par) {
	all.push_back(u);
	size[u] = 1;
	opt[u] = 0;

	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != par && !del[e->t]) {
			dfs(e->t, u);
			size[u] += size[e->t];
			opt[u] = max(opt[u], size[e->t]);
		}
	}
}

char how[MAX_N];

void solve(int rt, char ch) {

	all.clear();
	dfs(rt, -1);

	int minOpt = int(1e9), who = -1;

	for (int i = 0; i < (int) all.size(); ++i) {
		int u = all[i];
		opt[u] = max(opt[u], size[rt] - size[u]);
		if (opt[u] < minOpt) {
			minOpt = opt[u];
			who = u;
		}
	}

	rt = who;
	how[rt] = ch;
	del[rt] = true;

	for (vector<Edge>::iterator e = E[rt].begin(); e != E[rt].end(); ++e) {
		if (!del[e->t]) {
			solve(e->t, ch + 1);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		E[a].push_back(Edge(b));
		E[b].push_back(Edge(a));
	}

	solve(0, 'A');

	for (int i = 0; i < n; ++i) {
		printf("%c ", how[i]);
	}
	puts("");
}