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

typedef pair<ll, ll> P;

const ll MOD = 1000000007;

ll inv(ll n){
    if(n == 1) return 1;
    else return MOD-inv(MOD%n)*(MOD/n)%MOD;
}

P dp[10005][60];

map<ll, int> factorize(ll n){
    map<ll, int> mp;
    ll m = n;
    for(ll i = 2; i*i <= n; i++){
        if(m%i == 0){
            int cnt = 0;
            while(m%i == 0){
                cnt++;
                m /= i;
            }
            mp[i] = cnt;
        }
    }
    if(m != 1) mp[m] = 1;
    return mp;
}

P add(P a, P b){
    P ans;
    ans.first = (a.first*b.second+a.second*b.first)%MOD;
    ans.second = (a.second*b.second)%MOD;
    return ans;
}

P sub(P a, P b){
    P ans;
    ans.first = ((a.first*b.second-a.second*b.first)%MOD+MOD)%MOD;
    ans.second = (a.second*b.second)%MOD;
    return ans;
}

P mul(P a, P b){
    P ans;
    ans.first = (a.first*b.first)%MOD;
    ans.second = (a.second*b.second)%MOD;
    return ans;
}

ll n, k;
P unit = P(1, 1);
P zero = P(0, 1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    map<ll, int> mp = factorize(n);
    P ans = unit;
    for(auto iter : mp){
        ll p = iter.first;
        int cnt = iter.second;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= cnt; j++){
                dp[i][j] = zero;
            }
        }
        dp[0][cnt] = unit;
        for(int i = 0; i < k; i++){
            for(int j = 0; j <= cnt; j++){
                for(int k = 0; k <= j; k++){
                    dp[i+1][k] = add(dp[i+1][k], mul(dp[i][j], P(1, j+1)));
                }
            }
        }
        P sum = zero;
        P tmp = unit;
        for(int i = 0; i <= cnt; i++){
            sum = add(sum, mul(tmp, dp[k][i]));
            tmp = mul(tmp, P(p, 1));
        }
        ans = mul(ans, sum);
    }
    cout << (ans.first*inv(ans.second))%MOD << endl;
}