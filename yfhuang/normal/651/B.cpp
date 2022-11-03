//
//  main.cpp
//  B
//
//  Created by  on 16/3/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=1005;
int a[maxn];
int cnt[maxn];
bool vis[maxn];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    //printf("%d %d ",cnt[10],cnt[20]);
    int ans=0;
    while(n){
        int num=0;
        for(int j=1;j<=1000;j++){
            if(cnt[j]>0){
                num++;
                cnt[j]--;
            }
        }
        ans+=(num-1);
        n-=num;
    }
    printf("%d\n",ans);
    return 0;
}