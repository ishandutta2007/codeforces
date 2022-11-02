#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int b[maxn];
int inv;

int qpow(int a, int n){
    int ans = 1;
    while(n > 0){
        if(n & 1)
            ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ans;
}

int cal(int len){
    int val1 = qpow(k, len);
    int val2 = qpow(k, 2 * len);
    int val3 = (val2 - val1 + mod) % mod;
    val3 = 1LL * val3 * inv % mod;
    return (val3 + val1) % mod;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    inv = qpow(2, mod - 2);
    cin >> n >> m >> k;
    b[0] = 0;
    int ans = 1;
    for(int i = 1;i <= m;i++){
        cin >> b[i];
        ans = 1LL * ans * cal(b[i] - b[i - 1]) % mod;
    }
    ans = 1LL * ans * qpow(k, n - 2 * b[m]) % mod;
    cout << ans << endl;
    return 0;
}