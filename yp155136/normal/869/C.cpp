#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int MAX_N = 5006;
const LL mod = 998244353;

LL C[MAX_N][MAX_N];
LL f[MAX_N];

LL solve(int x,int y) {
    LL ret=0;
    for (int i=0;min(x,y)>=i;i++) {
        LL now=f[i];
        now *= C[x][i];
        now%=mod;
        now *= C[y][i];
        now%=mod;
        ret += now;
    }
    return ret%mod;
}

int main () {
    for (int i=0;MAX_N>i;i++) {
        C[i][0] = C[i][i] = 1;
        for (int j=1;i-1>=j;j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
    f[0] = f[1] = 1;
    for (int i=2;MAX_N>i;i++) {
        f[i] = f[i-1]*i;
        f[i]%=mod;
    }
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    LL ans=1;
    ans *= solve(a,b);
    ans %= mod;
    ans *= solve(b,c);
    ans %= mod;
    ans *= solve(a,c);
    ans %= mod;
    printf("%lld\n",ans);
}