#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
	const int mod = (int)1e9+7;
	int n, k, d;
	cin >> n; cin >> k; cin >> d;
	vector<vector<int> > dp1(n+1, vector<int>(n+1,0));
	dp1[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 1; l <= min(k,j); l++) {
				dp1[i][j] = (dp1[i][j] + dp1[i-1][j-l]) % mod;
			}
		}
	}

	ll v=0;for(int i=1;i<=n;i++)v+=dp1[i][n],v%=mod;

	vector<vector<int> > dp2(n+1, vector<int>(n+1,0));
	dp2[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 1; l <= min(d-1,j); l++) {
				dp2[i][j] = (dp2[i][j] + dp2[i-1][j-l]) % mod;
			}
		}
	}
	ll v2=0;for(int i=1;i<=n;i++)v2+=dp2[i][n],v2%=mod;
	
	cout << ((v-v2)%mod+mod )%mod << endl;
}