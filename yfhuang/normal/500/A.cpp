//
//  main.cpp
//  A
//
//  Created by  on 15/12/29.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,t;
const int maxn=3e4+10;

int a[maxn];
bool vis[maxn];

int main(int argc, const char * argv[]) {
    cin>>n>>t;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n-1;i++)
        scanf("%d",&a[i]);
    vis[1]=true;
    for(int i=1;i<=n-1;i++){
        if(vis[i]) vis[i+a[i]]=true;
    }
    if(vis[t]) printf("YES\n");
    else printf("NO\n");
    return 0;
}