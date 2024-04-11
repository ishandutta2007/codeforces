//
//  main.cpp
//  B
//
//  Created by  on 16/1/1.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=405;

int a[maxn*2];
bool vis[maxn*2];

struct team{
    int s,u,v;
}t[maxn*maxn*2];

bool cmp(team a,team b){
    return a.s>b.s;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=i-1;j++){
            scanf("%d",&t[(i-1)*(i-2)/2+j].s);
            t[(i-1)*(i-2)/2+j].u=i;
            t[(i-1)*(i-2)/2+j].v=j;
        }
    }
    sort(t+1,t+1+n*(2*n-1),cmp);
    for(int i=1;i<=n*(2*n-1);i++){
        if(!vis[t[i].u]&&!vis[t[i].v]){
            vis[t[i].u]=true;
            vis[t[i].v]=true;
            a[t[i].u]=t[i].v;
            a[t[i].v]=t[i].u;
        }
    }
    for(int i=1;i<=2*n;i++)
        printf("%d ",a[i]);
    return 0;
}