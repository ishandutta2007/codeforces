#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

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

char s[maxn];

int qc[maxn], lc[maxn], rc[maxn];
int c1[maxn], c2[maxn];

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    pre_comb();
    for(int i = 1;i <= n;i++){
        qc[i] = qc[i - 1] + (s[i] == '?');
        lc[i] = lc[i - 1] + (s[i] == '(');
        rc[i] = rc[i - 1] + (s[i] == ')');
    }
    int S = qc[n];
    for(int i = S;i >= 0;i--){
        c1[i] = comb(S, i);
        c1[i] = (c1[i] + c1[i + 1]) % mod;
    }
    for(int i = S - 1;i >= 0;i--){
        c2[i] = comb(S - 1, i);
        c2[i] = (c2[i + 1] + c2[i]) % mod;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == ')')
            continue;
        if(s[i] == '('){
            int a = lc[i];
            int b = rc[n] - rc[i];
            int c = qc[i];
            int d = qc[n] - qc[i];
            int lb = max(0, a - b + c);
            ans = (ans + c1[lb]) % mod;
        }else{
            int a = lc[i];
            int b = rc[n] - rc[i];
            int c = qc[i];
            int d = qc[n] - qc[i];
            c--;
            a++;
            int lb = max(0, a - b + c);
            ans = (ans + c2[lb]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}