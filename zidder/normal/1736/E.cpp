#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long dp[2][501][501];
long long prf[2][502][502];

void solve(int test_ind){
	// [i][k][j] 
    //     j<i then [i-1][k-1][j]
    //     j=i then [i-1][k][t<i] or [i-1][k-1][i]
    //     j>i then [i-1][k-1][j] or [i-1][k-(j-i)][t<j]
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    for (int i=0;i<n;++i) {
        dp[0][i][i] = a[i];
        for (int j=0;j<n;++j){
            if (j != i) dp[0][i][j] = -1;
            prf[0][i][j+1] = max(prf[0][i][j], dp[0][i][j]);
        }
    }
    int ind = 0;
    for (int i=1;i<n;++i) {
        for (int k=0;k<=n;++k) {
            prf[ind^1][k][0] = -1;
            for (int j=0;j<n;++j) {
                dp[ind^1][k][j] = -1;
                if (k > i + 1) {prf[ind^1][k][j+1] = prf[ind^1][k][j];continue;}
                if (j < i) {
                    if (k && dp[ind][k-1][j] != -1) dp[ind^1][k][j] = dp[ind][k-1][j] + a[j];
                } else {
                    if (j == i) {
                        dp[ind^1][k][j] = max(k?dp[ind][k-1][j]:-1, prf[ind][k][j]);
                        if (dp[ind^1][k][j] != -1) dp[ind^1][k][j] += a[i];
                    } else {
                        dp[ind^1][k][j] = max(k?dp[ind][k-1][j]:-1, ((k-j+i>=0)?prf[ind][k-(j-i)][j]:-1));
                        if (dp[ind^1][k][j] != -1) dp[ind^1][k][j] += a[j];
                    }
                }
                // cout << i << " " << k << " " << j << " " << dp[ind^1][k][j] << endl;
                prf[ind^1][k][j+1] = max(prf[ind^1][k][j], dp[ind^1][k][j]);
            }
        }
        ind ^= 1;
    }
    long long ans = 0;
    for (int i=0;i<=n;++i) {
        for (int j=0;j<n;++j) {
            ans = max(ans, dp[ind][i][j]);
        }
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}