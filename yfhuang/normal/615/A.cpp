//
//  main.cpp
//  A
//
//  Created by  on 16/1/8.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=105;

bool vis[maxn];

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int y;
            scanf("%d",&y);
            vis[y]=true;
        }
    }bool flag=true;
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            flag=false;
            break;
        }
    }
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}