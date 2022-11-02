#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int mod = 998244353;

long long n, k;
const int maxn = 2005;
int h[maxn];

long long fac[maxn], inv[maxn];

long long qpow(long long a, long long n){
    long long ret = 1;
    while(n > 0){
        if(n & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

long long C(long long n, long long k){
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main(){
    cin >> n >> k;
    int eq = 0;
    int ineq = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", &h[i]);
    }
    for(int i = 1;i <= n;i++){
        int nxt = i % n + 1;
        if(h[nxt] == h[i]){
            eq++;
        }else{
            ineq++;
        }
    }
    long long ans = 0;
    fac[0] = 1;
    for(int i = 1;i <= n;i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }  
    inv[n] = qpow(fac[n], mod - 2) % mod;
    for(int i = n - 1;i >= 0;i--){
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
    for(int i = 1;i <= ineq;i++){
        for(int j = 0;j <= ineq - i && j < i;j++){
            long long temp = C(ineq, i) * C(ineq - i, j) % mod * qpow(k - 2, ineq - i - j) % mod;
            ans = (ans + temp) % mod;
        }
    }
    ans = ans * qpow(k, eq) % mod;
    cout << ans << endl;
    return 0;
}