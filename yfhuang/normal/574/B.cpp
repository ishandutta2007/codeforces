//
//  main.cpp
//  B
//
//  Created by  on 16/1/7.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF=0x3f3f3f3f;

struct edge{
    int u,v;
};

vector<edge> E;

int a[4005][4005];
int b[4005];

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    E.resize(m+1);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&E[i].u,&E[i].v);
        a[E[i].u][E[i].v]=1;
        a[E[i].v][E[i].u]=1;
        b[E[i].u]++;
        b[E[i].v]++;
    }
    int minx=INF;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j!=E[i].u&&j!=E[i].v){
                if(a[j][E[i].u]&&a[j][E[i].v]){
                    minx=min(minx,b[E[i].u]+b[E[i].v]+b[j]-6);
                }
            }
        }
    }
    if(minx==INF) printf("-1\n");
    else printf("%d\n",minx);
    return 0;
}