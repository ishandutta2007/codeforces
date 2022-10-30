#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<int> E[120];
int maxD = 0;

void dfs(int u, int fa, int d) {
	maxD = max(maxD, d);
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != fa) {
			dfs(*e, u, d + 1);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nT;
	cin >> nT;
	int ret = 0;
	for (int i = 0; i < nT; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			E[j].clear();
		}
		for (int j = 0; j < n - 1; ++j) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			E[a].push_back(b), E[b].push_back(a);
		}
		maxD = 0;
		for (int j = 0; j < n; ++j) {
			dfs(j, -1, 0);
		}
		ret += maxD;
	}
	cout << ret << endl;
}