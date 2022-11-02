#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
const int MOD = int(1e9) + 7;

void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

vector<int> E[MAX_N];
int col[MAX_N];
int n;

int dp[MAX_N][2]; //white, black

void dfs(int u, int par) {
//	for (auto v : E[u])
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		int v = *e;
		if (v != par) {
			dfs(v, u);
		}
	}
	vector<int> am(2, 0);
	am[col[u]] = 1;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		int v = *e;
		if (v != par) {
			int*ch = dp[v];
			vector<int> nam(2, 0);
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					//link
					if (i + j < 2)
						addIt(nam[i + j], 1LL * am[i] * ch[j] % MOD);
					//cut
					if (j == 1)
						addIt(nam[i], 1LL * am[i] * ch[j] % MOD);
				}
			}
			am = nam;
		}
	}

	for (int i = 0; i < 2; ++i) {
		dp[u][i] = am[i];
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p;
		scanf("%d", &p);
		E[i].push_back(p), E[p].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", col + i);
	}
	dfs(0, -1);
	cout << dp[0][1] << endl;
}