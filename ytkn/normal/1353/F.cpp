#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
ll dp[100][100];
ll a[100][100];
int n, m;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll ans = 3e18;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < m; l++){
                    dp[k][l] = 3e18;
                }
            }
            for(int k = 0; k <= i; k++){
                for(int l = 0; l <= j; l++){
                    ll dif = a[k][l]-a[i][j]+(i+j)-(k+l);
                    if(dif < 0) continue;
                    if(k == 0 && l == 0) dp[k][l] = dif;
                    if(k > 0) dp[k][l] = min(dp[k][l], dp[k-1][l]+dif);
                    if(l > 0) dp[k][l] = min(dp[k][l], dp[k][l-1]+dif);
                }
            }
            for(int k = i; k < n; k++){
                for(int l = j; l < m; l++){
                    ll dif = a[k][l]-a[i][j]+(i+j)-(k+l);
                    if(dif < 0) continue;
                    if(k > i) dp[k][l] = min(dp[k][l], dp[k-1][l]+dif);
                    if(l > j) dp[k][l] = min(dp[k][l], dp[k][l-1]+dif);
                }
            }
            ans = min(ans, dp[n-1][m-1]);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}