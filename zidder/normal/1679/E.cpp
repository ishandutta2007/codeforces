#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
const int MOD = 998244353;
long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}
long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<pair<int, int> > > msk(n, vector<pair<int, int> >(n+1, {-1, -1})); // [l, r)
	vector<vector<int> > pw(18, vector<int>(2000));
	for (int i=1;i<=17;++i) for (int j=0;j<2000;++j) pw[i][j] = binpow(i, j);
	for (int i=0;i<n;++i) msk[i][i] = {0, 0};
	for (int l=1;l<=n;++l){
		for (int i=0;i<n;++i){
			int j = i + l;
			if (j > n) break;
			if (l == 1) {
				msk[i][j] = {0, s[i]=='?'};
			}
			else {
				if (msk[i+1][j-1].first != -1){
					if (s[i] == s[j-1]) {
						msk[i][j] = msk[i+1][j-1];
						if (s[i] == '?') msk[i][j].second++;
					} else {
						if (s[i] == '?') {
							msk[i][j].second = msk[i+1][j-1].second;
							msk[i][j].first = msk[i+1][j-1].first | (1<<(s[j-1]-'a'));
						} else {
							if (s[j-1] == '?') {
								msk[i][j].second = msk[i+1][j-1].second;
								msk[i][j].first = msk[i+1][j-1].first | (1<<(s[i]-'a'));
							}
						}
					}
				}
			}
		}
	}
	vector<vector<long long> > dp1(1<<17, vector<long long>(18)), dp;
	dp = dp1;
	int c1 = 0;
	for (int i=0;i<n;++i) c1 += s[i] == '?';
	for (int i=0;i<n;++i){
		int c = 0;
		for (int j=i+1;j<=n;++j){
			c += s[j-1] == '?';
			if (msk[i][j].first != -1) {
				for (int k=1;k<=17;++k){
					(dp1[msk[i][j].first][k] += pw[k][c1-c+msk[i][j].second]) %= MOD;
				}
			}
		}
	}
	// auto bits = [&](int v){
	// 	int c = 0;
	// 	for (int i=0;i<17;++i) if (v&(1<<i))c++;
	// 	return c;
	// };
	// for (int i=0;i<(1<<17);++i){
	// 	int b = bits(i);
	// 	(dp[i] += dp1[0][b]) %= MOD;
	// 	for (int j=i;j;j=(j-1)&i){
	// 		(dp[i] += dp1[j][b]) %= MOD;
	// 	}
	// }
	for (int b=1;b<=17;++b){
		for(int i = 0; i<(1<<17); ++i)
			dp[i][b] = dp1[i][b];
		for(int i = 0;i < 17; ++i) for(int mask = 0; mask < (1<<17); ++mask){
			if(mask & (1<<i))
				(dp[mask][b] += dp[mask^(1<<i)][b]) %= MOD;
		}
	}
	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		string qi;
		cin >> qi;
		int v = 0;
		for (char c: qi){
			v |= (1<<(c-'a'));
		}
		cout << dp[v][qi.size()] << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}