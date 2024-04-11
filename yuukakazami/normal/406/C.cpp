#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long int64;
const int MAX_N = int(1e5) + 10;
vector<int> E[MAX_N];
int n, m;
vector<int> extra[MAX_N];
bool instack[MAX_N], vis[MAX_N];
vector<int> atdep[MAX_N];

void dfs(int u, int par, int dep) {
	vis[u] = true;
	instack[u] = true;
	atdep[dep].push_back(u);

	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (instack[*e])
			extra[u].push_back(*e); //including par
		if (*e != par && !vis[*e]) {
			dfs(*e, u, dep + 1);
		}
	}

	instack[u] = false;
}

int main() {
	cin >> n >> m;
	if (m % 2 == 1) {
		puts("No solution");
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	dfs(0, -1, 0);

	for (int d = n - 1; d >= 0; --d) {
		for (vector<int>::iterator e = atdep[d].begin(); e != atdep[d].end();
				++e) {
			int u = *e;
			while (extra[u].size() >= 2) {
				int x = extra[u].back();
				extra[u].pop_back();
				int y = extra[u].back();
				extra[u].pop_back();
				printf("%d %d %d\n", x + 1, u + 1, y + 1);
			}
			if (!extra[u].empty()) {
				int x = extra[u].back();
				extra[u].pop_back();
				extra[x].push_back(u);
			}
		}
	}
}