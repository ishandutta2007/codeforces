#include <bits/stdc++.h>
using namespace std;

int n, m;

const int maxn = 2e5 + 5;

typedef long long ll;
const int mod = 998244353;
ll a[maxn];
ll base[60];
ll power[maxn];

void insert(ll x){
    for(int i = m - 1;i >= 0;i--){
        if(x & (1LL << i)){
            if(base[i] != 0){
                x ^= base[i];
            }else{
                base[i] = x;
                break;
            }
        }
    }
}

ll ans[40];

void add(ll &a, ll b){
    a += b;
    if(a >= mod)
        a -= mod;
}

ll dp[2][40][(1 << 16) + 5];

void compute(){
    for(int i = m - 1;i >= 0;i--){
        if(base[i] != 0){
            for(int j = m - 1;j >= 0;j--){
                if(j == i)
                    continue;
                if(base[j] & (1LL << i)){
                    base[j] ^= base[i];
                }
            }
        }
    }
}

int val[60];

bool cmp(int i, int j){
    return val[i] < val[j];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        insert(a[i]);
    }
    compute();
    for(int i = 0;i < m;i++){
        if(base[i] != 0){
            val[i] = 1; 
        }
    }
    vector<int> id(m, 0);
    for(int i = 0;i < m;i++){
        id[i] = i;
    }
    vector<int> rid(m, 0);
    sort(id.begin(), id.end(), cmp);
    for(int i = 0;i < m;i++){
        rid[id[i]] = i;
    }
    vector<ll> Base;
    for(int i = 0;i < m;i++){
        if(base[i] != 0){
            ll tmp = 0;
            for(int j = 0;j < m;j++){
                if(base[i] & (1LL << j)){
                    tmp |= (1LL << rid[j]);
                }
            }
            Base.push_back(tmp);
        }
    }
    power[0] = 1;
    for(int i = 1;i <= n;i++){
        power[i] = power[i - 1] * 2 % mod;
    }
    if(Base.size() <= 20){
        int z = Base.size();
        for(int i = 0;i < (1 << z);i++){
            ll tmp = 0;
            for(int j = 0;j < z;j++){
                if(i & (1 << j)){
                    tmp = tmp ^ Base[j];
                }
            }            
            int cnt = __builtin_popcountll(tmp);
            add(ans[cnt], power[n - z]);
        }
    }else{
        int z = Base.size(); 
        int y = m - z;
        ll mask = (1LL << y) - 1;
        dp[0][0][0] = 1;
        for(int i = 1;i <= z;i++){
            int cur = i & 1;
            int pre = cur ^ 1;
            memset(dp[cur], 0, sizeof(dp[cur]));
            for(int j = 0;j <= z;j++){
                for(int k = 0;k <= mask;k++){
                    if(dp[pre][j][k] == 0)
                        continue;
                    ll val = Base[i - 1] & mask;
                    add(dp[cur][j + 1][k ^ val], dp[pre][j][k]);
                    add(dp[cur][j][k], dp[pre][j][k]);
                }
            }
        }
        for(int j = 0;j <= z;j++){
            for(int k = 0;k <= mask;k++){
                int cnt = j + __builtin_popcount(k);
                add(ans[cnt], dp[z & 1][j][k]);
            }
        }
        for(int i = 0;i <= m;i++){
            ans[i] = ans[i] * power[n - z] % mod;
        }
    }
    for(int i = 0;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}