/*
 * d.cpp
 *
 *  Created on: 2012-3-11
 *      Author: mac
 */
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
int n, k;
const int MAX_N = 50000 + 10;
const int MAX_K = 500 + 10;

typedef long long ll;

ll down[MAX_N][MAX_K], up[MAX_N][MAX_K];

vector<int> E[MAX_N];

void dfs(int u, int par) {
	down[u][0] = 1;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par) {
			dfs(*e, u);
			for (int j = 1; j <= k; ++j) {
				down[u][j] += down[*e][j - 1];
			}
		}
	}
}

void dfs2(int u, int par) {
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par) {
			for (int j = 1; j <= k; ++j) {
				up[*e][j] = up[u][j - 1] + down[u][j - 1] - (j >= 2 ? down[*e][j - 2] : 0);
			}
			dfs2(*e, u);
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	memset(down, 0, sizeof down);
	memset(up, 0, sizeof up);
	dfs(0, -1);
	dfs2(0, -1);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += up[i][k] + down[i][k];
	}
	ans /= 2;
	cout << ans << endl;
}