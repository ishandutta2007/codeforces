#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = int(2e5) + 10;
int n;
vector<int> E[MAX_N];

void addEdge(int u, int v) {
	E[u].push_back(v), E[v].push_back(u);
}

int col[MAX_N];

void dfs(int u, int c) {
	if (col[u] != -1)
		return;
	col[u] = c;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		dfs(*e, 1 - c);
	}
}

int main() {
	cin >> n;
	vector<pair<int, int> > events;
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		l *= 2, r = r * 2 + 1;
		addEdge(i * 2, i * 2 + 1);
		events.push_back(make_pair(l, 2 * i));
		events.push_back(make_pair(r, 2 * i + 1));
	}
	sort(events.begin(), events.end());
	for (int i = 0; i < n; ++i) {
		addEdge(events[i * 2].second, events[i * 2 + 1].second);
	}
	memset(col, -1, sizeof col);
	for (int i = 0; i < n * 2; ++i) {
		if (col[i] == -1)
			dfs(i, 0);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", col[i * 2]);
	}
	puts("");
}