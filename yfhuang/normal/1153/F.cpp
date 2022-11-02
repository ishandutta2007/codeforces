#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

LL n, k, l;

const LL mod = 998244353;

LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

const int maxn = 4005;

LL f[maxn][maxn][2];

int main(){
    while(cin >> n >> k >> l){
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        for(int i = 1;i <= 2 * n + 1;i++){
            for(int j = 0;j <= n;j++){
                for(int x = 0;x < 2;x++){
                    if(f[i - 1][j][x]){
                        if(j){
                            f[i][j - 1][x] = (f[i][j - 1][x] + f[i - 1][j][x] * j) % mod;
                        }
                        if(j >= k && !x){
                            f[i][j][1] = (f[i][j][1] + f[i - 1][j][x]) % mod;
                        }
                        if(i + j - 1 < 2 * n + x){
                            f[i][j + 1][x] = (f[i][j + 1][x] + f[i - 1][j][x]) % mod;
                        }
                    }
                }
            }
        }
        LL fac = 1;
        for(int i = n + 1;i <= 2 * n + 1;i++){
            fac = fac * i % mod;
        }
        LL ans = f[2 * n + 1][0][1];
        ans = ans * qpow(fac, mod - 2) % mod;
        ans = ans * qpow(2, n) % mod;
        ans = ans * l % mod;
        cout << ans << endl;
    } 
    return 0;
}