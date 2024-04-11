/*
 * cd.cpp
 *
 *  Created on: 2012-11-6
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

const int MAX_N = 100 + 10, INF = ~0U >> 3;
const int MOD = int(1e9) + 7;

int n, m, vs, vt;
int dist[MAX_N][MAX_N], cnt[MAX_N][MAX_N];
int nB;
int st[MAX_N], ed[MAX_N];
bool e[MAX_N][MAX_N];

int dp[MAX_N][MAX_N]; //at,bus-end

bool mustPass(int u, int v, int mid) {
	//dose u->v must pass mid?
	return dist[u][mid] + dist[mid][v] == dist[u][v] && 1LL * cnt[u][mid] * cnt[mid][v] % MOD == cnt[u][v];
}

vector<int> nxt[MAX_N][MAX_N];

int main() {
	cin >> n >> m >> vs >> vt;
	--vs, --vt;
	fill(dist[0], dist[n], INF);
	memset(cnt, 0, sizeof cnt);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		dist[a][b] = 1;
		cnt[a][b] = 1;
		e[a][b] = true;
	}

	for (int i = 0; i < n; ++i) {
		dist[i][i] = 0;
		cnt[i][i] = 1;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				if (i != j && i != k && j != k) {
					//i->k->j
					int nd = dist[i][k] + dist[k][j];
					if (nd <= dist[i][j]) {
						int ncnt = 1LL * cnt[i][k] * cnt[k][j] % MOD;
						if (nd < dist[i][j]) {
							dist[i][j] = nd;
							cnt[i][j] = ncnt;
						} else {
							cnt[i][j] += ncnt;
							if (cnt[i][j] >= MOD)
								cnt[i][j] -= MOD;
						}
					}
				}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (e[i][k] && dist[i][k] + dist[k][j] == dist[i][j])
					nxt[i][j].push_back(k);
			}
		}
	}

	cin >> nB;
	int cnt = 0;
	for (int i = 0; i < nB; ++i) {
		cin >> st[cnt] >> ed[cnt];
		--st[cnt], --ed[cnt];
		if (dist[st[cnt]][ed[cnt]] != INF)
			++cnt;
	}
	nB = cnt;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = INF;
		}
	}

	dp[vt][n] = 0;
	for (int it = 0; it < n; ++it) {
		for (int i = 0; i < n; ++i) {
			//dp[i][n]
			for (int k = 0; k < nB; ++k) {
				if (mustPass(st[k], ed[k], i)) {
					dp[i][n] = min(dp[i][n], dp[i][ed[k]] + 1);
				}
			}
			for (int j = 0; j < n; ++j) {
				//dp[i][j]
				dp[i][j] = min(dp[i][j], dp[i][n]);
				if (i != j) {
					int t = 0;
					for (vector<int>::iterator e = nxt[i][j].begin(); e != nxt[i][j].end(); ++e) {
						t = max(t, dp[*e][j]);
					}
					dp[i][j] = min(dp[i][j], t);
				}
			}
		}
	}
	if (dp[vs][n] == INF)
		cout << -1 << endl;
	else
		cout << dp[vs][n] << endl;
	return 0;
}