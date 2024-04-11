/*
 * c.cpp
 *
 *  Created on: 2011-9-15
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MOD = int(1e6) + 3;
typedef long long int64;

int64 calc(vector<vector<int> > map) {
	//-1,0,1
	int64 ret = 1;
	int n = map.size(), m = map[0].size();
	for (int r = 0; r < n; ++r) {
		vector<int64> am(2, 0);
		if (map[r][0] == -1) {
			am[0] = am[1] = 1;
		} else {
			am[map[r][0]] = 1;
		}
		for (int c = 1; c < m; ++c) {
			vector<int64> nam(2, 0);
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					if (i == 1 && j != 0)
						continue;
					if (j == 0 && i != 1)
						continue;
					if (map[r][c] != -1 && map[r][c] != j)
						continue;
					nam[j] += am[i];
					if (nam[j] >= MOD)
						nam[j] -= MOD;
				}
			}
			am = nam;
		}
		ret *= (am[0] + am[1]) % MOD;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char> > M(n, vector<char>(m));
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			scanf(" ");
			scanf("%c", &M[r][c]);
		}
	}
	vector<vector<int> > map(n, vector<int>(m));
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (M[r][c] == '.') {
				map[r][c] = -1;
			} else {
				int id = M[r][c] - '0';
				map[r][c] = id < 3 ? 0 : 1;
			}
		}
	}
	//	for (int r = 0; r < n; ++r) {
//		for (int c = 0; c < m; ++c) {
//			cout << map[r][c] << " ";
//		}
//		cout << endl;
//	}
	int64 ans = calc(map);
	map = vector<vector<int> >(m, vector<int>(n));
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (M[r][c] == '.') {
				map[c][r] = -1;
			} else {
				int id = M[r][c] - '0';
				map[c][r] = (id == 1 || id == 4) ? 0 : 1;
			}
		}
	}
	ans = ans * calc(map) % MOD;
	cout << ans << endl;
	return 0;
}