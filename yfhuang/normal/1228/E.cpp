#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5; 
 
int n, K;
int fac[maxn], inv[maxn];
 
int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}
 
void pre_comb(){
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for(int i = maxn - 2;i >= 0;i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}
 
int comb(int n, int m){
    if(m > n or m < 0) return 0;
    return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int dp[255][255];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int kpow[255], k1pow[255];

int main(){
    pre_comb();
    cin >> n >> K;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    kpow[0] = 1;
    for(int i = 1;i < 255;i++){
        kpow[i] = 1LL * kpow[i - 1] * K % mod;
    }
    k1pow[0] = 1;
    for(int i = 1;i < 255;i++){
        k1pow[i] = 1LL * k1pow[i - 1] * (K - 1) % mod;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n;j++){
            for(int k = 0;k < j;k++){
                add(dp[i][j], 1LL * dp[i - 1][k] * comb(j, k) % mod * kpow[k] % mod * k1pow[n - j] % mod);
            }
            add(dp[i][j], 1LL * dp[i - 1][j] * kpow[j] % mod * k1pow[n - j] % mod);
            add(dp[i][j], mod - 1LL * dp[i - 1][j] * k1pow[n] % mod);
        }
    } 
    cout << dp[n][n] << endl;
    return 0;
}