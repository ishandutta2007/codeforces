#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
    int k;
	int n;
    cin >> n;
    cin >> k;
    vector<int> dp(n+1), dp1;
    vector<long long> ans(n+1);
    dp[0] = 1;

    for (int ki=0;ki<1050;++ki){
        int dl = k + ki;
        dp1 = vector<int>(n+1);
        for (int i=dl;i<=n;++i){
            dp1[i] = (dp[i-dl] + dp1[i-dl]) % MOD;
            ans[i] += dp1[i];
        }
        swap(dp, dp1);
    }

    for (int i=1;i<=n;++i){
        ans[i] %= MOD;
        printf("%d ", (int)ans[i]);
    }
    cout << endl;
}

int main(){
	int t=1;
	// cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}