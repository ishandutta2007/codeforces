#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
const int MOD = 998244353;
void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<vector<bool> > g(10, vector<bool>(10, false));
	for (int i=0;i<10;++i) g[i][i] = true;
	for (int i=0;i<m;++i){
		int x, y;
		cin >> x >> y;
		g[x][y] = true;
		g[y][x] = true;
	}
	vector<vector<int> > G(1024, vector<int>(10));
	for (int msk=0;msk<1024;++msk){
		for (int i=0;i<10;++i){
			if(msk&(1<<i)){
				int msk2 = 0;
				for (int j=0;j<10;++j){
					if (g[i][j]) {
						if (i < j && msk&(1<<j)){
							msk2 |= (1<<j);
						}
					} else {
						msk2 |= (1<<j);
					}
				}
				G[msk][i] = msk2;
			} else {
				G[msk][i] = -1;
			}
		}
	}
	vector<vector<int> > dp(n+1, vector<int>(1024));
	for (int i=0;i<1024;++i) dp[n][i] = 0;

	// dp[i][j] = sum_k dp[i+1+k][nxt j] + dp[i+1+k][other j]
	for (int i=n-1;i>=0;--i){
		for (int j=0;j<1024;++j){
			dp[i][j] = dp[i+1][j];
			for (int k=0;k<10;++k){
				if (G[j][k] == -1) continue;
				(dp[i][j] += 1 + dp[i+1][G[j][k]]) %= MOD;
			}
		}
	}
	// 1 0
	// 1 2
	// 1 2 0
	// 2 0 1

	cout << (dp[0][1023] + MOD - dp[1][1023]) % MOD << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}