#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

int n, m;

const int mod = 998244353;
const int maxn = 1e6 + 5;

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

int main(){
    cin >> n >> m; 
    pre_comb();
    if(n == 2){
        cout << 0 << endl;
        return 0;
    }else{
        int ans = comb(m, n - 1);
        ans = 1LL * ans * (n - 2) % mod;
        ans = 1LL * ans * qpow(2, n - 3) % mod;
        cout << ans << endl;
    }
    return 0;
}