//
//  main.cpp
//  C
//
//  Created by  on 16/3/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;

const int maxn = 1e5 + 5;

long long a[maxn],t[maxn];

bool vis[500000];

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=1&&a[i]<500000) vis[a[i]] = true;
    }
    int cnt=0;
    for(int i=1;i<500000;i++){
        if(!vis[i]&&i<=m){
            t[cnt++]=i;
            m-=i;
        }
    }
    cout<<cnt<<endl;
    for(int i =0;i<cnt;i++){
        printf("%d%c",(int)t[i],i==cnt-1?'\n':' ');
    }
    return 0;
}