//
//  main.cpp
//  1486
//
//  Created by  on 10/24/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

const int maxn = 1e5 + 5;
LL fac[maxn * 2];
LL inv[maxn * 2];

LL mod_pow(LL a,LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

void init(){
    fac[0] = 1;
    for(int i = 1;i < maxn * 2;i ++){
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[2 * maxn - 1] = mod_pow(fac[2 * maxn - 1],mod - 2);
    for(int i = 2 * maxn - 2;i >= 0;i--){
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

LL dp[2005];

LL C(int n,int m){
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

struct node{
    int r,c;
    bool operator < (const node & rhs) const{
        return r < rhs.r || (r == rhs.r && c < rhs.c);
    }
}x[2005];

int h,w,n;


int main(int argc, const char * argv[]) {
    init();
    cin >> h >> w >> n;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&x[i].r,&x[i].c);
        if(x[i].r == h && x[i].c == w) flag = false;
        if(x[i].r == 1 && x[i].c == 1) flag = false;
    }
    memset(dp,0,sizeof(dp));
    if(!flag){
        printf("0\n");
    }else{
        sort(x + 1,x + 1 + n);
        x[++n].r = h;
        x[n].c = w;
        for(int i = 1;i <= n;i++){
            dp[i] = C(x[i].c + x[i].r - 2,x[i].r - 1);
            for(int j = i - 1;j > 0;j--){
                if(x[j].r <= x[i].r && x[j].c <= x[i].c){
                    dp[i] = (dp[i] - dp[j] * C(x[i].r - x[j].r + x[i].c - x[j].c,x[i].r - x[j].r) % mod + mod) % mod;
                }
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}