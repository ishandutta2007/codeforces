#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

int n;
long long k;

long long modpow(long long a, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;
    
    long long r = modpow(a, p / 2);
    return r * r % MOD;
}
long long modinv(long long a){
    return modpow(a, MOD - 2);
}

int main(){
    scanf("%d %lld", &n, &k);
    
    if(k >= n){
        printf("0\n");
        return 0;
    }
    
    if(k == 0){
        long long res = 1;
        for(int i = 1; i <= n; i++)
            res = res * i % MOD;
        printf("%lld\n", res);
    }else{
        long long r = 0, cc = 1;
        for(int i = n - k; i >= 1; i--){
            if((n - k - i) % 2 == 0){
                r = (r + modpow(i, n) * cc) % MOD;
            }else{
                r = (r + (MOD - cc) * modpow(i, n)) % MOD;
            }
            cc = cc * i % MOD * modinv(n - k - i + 1) % MOD;
        }
        
        long long c = 2;
        for(int i = 0; i < k; i++)
            c = c * (n - i) % MOD * modinv(i + 1) % MOD;
            
        printf("%lld\n", c * r % MOD);
    }
    return 0;
}