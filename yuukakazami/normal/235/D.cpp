#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 3000 + 10;
vector<int> E[MAX_N];
int n;

vector<int> cyc;
vector<int> stack;
bool vis[MAX_N];
bool inCyc[MAX_N];
double inv[MAX_N];

void dfs(int u, int par) {
	if (vis[u]) { //find the cycle!
		for (;;) {
			int v = stack.back();
			stack.pop_back();
			cyc.push_back(v);
			if (v == u)
				break;
		}
		throw 1;
	}
	stack.push_back(u);
	vis[u] = true;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par)
			dfs(*e, u);
	}
	stack.pop_back();
}

void readInput() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

void findCycle() {
	try {
		dfs(0, -1);
	} catch (int e) {

	}
}

int cnt[MAX_N];

void dfsTree(int u, int par, int d) { //forbid moving on a cycle-edge
	cnt[d]++;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (inCyc[u] && inCyc[*e])
			continue;
		if (par == *e)
			continue;
		dfsTree(*e, u, d + 1);
	}
}

void dfsCount(int u, int par, int d, vector<int>&cnt) {
	while (cnt.size() <= d)
		cnt.push_back(0);
	cnt[d]++;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par && !inCyc[*e])
			dfsCount(*e, u, d + 1, cnt);
	}
}

void work() {
	double ans = 0;

	for (vector<int>::iterator e = cyc.begin(); e != cyc.end(); ++e) {
		inCyc[*e] = true;
	}
	//calc answer for trees
	for (int i = 0; i < n; ++i) {
		dfsTree(i, -1, 1);
	}
	for (int i = 1; i <= n; ++i) {
		inv[i] = 1.0 / i;
		ans += inv[i] * cnt[i];
	}
	//calc answer invole cycle
	int nCyc = cyc.size();
	static vector<int> cnts[MAX_N];
	for (int i = 0; i < nCyc; ++i) {
		dfsCount(cyc[i], -1, 1, cnts[i]);
	}

	for (int i = 0; i < nCyc; ++i) {
		for (int j = i + 1; j < nCyc; ++j) {
			vector<int>&icnt = cnts[i];
			vector<int>&jcnt = cnts[j];
			for (int a = 1; a < icnt.size(); ++a) {
				for (int b = 1; b < jcnt.size(); ++b) {
					int nPairs = icnt[a] * jcnt[b];
					int X = a + b - 1;
					int Y = j - i - 1;
					int Z = nCyc - Y - 2;
					double v = inv[X + Y + 1] + inv[X + Z + 1] - inv[X + Y + Z + 1];
					ans += v * nPairs * 2;
				}
			}
		}
	}

	printf("%0.15lf\n", ans);
}

int main() {
	readInput();
	findCycle();
	work();
	return 0;
}