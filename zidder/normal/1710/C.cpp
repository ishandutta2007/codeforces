#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	string s;
    cin >> s;
    int n = s.size();
    vector<int> p8(n+1);
    p8[0] = 1;
    for (int i=1;i<=n;++i) p8[i] = (p8[i-1] * 8ll) % MOD;

    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(8, vector<int>(8))); // dp[ind][msk][dard]
    int c[8] = {0, 1, 1, 2, 1, 2, 2, 3}; // number of 1s
    for (int msk=0;msk<8;++msk) dp[n][msk][0] = 1;
    for (int i=n-1;i>=0;--i) {
        for (int dard=0;dard<8;++dard) {
            for (int msk=0;msk<8;++msk) {
                for (int msk2=0;msk2<8;++msk2) {
                    if (s[i] == '0' && (msk2&msk) != 0) continue;
                    int msk3 = msk;
                    if (s[i] != '0'){
                        if ((msk&1) && (msk2&1) == 0) msk3 ^= 1;
                        if ((msk&2) && (msk2&2) == 0) msk3 ^= 2;
                        if ((msk&4) && (msk2&4) == 0) msk3 ^= 4;
                    }
                    // try msk2 on i from msk
                    int dard2 = dard;
                    if ((msk2^1) == 0 || (msk2^1) == 7) dard2 &= 6;
                    if ((msk2^2) == 0 || (msk2^2) == 7) dard2 &= 5;
                    if ((msk2^4) == 0 || (msk2^4) == 7) dard2 &= 3;
                    // if (i == 1 && msk == 4 && dard == 3) cout << msk2 << " " << msk3 << " " << dard2 << endl;
                    dp[i][msk][dard] = (dp[i][msk][dard] + 0ll+ dp[i+1][msk3][dard2]) % MOD;
                }
                // cout << i << " " << msk << " " << dard << " " << dp[i][msk][dard] << endl;
            }
        }
    }
    cout << dp[0][7][7] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}