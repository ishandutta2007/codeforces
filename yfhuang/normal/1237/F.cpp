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
    return 1LL * fac[n] * inv[n - m] % mod;
}

int a[2][maxn], dp[2][4005][4005];
int h, w, n;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int cnt[2][4005];

void Dp(int id, int len){
    memset(dp[id], 0, sizeof(dp[id]));
    dp[id][0][0] = 1;
    //for(int i = 1;i <= len;i++){
    //    cout << i << " a : " << a[i] << endl;
    //}
    for(int i = 1;i <= len;i++){
        for(int j = 0;j <= len;j++){
            dp[id][i][j] = dp[id][i - 1][j];
            if(i > 1 and a[id][i] == 0 and a[id][i - 1] == 0 and j > 0){
                add(dp[id][i][j], dp[id][i - 2][j - 1]);         
            } 
        }
    }
    for(int j = 0;j <= len;j++){
        cnt[id][j] = dp[id][len][j];
        //cout << j << " " << cnt[id][j] << endl;
    }
}

int main(){
    cin >> h >> w >> n;
    pre_comb();
    memset(a, 0, sizeof(a));
    int freeh = 0, freew = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 2;j++){
            int r, c;
            scanf("%d%d", &r, &c);
            a[0][r] = 1;
            a[1][c] = 1;
        }
    }
    Dp(0, h);
    Dp(1, w);
    for(int i = 1;i <= h;i++){
        if(a[0][i] == 0)
            freeh++;
        //cout << i << " " << cnt[0][i] << endl;
    }
    for(int i = 1;i <= w;i++){
        if(a[1][i] == 0)
            freew++;
    }
    //cout << freeh << " " << freew << endl;
    int ans = 0;
    for(int k = 0;k <= h;k++){
        for(int j = 0;j <= w;j++){
            if(k * 2 + j > freeh or j * 2 + k > freew){
                continue;
            }
            //cout << k << " " << j << endl;
            int num = 1LL * cnt[0][k] * comb(freeh - 2 * k, j) % mod * cnt[1][j] % mod * comb(freew - 2 * j, k) % mod;
            //cout << cnt[0][k] << " " << comb(freeh - 2 * k, j) << " " << cnt[1][j] << " " << comb(freew - 2 * j, k) << " " << num << endl;
            add(ans, num);
        }
    } 
    cout << ans << endl;
    return 0;
}