#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
LL n, k;
LL inv[maxn];
const LL mod = 1e9 + 7;
LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1){
            ret = ret * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

void init(){
    inv[1] = 1;
    for(int i = 2;i < maxn;i++){
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}

LL dp[60][10005];

LL cal(LL p, LL cnt, LL k){
    memset(dp, 0, sizeof(dp));
    LL now = 1;
    for(int i = 0;i <= cnt;i++){
        dp[i][0] = now % mod;
        now *= p;
    } 
    for(int j = 1;j <= k;j++){
        dp[0][j] = 1;
        for(int i = 1;i <= cnt;i++){
            for(int l = 0;l <= i;l++){
                dp[i][j] = (dp[i][j] + dp[l][j - 1]) % mod;
            }
            dp[i][j] = dp[i][j] * inv[i + 1] % mod;
        }
    }
    return dp[cnt][k];
}

int main(){
    init();
    while(cin >> n >> k){
        LL ans = 1;
        LL i = 2;
        while(i * i <= n){
            if(n % i == 0){
                int cnt = 0;
                while(n % i == 0){
                    cnt++;
                    n /= i;
                }
                ans = ans * cal(i, cnt, k) % mod;
            }
            i++;
        }
        if(n > 0){
            ans = ans * cal(n, 1, k) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}