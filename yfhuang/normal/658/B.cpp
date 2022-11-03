//
//  main.cpp
//  B
//
//  Created by  on 16/3/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k;
const int maxn = 150000 + 5;
const int INF = 1e9 + 7;

struct a{
    int x;
    int id;
    int y;
}t[maxn];

bool cmp1(a x, a y){
    return x.x > y.x;
}
bool cmp2(a x, a y){
    return x.id < y.id;
}
int c[maxn];
bool vis[maxn];

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= x&-x;
    }
    return ret;
}

void add(int x){
    while(x < maxn){
        c[x]++;
        x += x&-x;
    }
}

int main(int argc, const char * argv[]) {
    int q;
    scanf("%d%d%d",&n,&k,&q);
    memset(vis,false,sizeof(vis));
    for(int i = 1; i <= n; i++){
        scanf("%d",&t[i].x);
        t[i].id = i;
    }
    sort(t + 1,t + 1 +n,cmp1);
    for(int i = 1; i <= n; i++){
        t[i].y = i;
    }
    sort(t + 1,t + 1 + n, cmp2);
    for(int i = 1; i <= q; i++){
        int type, u;
        scanf("%d%d",&type,&u);
        if(type == 1){
            add(t[u].y);
            vis[u] = true;
        }else{
           if(!vis[u]) puts("NO");
           else{
                if(sum(t[u].y) > k)puts("NO");
                else puts("YES");
            }
        }
    }
    return 0;
}