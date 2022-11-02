#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int n;
const int maxn = 1e6 + 5;
typedef long long ll;
ll r1, r2, r3, d;
ll a[maxn];
ll dp[maxn][2];
ll suf[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i <= n;i++){
        dp[i][0] = dp[i][1] = 1e18;
        suf[i] = 1e18;
    }
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + min(r1 * (a[i] + 1), r2) + r1 + 3 * d);
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + r1 * a[i] + r3 + d);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + min(r1 * (a[i] + 1), r2) + r1 + d);
    }
    suf[n] = min(r1 * a[n] + r3, 2 * d + min(r1 * (a[n] + 2), r2 + r1)); 
    for(int i = n - 1;i >= 1;i--){
        suf[i] = min(suf[i], suf[i + 1] + min(r1 * a[i] + r3, min(r1 * (a[i] + 2), r2 + r1))) + 2 * d;
    }
    ll ans = min(dp[n][0], dp[n][1]) - d;
    for(int i = n - 1;i >= 1;i--){
        ans = min(ans, min(dp[i-1][0], dp[i-1][1]) + suf[i]);
    }
    cout << ans << endl;
    return 0;
}