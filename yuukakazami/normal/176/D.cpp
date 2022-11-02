/*
 * d.cpp
 *
 *  Created on: 2012-4-20
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

const int MAX_N = 2000 + 10;
string ls[MAX_N];
int n;
int m;
int ids[MAX_N];

const int INF = INT_MAX / 4;

struct Data {
	vector<vector<int> > next;
	int n;
	void init(string a) {
		n = a.size();
		next.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
			next[i].resize(26);
		}
		for (int i = 0; i < 26; ++i) {
			next[n][i] = INF;
		}

		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 26; ++j) {
				next[i][j] = next[i + 1][j];
			}
			next[i][a[i] - 'a'] = i;
		}
	}
};

Data ds[MAX_N];

string s;

pair<int, int> next[MAX_N][26];

pair<int, int> getNext(pair<int, int> a,int ch) {
	int at = a.first;
	if (at >= m)
		return make_pair(INF, INF);
	int me = ids[at];
	int t = ds[me].next[a.second][ch];
	if (t != INF)
		return make_pair(at, t);
	if (at + 1 == m)
		return make_pair(INF, INF);
	return next[at + 1][ch];
}

pair<int, int> goNext(pair<int, int> a) {
	int at = a.first;
	int me = ids[at];
	if (a.second + 1 < ds[me].n)
		return make_pair(at, a.second + 1);
	else
		return make_pair(at + 1, 0);
}

pair<int, int> dp[MAX_N][MAX_N]; //len,at

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ls[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> ids[i];
		--ids[i];
	}
	cin >> s;

	for (int i = 0; i < n; ++i) {
		ds[i].init(ls[i]);
	}

	for (int i = 0; i < 26; ++i) {
		next[m][i] = make_pair(INF, INF);
	}
	for (int i = m - 1; i >= 0; --i) {
		int me = ids[i];
		for (int j = 0; j < 26; ++j) {
			if (ds[me].next[0][j] != INF) {
				next[i][j] = make_pair(i, ds[me].next[0][j]);
			} else
				next[i][j] = next[i + 1][j];
		}
	}

	for (int i = 0; i <= s.size(); ++i) {
		for (int j = 0; j <= s.size(); ++j) {
			dp[i][j] = make_pair(INF, INF);
		}
	}

	dp[0][0] = make_pair(0, 0);

	int ans = 0;
	for (int len = 0; len <= s.size(); ++len) {
		for (int i = 0; i < s.size(); ++i) {
			dp[len][i + 1] = min(dp[len][i + 1], dp[len][i]);
		}
		if (dp[len][s.size()].first == INF)
			break;
		ans = len;
		for (int i = 0; i < s.size(); ++i) {
			int me = s[i] - 'a';
			if (dp[len][i].first != INF) {
				pair<int, int> nxt = getNext(dp[len][i], me);
				if (nxt.first != INF) {
					nxt = goNext(nxt);
					dp[len + 1][i + 1] = min(dp[len + 1][i + 1], nxt);
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}