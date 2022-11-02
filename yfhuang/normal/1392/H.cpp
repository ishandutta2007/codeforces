#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int n, m;

const int mod = 998244353;

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1)
            ret = 1LL * ret * a % mod;
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

int inv(int a){
    return qpow(a, mod - 2);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m; 
    int ans = inv(m + 1);
    ans = (1LL * ans * n + 1) % mod;
    int ans1 = m + 1;
    for(int i = 2;i <= n;i++){
        int tmp = 1LL * m * inv(i) % mod;
        ans1 = (tmp + ans1) % mod;
    }
    cout << 1LL * ans * ans1 % mod << endl;
    return 0;
}