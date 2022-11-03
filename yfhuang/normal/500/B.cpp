//
//  main.cpp
//  B
//
//  Created by  on 15/12/29.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=300+5;

char a[maxn][maxn];
int p[maxn];
bool vis[maxn];
int w[maxn];
int n;
int x,y;

void dfs(int i){
    if(!vis[p[i]]){
        x=min(x,p[i]);
    }
    w[i]=y;
    for(int j=1;j<=n;j++){
        if(a[i][j]=='1'&&w[j]!=y)
            dfs(j);
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++){
        y++;
        x=n+1;
        dfs(i);
        vis[x]=true;
        cout<<x<<" ";
    }
    return 0;
}