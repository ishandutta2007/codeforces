//
//  main.cpp
//  E
//
//  Created by  on 8/6/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

#define mp make_pair
#define ft first
#define sd second
typedef long long LL;
typedef pair<int,LL> PIL;

int n,divc;
LL k,a[1005],b[1005];
LL f[7000];
PIL dp[1005][7000];
map<LL,int> p;

int main(int argc, const char * argv[]) {
    scanf("%d%I64d",&n,&k);
    LL tmp = k;
    for(int i = 1;i <= n;i++){
        scanf("%I64d",a + i);
        b[i] = __gcd(a[i],k);
        tmp = tmp / __gcd(b[i],tmp);
    }
    if(tmp != 1){
        printf("-1\n");
        return 0;
    }
    if(k == 1){
        printf("1\n");
        printf("%d\n",(int)(min_element(a + 1,a + n + 1) - a));
        return 0;
    }
    divc = 0;
    p.clear();
    for(LL i = 1;i * i <= k;i++){
        if(k % i == 0){
            f[divc++] = i;
            if(i * i != k){
                f[divc++] = k / i;
            }
        }
    }
    sort(f,f + divc);
    for(int i = 0;i < divc;i++) p[f[i]] = i;
    for(int i = 0;i < divc;i++) dp[0][i] = mp(n + 1,0);
    dp[0][0] = mp(0,0);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < divc;j++){
            LL v = f[j] / __gcd(f[j],b[i]);
            int la = p[v];
            dp[i][j] = dp[i - 1][j];
            if(dp[i][j] > mp(dp[i - 1][la].ft + 1,dp[i - 1][la].sd + a[i]))
                dp[i][j] = mp(dp[i - 1][la].ft + 1,dp[i - 1][la].sd + a[i]);
        }
    }
    printf("%d\n",dp[n][divc - 1].ft);
    for(int i = n,j = divc - 1;i > 0;i--){
        if(dp[i][j] == dp[i - 1][j]) continue;
        LL v = f[j] / __gcd(f[j],b[i]);
        j = p[v];
        printf("%d ",i);
    }
    puts("");
    return 0;
}