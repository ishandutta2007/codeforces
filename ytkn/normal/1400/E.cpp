#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n;
int a[5005];
int dp[5005][5005];

// [i:n] dp[k]-kmin
int min_r[5005];
// [0:i] dp[k]min
int min_l[5005];

const int INF = 1e6;

void solve(){
    for(int i = 1; i <= n; i++) dp[0][i] = INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++){
        min_l[0] = dp[i-1][0];
        for(int j = 1; j <= n; j++) min_l[j] = min(min_l[j-1], dp[i-1][j]-j);
        min_r[n+1] = INF;
        for(int j = n; j >= 0; j--) min_r[j] = min(min_r[j+1], dp[i-1][j]);
        for(int j = 0; j <= min(a[i], n); j++){
            if(j == a[i]){
                dp[i][j] = min(min_l[j]+j, min_r[j+1]);
            }else{
                dp[i][j] = min(min_l[j]+j, min_r[j+1])+1;
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    
    int ans = INF;
    for(int i = 0; i <= min(a[n], n); i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    solve();
}