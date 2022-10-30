/*
 * D. Password.cpp
 *
 *  Created on: 2011-5-2
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int INF = INT_MAX / 4;

int main() {
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> state(n + 2, 0);
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		state[x] = 1;
	}

	vector<int> a;
	for (int i = 0; i < l; ++i) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	vector<int> diff(n + 2, 0);

	vector<int> pos;
	for (int i = 1; i <= n + 1; ++i) {
		diff[i] = state[i] ^ state[i - 1];
		if (diff[i])
			pos.push_back(i);
	}

	int cnt = pos.size();

	vector<vector<int> > dist(cnt);
	for (int i = 0; i < cnt; ++i) {
		queue<int> que;
		vector<int> am(n + 2, INF);
		am[pos[i]] = 0;
		que.push(pos[i]);
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			foreach(iter,a) {
				int use = *iter;
				if (u + use <= n + 1) {
					int v = u + use;
					if (am[v] == INF) {
						am[v] = am[u] + 1;
						que.push(v);
					}
				}
				if (u - use > 0) {
					int v = u - use;
					if (am[v] == INF) {
						am[v] = am[u] + 1;
						que.push(v);
					}
				}
			}
		}

		vector<int>&d = dist[i];
		d.resize(cnt);
		for (int id = 0; id < cnt; ++id) {
			d[id] = am[pos[id]];
		}
	}

	vector<int> dp(1 << cnt, INF);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << cnt); ++mask) {
		if (dp[mask] == INF)
			continue;
		int a1 = 0;
		while (mask >> a1 & 1)
			++a1;
		for (int a2 = a1 + 1; a2 < cnt; ++a2) {
			if (!(mask >> a2 & 1)) {
				int nmask = mask | (1 << a1) | (1 << a2);
				dp[nmask] = min(dp[nmask], dp[mask] + dist[a1][a2]);
			}
		}
	}

	int ans = dp[(1 << cnt) - 1];
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
}