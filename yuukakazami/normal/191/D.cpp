#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;

vector<int> e[MAX_N];

int n, m;

bool vis[MAX_N];

vector<int> stack;

int id[MAX_N], nId;
bool inStack[MAX_N];

void dfs(int u, int par) {
	if (vis[u]) {
		if (!inStack[u])
			return;
		for (;;) {
			int x = stack.back();
			stack.pop_back();
			inStack[x] = false;
			id[x] = nId;
			if (x == u)
				break;
		}
		++nId;
		return;
	}
	vis[u] = true;
	stack.push_back(u);
	inStack[u] = true;

	for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); ++it) {
		if (*it != par)
			dfs(*it, u);
	}

	if (id[u] == -1) {
		stack.pop_back();
		inStack[u] = false;
	}
}

int cnt[MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		e[a].push_back(b), e[b].push_back(a);
	}

	memset(id, -1, sizeof id);

	for (int i = 0; i < n; ++i) {
		if (!vis[i])
			dfs(i, -1);
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += e[i].size() % 2;
		if (id[i] != -1)
			cnt[id[i]] += e[i].size() > 2;
	}

	ret /= 2;

	for (int i = 0; i < nId; ++i) {
		if (cnt[i] < 2)
			++ret;
	}

	cout << ret << " " << m << endl;

	return 0;
}