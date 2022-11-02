#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n;
vector<int> E[MAX_N];
int v[MAX_N];

typedef long long int64;

int64 ans;

pair<int64, int64> dfs(int u, int par) { //(plus,minus)
	pair<int64, int64> ret = make_pair(0, 0);
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par) {
			pair<int64, int64> t = dfs(*e, u);
			ret.first = max(ret.first, t.first);
			ret.second = max(ret.second, t.second);
		}
	}
	int64 nv = -(v[u] + ret.first - ret.second);
	if (nv > 0)
		ret.first += nv;
	else
		ret.second -= nv;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}
	ans = 0;
	pair<int64, int64> ret = dfs(0, -1);
	cout << ret.first + ret.second << endl;
	return 0;
}