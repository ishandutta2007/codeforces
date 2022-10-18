#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;

    long long r = modpow(x, p / 2);
    return r * r % MOD;
}
long long modinv(long long x){
    return modpow(x, MOD - 2);
}

long long dp[1 << 14];
map <int, long long> pre[1 << 14];

int main(){
    int n;
    scanf("%d", &n);
    
    vector <int> a(n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);

    vector < vector <long long> > g(n, vector <long long> (n));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)if(i != j){
        g[i][j] = 1LL * a[i] * modinv(a[i] + a[j]) % MOD;
    }

    for(int mask = 1; mask < (1 << n); mask++)
    for(int sub = mask; sub > 0; sub = (sub - 1) & mask){
        if(mask == sub){
            pre[mask][sub] = 1;
            continue;
        }

        int i;
        for(i = 0; i < n; i++)if(mask & (1 << i)){
            if(sub & (1 << i))continue;
            break;
        }

        pre[mask][sub] = pre[mask ^ (1 << i)][sub];
        for(int j = 0; j < n; j++)if(sub & (1 << j)){
            pre[mask][sub] = (pre[mask][sub] * g[i][j]) % MOD;
        }
    }

    long long res = 0;
    for(int st = 0; st < n; st++){
        for(int mask = 0; mask < (1 << n); mask++)if(mask & (1 << st)){
            dp[mask] = 1;
            for(int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask)if(submask & (1 << st)){
                dp[mask] = (dp[mask] - (dp[submask] * pre[mask][submask] % MOD) + MOD) % MOD;
            }
        }
        res = (res + dp[(1 << n) - 1]) % MOD;
    }

    printf("%lld\n", res);

    return 0;
}