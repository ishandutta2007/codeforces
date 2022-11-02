#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

int cal(int n, int m){
    int ans = 0;
    for(int i = 0;i < m;i++){
        int k = m - i;
        int coeff = comb(m, k);
        int tmp = qpow(k, n);
        tmp = 1LL * tmp * coeff % mod;
        if(i % 2 == 0){
            ans = (ans + tmp) % mod;
        }else{
            ans = (ans - tmp + mod) % mod;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pre_comb();
    int n;
    ll k;
    cin >> n >> k;
    if(k >= n){
        cout << 0 << endl;
    }else if(k == 0){
        cout << fac[n] << endl;
    }else{
        int m = n - k;
        int ans = 1LL * comb(n, m) * 2 % mod;
        int ans1 = cal(n, m);
        ans = 1LL * ans * ans1 % mod;
        cout << ans << endl;
    }
    return 0;
}