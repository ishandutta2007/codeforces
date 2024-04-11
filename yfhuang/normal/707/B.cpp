//
//  main.cpp
//  B
//
//  Created by  on 8/20/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int n,m;
int k;

int u[maxn],v[maxn],l[maxn];
bool vis[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    cin >> k;
    memset(vis,false,sizeof(vis));
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",u + i,v + i,l + i);
    }
    for(int i = 1;i <= k;i++){
        int u;
        scanf("%d",&u);
        vis[u] = true;
    }
    if(k == 0 || k == n){
        printf("-1\n");
        return 0;
    }else{
        int ans = 1e9 + 7;
        for(int i = 1;i <= m;i++){
            if(vis[u[i]] ^ vis[v[i]]) ans = min(ans,l[i]);
        }
        if(ans == 1e9 + 7) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}