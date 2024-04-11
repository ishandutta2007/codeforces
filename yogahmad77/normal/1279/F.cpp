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

const int mx = 1e6 + 10;

int n, k, l, a[mx], ambil[mx];
int dp[mx];

void compute_dp(int cost){
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + a[i];
        ambil[i] = ambil[i - 1];
        if(i >= l){
            if(dp[i - l] + cost < dp[i]){
                dp[i] = dp[i - l] + cost;
                ambil[i] = ambil[i - l] + 1;
            }
            else if(dp[i - l] + cost == dp[i] && ambil[i] > ambil[i - l] + 1){
                ambil[i] = ambil[i - l] + 1;
            }
        }
    }
}

int solve(){
    int lo = 0, hi = 1e6, mid, di;
    bool ada = 0;
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        compute_dp(mid);
        if(ambil[n] <= k){
            hi = mid - 1;
            di = mid;
        }
        else lo = mid + 1;
    }
    compute_dp(di);
    return dp[n] - di * k;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> l;
    if(1LL * k * l >= n){
        cout << 0 << endl;
        return 0;
    }
    string ss;
    cin >> ss;
    for(int i = 1; i <= n; i++){
        a[i] = ('a' <= ss[i - 1] && ss[i - 1] <= 'z' ) ? 1 : 0;
    }
    int ans = solve();
    for(int i = 1; i <= n; i++){
        a[i] = ('A' <= ss[i - 1] && ss[i - 1] <= 'Z' ) ? 1 : 0;
    }
    ans = min(ans, solve());
    cout << ans << endl;
}