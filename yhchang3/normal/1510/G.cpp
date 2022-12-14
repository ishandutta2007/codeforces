#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back

vector<int> e[101];
const int N = 100, INF = 1e9;

int dp[N + 1][N + 1][N + 1][2];
int sz[N + 1];

pair<int,int> from[N + 1][N + 1][N + 1][2];

void dfs(int x) {
	for(int i=0;i<=N;i++)
		for(int j=0;j<=e[x].size();j++)
			dp[x][i][j][0] = dp[x][i][j][1] = INF;
	sz[x] = 1;
	dp[x][1][0][0] = 0;
	dp[x][1][0][1] = 0;
	for(int _=0;_<e[x].size();_++) {
		int y = e[x][_];
		dfs(y);
		sz[x] += sz[y];
		for(int i=sz[x];i>=1;i--) {
			dp[x][i][_+1][0] = dp[x][i][_][0];
			from[x][i][_+1][0] = make_pair(i, 0);
			dp[x][i][_+1][1] = dp[x][i][_][1];
			from[x][i][_+1][1] = make_pair(i, 1);
			for(int j=sz[y];j>=1;j--) {
				int cur = dp[x][i][_][0] + 2 + dp[y][j][e[y].size()][0];
				if(cur < dp[x][i+j][_+1][0]) {
					dp[x][i+j][_+1][0] = cur;
					from[x][i+j][_+1][0] = make_pair(i, 0);
				}
				cur = dp[x][i][_][0] + 1 + dp[y][j][e[y].size()][1];
				if(cur < dp[x][i+j][_+1][1]) {
					dp[x][i+j][_+1][1] = cur;
					from[x][i+j][_+1][1] = make_pair(i, 0);
				}
				cur = dp[x][i][_][1] + 2 + dp[y][j][e[y].size()][0];
				if(cur < dp[x][i+j][_+1][1]) {
					dp[x][i+j][_+1][1] = cur;
					from[x][i+j][_+1][1] = make_pair(i, 1);
				}
			}
		}
	}
}

void solve(int x, int csz, int z) {
	cout << x << ' ';
	int spidx = 0, spsz = 0;
	for(int i=e[x].size();i>=1;i--) {
		auto [psz, w] = from[x][csz][i][z];
		if(psz != csz) {
			if(z - w == 1) {
				spidx = e[x][i-1];
				spsz = csz - psz;
			}
			else {
				solve(e[x][i-1], csz - psz, 0);
				cout << x << ' ';
			}
		}
		z = w, csz = psz;
	}
	if(spidx != 0) {
		solve(spidx, spsz, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		for(int i=1;i<=n;i++)
			vector<int>().swap(e[i]);
		for(int i=2;i<=n;i++) {
			int p;
			cin >> p;
			e[p].eb(i);
		}
		dfs(1);
		cout << dp[1][k][e[1].size()][1] << '\n';
		solve(1, k, 1);
		cout << '\n';
	}
}