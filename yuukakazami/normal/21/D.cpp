#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 15;
int dist[MAX_N][MAX_N];
int n, m;
int dp[1 << MAX_N];
bool v[MAX_N];

int main() {
	cin >> n >> m;
	fill(dist[0], dist[n], INT_MAX / 2);
	int ans = 0;
	int init = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		ans += c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = dist[a][b];
		init ^= 1 << a;
		init ^= 1 << b;
		v[a] = v[b] = true;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		if (v[i] && dist[0][i] == INT_MAX / 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	fill(dp, dp + init, INT_MAX / 2);
	dp[init] = 0;
	for (int i = init; i >= 0; --i) {
		for (int a = 0; a < n; ++a) {
			if (i >> a & 1)
				for (int b = 0; b < n; ++b) {
					if (i >> b & 1) {
						dp[i ^ (1 << a) ^ (1 << b)] = min(dp[i ^ (1 << a) ^ (1 << b)], dp[i] + dist[a][b]);
					}
				}
		}
	}
	cout << dp[0] + ans << endl;
	return 0;
}