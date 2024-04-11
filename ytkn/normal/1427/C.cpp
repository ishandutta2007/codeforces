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

int r, n;
int dp[100005];

int dp_max[100005];
int t[100005], x[100005], y[100005];

int dist(int i, int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

void input(){
    cin >> r >> n;
    x[0] = 1; y[0] = 1;
    for(int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i]; 
}

void solve(){
    for(int i = 1; i <= n; i++){
        auto p = lower_bound(t, t+n+1, t[i]-2*r);
        int m = p-t;
        // cout << i << ' ' << m << endl;
        if(m != 0) dp[i] = dp_max[m-1]+1;
        for(int j = m; j < i; j++){
            if(dist(i, j) <= t[i]-t[j]){
                if(dp[j] != 0 || j == 0) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        dp_max[i] = max(dp[i], dp_max[i-1]);
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    cout << dp_max[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}