#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())


const int MOD = 1e9 + 7;

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 1e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(2 * m + 1, vector<int>(n, 0));
    for(int i = 2 * m; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(i == 2 * m) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i + 1][j];
                if(j + 1 < n) dp[i][j] = add(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}