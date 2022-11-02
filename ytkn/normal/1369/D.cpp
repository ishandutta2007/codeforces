#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[2000006][3];

void init(){
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = 0;
    dp[2][1] = 0;
    for(int i = 3; i <= 2000000; i++){
        dp[i][1] = max(dp[i-1][0], dp[i-1][1])+2*max(dp[i-2][0], dp[i-2][1]);
        dp[i][0] = dp[i-1][1]+2*dp[i-2][1]+4;
        dp[i][1] %= MOD;
        dp[i][0] %= MOD;
    }
}

void solve(){
    int n;
    cin >> n;
    cout << max(dp[n][0], dp[n][1]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    init();
    for(int i = 0; i < t; i++){
        solve();
    }
}