#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 50 + 1;
int E[MAX_N][MAX_N];
int nV, nE;
bool hasCycle;
int nComp;
bool visited[MAX_N];

void dfs(int u, int f) {
	visited[u] = true;
	for (int v = 0; v < nV; ++v) {
		if ((v != f && E[u][v] > 0) || E[u][v] == 2) {
			if (visited[v]) {
				hasCycle = true;
			} else {
				dfs(v, u);
			}
		}
	}
}

bool check() {
	for (int i = 0; i < nV; ++i) {
		int deg = accumulate(E[i], E[i] + nV, 0);
		if (deg > 2)
			return false;
	}
	hasCycle = false;
	nComp = 0;
	memset(visited, false, sizeof visited);
	for (int i = 0; i < nV; ++i) {
		if (!visited[i]) {
			nComp++;
			dfs(i, -1);
		}
	}
	if (nComp > 1 && hasCycle)
		return false;
	return true;
}

int main() {
	cin >> nV >> nE;
	if (nV == 2 && nE == 0) {
		cout << "YES" << endl;
		cout << 2 << endl;
		for (int i = 0; i < 2; ++i) {
			cout << 1 << " " << 2 << endl;
		}
		return 0;
	}
	for (int i = 0; i < nE; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		E[a][b]++;
		E[b][a]++;
	}
	if (!check()) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<int> a, b;
	for (int i = 0; i < nV; ++i) {
		for (int j = i; j < nV; ++j) {
			E[i][j]++;
			E[j][i]++;
			if (check()) {
				a.push_back(i);
				b.push_back(j);
			} else {
				E[i][j]--;
				E[j][i]--;
			}
		}
	}
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] + 1 << " " << b[i] + 1 << endl;
	}
	return 0;
}