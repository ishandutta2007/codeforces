#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = int(3e5) + 10;
int n, m;
vector<int> E[MAX_N];
queue<int> que;
int color[MAX_N];
bool bad(int u) {
	int cnt = 0;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (color[*e] == color[u])
			++cnt;
	}
	return cnt > 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (bad(i)) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		if (bad(u)) {
			color[u] = 1 - color[u];
			for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
				if (bad(*e))
					que.push(*e);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d", color[i]);
	}
	puts("");
	return 0;
}