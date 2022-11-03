//
//  main.cpp
//  C
//
//  Created by  on 15/12/24.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct beacon{
    int a,b,c;
}p[100000+5];

int dp[1000000+5];

bool cmp(beacon a,beacon b){
    return a.a<b.a;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].a,&p[i].b);
    }
    sort(p+1,p+1+n,cmp);
    map <int,int> pos;
    for(int i=1;i<=n;i++){
        pos[p[i].a]=i;
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=1000000+5;i++){
        if(pos.count(i)!=0){
            if(i-p[pos[i]].b-1<0) dp[i]=1;
            else dp[i]=dp[i-p[pos[i]].b-1]+1;
        }
        else dp[i]=dp[i-1];
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ans=min(ans,(i-dp[p[i].a])+n-i);
    }
    printf("%d\n",ans);
    return 0;
}