#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
ll dp[505][505];

int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(int j = 0; j <= n; j++){
            for(int l = 1; j+l <= n && l <= i; l++){
                dp[i][j+l] += dp[i][j];
                dp[i][j+l] %= MOD;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i*j < k) {
                ans += (2*(dp[i][n]-dp[i-1][n])*(dp[j][n]-dp[j-1][n]))%MOD;
                ans %= MOD;
            }
        }
    }
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
}