#include <bits/stdc++.h>
#define N 20
#define max(_1_, _2_) ((_1_) < (_2_) ? (_2_) : (_1_))
using namespace std;

typedef long long ll;

int i, j, p, k;

ll l, r, ans;
ll f[N][0x10022][N];

ll solve(ll x){
    if(x < 20) return 0;
    int g = 63 - __builtin_clzll(x) >> 2 << 2;
    int i, j, d, Md = 0;
    ll mask, val, res = 0;
    for(i = g; i >= 0; i -= 4){
        d = x >> i & 15;
        mask = x >> i & 0xfff0;
        for(j = 0; j < d; ++j)
            res += f[i >> 2][mask | j][max(Md, j)];
        Md < d ? Md = d : 0;
    }
    res += f[0][x & 0xffff][Md];
    return res;
}

int main(){
    int T;
    for(j = 0; j < 0x10000; ++j)
        for(p = 0; p < 16; ++p)
            f[0][j][p] = j >> p & 1;
    for(i = 1; i <= 16; ++i)
        for(j = 0; j < 0x10000; ++j)
            for(p = 0; p < 16; ++p)
                for(k = 0; k < 16; ++k)
                    f[i][j][p] += f[i - 1][(j << 4 | k) & 0xffff][max(p, k)];

    for(scanf("%d", &T); T; --T){
        scanf("%llx%llx", &l, &r);
        ans = solve(r) - solve(l - 1);
        printf("%lld\n", ans);
    }
    return 0;
}