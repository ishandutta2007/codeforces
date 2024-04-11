#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> > E;
vector<pair<int, int> > es;
map<pair<int, int> ,pair<int, int> > ms;
vector<int> low, ord;
int cur;

void dfs(int u, int fa) {
	ord[u] = low[u] = cur++;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != fa) {
			pair<int, int> key(u, *e);
			if (key.first > key.second)
				swap(key.first, key.second);

			if (ord[*e] == -1) {
				dfs(*e, u);
				if (low[*e] == ord[*e]) {
					throw 1;
				}
				low[u] = min(low[u], low[*e]);
				ms[key] = make_pair(u, *e);
			} else {
				low[u] = min(low[u], ord[*e]);
				if (ord[*e] < ord[u]) { //to anc
					ms[key] = make_pair(u, *e);
				}
			}
		}
	}
}

int main() {
	int nV, nE;
	cin >> nV >> nE;
	E.resize(nV);
	ord.assign(nV, -1);
	low.resize(nV);
	for (int i = 0; i < nE; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		E[a].push_back(b);
		E[b].push_back(a);
		if (a > b)
			swap(a, b);
		es.push_back(make_pair(a, b));
	}
	try {
		dfs(0, -1);
	} catch (...) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < nE; ++i) {
		pair<int, int> a = ms[es[i]];
		printf("%d %d\n", a.first + 1, a.second + 1);
	}
	return 0;
}