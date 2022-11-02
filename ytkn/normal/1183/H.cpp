#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

vector<int> v[26];
ll dp[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, K;
    cin >> n >> K;
    string s;
    cin >> s;
    for(int i = 0; i < 26; i++) v[i].push_back(0);
    for(int i = 0; i < n; i++) v[s[i]-'a'].push_back(i+1);
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        int m = s[i]-'a';
        auto p = lower_bound(v[m].begin(), v[m].end(), i+1);
        p--;
        int l = *p;
        // cout << l << ' ' << v[m].size() << endl;
        for(int j = l; j <= i; j++){
            for(int k = 0; k+1 <= i+1; k++) dp[i+1][k+1] += dp[j][k];
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= i; j++) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    ll cnt = 0;
    ll ans = 0;
    for(int i = n; i >= 0; i--){
        ll tmp = 0;
        for(int j = 0; j <= n; j++) tmp += dp[j][i];
        if(cnt+tmp >= K){
            ans += (n-i)*(K-cnt);
            cout << ans << endl;
            return 0;
        }
        cnt += tmp;
        ans += (n-i)*tmp;
        // cout << cnt << ' ' << ans << endl;
    }
    cout << -1 << endl;
}