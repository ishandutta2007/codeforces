#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

ll dp[405][405];
ll INF = 1e15;

void init_dp(int n){
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = INF;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> t(n);
    init_dp(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(), t.end());
    dp[0][0] = 0;
    for(int i = 1; i <= 2*n; i++){
        for(int j = 0; j <= n; j++){
            // 
            dp[i][j+1] = min(dp[i][j+1], dp[i-1][j]+abs(i-t[j]));
            // 
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[2*n][n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}