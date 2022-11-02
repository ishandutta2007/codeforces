#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mod = 998244353LL;
const int maxn = 5005;
LL dp[maxn][maxn];
LL pre[maxn][maxn];
int n;
LL a[maxn];
LL cnt[maxn];

LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

LL fac[maxn];

int main(){
    while(cin >> n){
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            cnt[a[i]]++;
        }
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        dp[0][0] = 1;
        for(int j = 0;j <= n;j++){
            pre[0][j] = 1;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dp[i][j] = pre[i - 1][j - 1] * cnt[j] % mod;
                pre[i][j] = (pre[i][j - 1] + dp[i][j]) % mod;
                //printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
            }
        }
        fac[0] = 1;
        for(int i = 1;i <= n;i++){
            fac[i] = (fac[i - 1] * i) % mod;
        }
        LL inv = qpow(fac[n], mod - 2);
        LL ans = 0;
        for(int i = 1;i < n;i++){
            for(int j = 1;j <= n;j++){
                LL tmp = dp[i][j] * (cnt[j] - 1) % mod * fac[n - i - 1] % mod;
                ans = (ans + tmp) % mod;
            }
        }
        ans = ans * inv % mod;
        cout << ans << endl;
    } 
    return 0;
}