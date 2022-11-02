#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

LL N, M;
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



struct mat{
    LL a[105][105];
    mat(){
        memset(a, 0, sizeof(a));
    }
    mat operator * (mat b){
        mat c;
        for(int i = 0;i < M;i++){
            for(int j = 0;j < M;j++){
                if(a[i][j] == 0)
                    continue;
                for(int k = 0;k < M;k++){
                    c.a[i][k] = (c.a[i][k] + 1LL * a[i][j] * b.a[j][k]) % mod;
                }
            }
        }
        return c;
    }
};

mat qpow(mat a, LL n){
    mat c;
    for(int i = 0;i < M;i++){
        c.a[i][i] = 1;
    }
    while(n > 0){
        if(n & 1){
            c = c * a;
        }
        a = a * a;
        n >>= 1;
    }
    return c;
} 

LL dp[105];

int main(){
    while(cin >> N >> M){
        if(N < 105){
            dp[1] = 1;
            dp[0] = 1;
            for(int i = 2;i <= N;i++){
                dp[i] = dp[i - 1];
                if(i - M >= 0){
                    dp[i] = (dp[i] + dp[i - M]) % mod;
                }
            }
            cout << dp[N] << endl;
        }else{
            dp[0] = 1;
            dp[1] = 1;
            for(int i = 2;i < M;i++){
                dp[i] = dp[i - 1];
                if(i - M >= 0){
                    dp[i] = (dp[i] + dp[i - M]) % mod;
                }
            }
            mat a;
            a.a[0][0] = 1;
            a.a[0][M - 1] = 1;
            for(int i = 1;i < M;i++){
                a.a[i][i - 1] = 1;
            }
            a = qpow(a, N - (M - 1));
            LL ans = 0;
            for(int i = 0;i < M;i++){
                ans = (ans + a.a[0][i]) % mod;
            }
            cout << ans << endl;
        }
    }
    return 0;
}