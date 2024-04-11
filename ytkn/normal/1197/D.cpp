#include <iostream>

using namespace std;
typedef long long ll;

ll dp[300000][10];
ll a[300000];

const ll INF = 1e+17;;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        dp[n][i] = -INF;
    }
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        //j = 0;
        dp[i][0] = max(a[i]-k, a[i]+dp[i+1][m-1]-k);
        ans = max(ans, dp[i][0]);
        //cout << ans << endl;
        //else
        for(int j = 1; j <= m-1; j++){
            dp[i][j] = dp[i+1][j-1] + a[i];
            ans = max(ans, dp[i][j]);
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}