#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 100005;
const int MAXM = 1 << 9;

vector <int> g[MAXN];
int dp[MAXN], vis[MAXN];
long long f[MAXM];

long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;

    long long r = modpow(x, p / 2);
    return r * r % MOD;
}
long long modinv(long long x){
    return modpow(x, MOD - 2);
}

int grundy(int u){
    if(dp[u] != -1)return dp[u];

    vector <int> opts;
    for(int v : g[u])opts.push_back(grundy(v));
    
    for(int x : opts)vis[x]++;

    dp[u] = 0;
    while(vis[dp[u]] != 0)dp[u]++;

    for(int x : opts)vis[x]--;

    return dp[u];
}

void fwht(){
    for(int len = 2; len <= MAXM; len *= 2){
        for(int i = 0; i < MAXM; i += len){
            for(int j = 0; j < len / 2; j++){
                long long a = f[i + j];
                long long b = f[i + j + len / 2];
                f[i + j] = (a + b) % MOD;
                f[i + j + len / 2] = (a - b + MOD) % MOD;
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    while(m--){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        g[u].push_back(v);
    }

    memset(dp, -1, sizeof dp);

    long long prob = modinv(n + 1);
    for(int i = 0; i < n; i++){
        int gi = grundy(i);
        f[gi] = (f[gi] + prob) % MOD;
    }
    fwht();

    for(int i = 0; i < MAXM; i++)
        f[i] = modinv((1 - f[i] + MOD) % MOD);
    fwht();

    long long prob_lose = f[0] * modinv(MAXM) % MOD * prob % MOD;

    printf("%lld\n", (1 - prob_lose + MOD) % MOD);

    return 0;
}