//
//  main.cpp
//  B
//
//  Created by  on 2017/3/5.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>


using namespace std;

const int maxn = 2e5 + 5;

int n,m,k;
int f[maxn];
int x,y;
vector<int> G[maxn];

int Find(int x){
    return x == f[x] ? x : f[x] = Find(f[x]);
}

int tid[maxn * 2];
int num;

void dfs(int u,int fa){
    tid[++num] = u;
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v,u);
        tid[++num] = u;
    }
    //tid[++num] = u;
}


int main(int argc, const char * argv[]) {
    while(cin >> n >> m >> k){
        for(int i = 1;i <= n;i++) f[i] = i;
        for(int i = 1;i <= m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int fx = Find(x);
            int fy = Find(y);
            if(fx == fy) continue;
            f[fx] = fy;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        num = 0;
        dfs(1,0);
        int len = (2 * n + k - 1) / k;
        int now = 0;
        int p = 1;
        int remain = num - k;
        for(int i = 1;i <= k;i++){
            int s = 0;
            printf("%d",min(remain - now + 1,len));
            int step = min(remain - now + 1,len);
            for(int j = p;j < p + step;j++){
                printf(" %d",tid[j]);
            }
            p += step;
            now += step - 1;
            puts("");
        }
    }
    return 0;
}