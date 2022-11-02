#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;
vector<int> E[MAX_N];
int n;
int init[MAX_N], goal[MAX_N];
int ans;

vector<int> at;

void dfs(int u, int par, int dep, int c0, int c1) {
	int me = init[u];
	if (dep % 2 == 0)
		me ^= c0;
	else
		me ^= c1;
	if (me != goal[u]) {
		at.push_back(u);
		if (dep % 2 == 0)
			c0 ^= 1;
		else
			c1 ^= 1;
		++ans;
	}

	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (*e != par) {
			dfs(*e, u, dep + 1, c0, c1);
		}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", init + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", goal + i);
	}
	dfs(0, -1, 0, 0, 0);
	cout << ans << endl;
	sort(at.begin(), at.end());
	for (int i = 0; i < at.size(); ++i) {
		cout << at[i] + 1 << endl;
	}
}