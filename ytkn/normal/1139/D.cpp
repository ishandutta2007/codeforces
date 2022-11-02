#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define N_MAX 200002

using namespace std;
typedef long long ll;

vector<int> divs[100005];
ll dp[100005];
const ll MOD = 1000000007;

ll inv_(ll n){
    if(n == 1) return 1;
    else return MOD-inv_(MOD%n)*(MOD/n)%MOD;
}

vector<int> calc(int n){
    vector<int> ans;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            ans.push_back(i);
            if(i*i != n) ans.push_back(n/i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

ll cnt[100005];

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int m;
    cin >> m;
    for(int i = 1; i <= 100000; i++){
        divs[i] = calc(i);
    }
    dp[1] = 0;
    for(int i = 2; i <= m; i++){
        int sz = divs[i].size();
        for(int j = sz-1; j >= 0; j--){
            cnt[divs[i][j]] = m/divs[i][j];
            for(int k = sz-1; k > j; k--){
                if(divs[i][k]%divs[i][j] == 0) cnt[divs[i][j]] -= cnt[divs[i][k]];
            }
        }
        
        ll p = (cnt[divs[i][sz-1]]*inv[m])%MOD;
        ll sum = p;
        for(int j = 0; j < sz-1; j++){
            ll tmp = dp[divs[i][j]]+1;
            ll q = (cnt[divs[i][j]]*inv[m])%MOD;
            sum += (tmp*q)%MOD;
            sum %= MOD;
        }
        ll q = (1-p+MOD)%MOD;
        dp[divs[i][sz-1]] = (sum*inv_(q))%MOD;
    }
    ll ans = 1;
    for(int i = 1; i <= m; i++){
        ans += (dp[i]*inv[m])%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}