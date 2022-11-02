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

const int maxn = 205;
typedef long long LL;
LL dp[maxn][maxn * 2];

int n;
int l[maxn], r[maxn];

const int mod = 998244353; 

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
 
int inv(int val){
    return qpow(val, mod - 2);
}

int comb(int x, int a){
    if(x < a)
        return 0;
    int ans = 1;
    for(int i = x - a + 1;i <= x;i++){
        ans = 1LL * ans * i % mod;
    }
    for(int i = 1;i <= a;i++){
        ans = 1LL * ans * inv(i) % mod;
    }
    return ans;
}

int m, x[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d", &l[i], &r[i]);
        r[i]++;
        x[++m] = l[i];
        x[++m] = r[i];
    }
    sort(x + 1, x + 1 + m);
    m = unique(x + 1, x + 1 + m) - x - 1;
    for(int i = 1;i <= n;i++){
        l[i] = lower_bound(x + 1, x + 1 + m, l[i]) - x;
        r[i] = lower_bound(x + 1, x + 1 + m, r[i]) - x;
    }
    for(int i = 0;i <= m;i++){
        dp[0][i] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = l[i];j < r[i];j++){
            for(int k = i;k > 0;k--){
                if(j < l[k])
                    break;
                if(j >= r[k])
                    break;
                int range = x[j + 1] - x[j];
                int num = i - k + 1;
                int tmp = comb(range + num - 1, num);
                dp[i][j] = (dp[i][j] + dp[k - 1][j + 1] * tmp) % mod;
            }
        }
        for(int j = m;j >= 1;j--){
            dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
        }
    }
    LL ans = dp[n][1];
    //cout << ans << endl;
    for(int i = 1;i <= n;i++){
        ans = ans * inv(x[r[i]] - x[l[i]]) % mod;
    }
    cout << ans << endl;
    return 0;
}