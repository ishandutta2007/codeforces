#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1000005;

long long fact[MAXN], invfact[MAXN];

long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;

    long long r = modpow(x, p / 2);
    return r * r % MOD;
}

long long modinv(long long x){
    return modpow(x, MOD - 2);
}

long long choose(int n, int r){
    if(r > n)return 0LL;
    else return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}


int main(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = i * fact[i - 1] % MOD;

    invfact[MAXN - 1] = modinv(fact[MAXN - 1]);
    for(int i = MAXN - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int t;
    scanf("%d", &t);

    while(t--){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        m = n - m;

        if(m == 0){
            printf("%lld\n", 1LL * n * k % MOD);
            continue;
        }

        long long res = 0, p2inv = 1;
        for(int i = n; i >= 1; i--){
            res = (res + choose(n - i - 1, m - 1) * p2inv % MOD * i) % MOD;
            p2inv = p2inv * ((MOD + 1) / 2) % MOD;
        }

        printf("%lld\n", res * k % MOD);
    }

    return 0;
}