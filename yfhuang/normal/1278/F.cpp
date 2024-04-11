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

using namespace std;

typedef long long LL;
const LL mod = 998244353;
LL n, m, k;
const int maxn = 5005;
LL dp[maxn][maxn];

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

int main(){
    cin >> n >> m >> k;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    LL div = qpow(m, n);
    for(int i = 0;i < k;i++){
        for(int j = 0;j <= min(n, k);j++){
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (n - j) )% mod;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j) % mod;
            //if(i == 0 and j == 0){
            //    cout << dp[i][j] << " " << dp[i][j] * (n - j) << " " << dp[i + 1][j + 1] << endl;
            //    cout << i + 1 << " " << j + 1 << endl;
            //}
        }
    }
    //for(int i = 0;i < 10;i++){
    //    cout << dp[i][0] << " " << dp[i][1] << endl;
    //}
    //cout << dp[1][1] << " " << dp[2][1] << endl;
    LL ans = 0;
    for(int i = 0;i <= min(n, k);i++){
        ans = (ans + dp[k][i] * qpow(m, n - i)) % mod;
        //cout << i << " " << dp[k][i] << endl; 
    }
    ans = ans * qpow(div, mod - 2) % mod;
    //LL comp = qpow(2, mod - 2) + 1;
    //cout << ans << " " << comp << endl;
    cout << ans << endl;
    return 0;
}