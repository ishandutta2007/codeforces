//
//  main.cpp
//  383C
//
//  Created by  on 9/7/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 200000 + 5;

#define lson o * 2,l,m
#define rson o * 2 + 1,m + 1,r

int id[maxn * 2];
int a[maxn];

int dfs[maxn * 2];
int pre[maxn],suf[maxn];
int dfs_clock;
int depth[maxn];

vector<int> G[maxn];

void Dfs(int u,int fa,int dep){
    pre[u] = ++dfs_clock;
    id[dfs_clock] = u;
    depth[u] = dep;
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(v == fa) continue;
        Dfs(v,u,dep + 1);
    }
    suf[u] = ++dfs_clock;
    id[dfs_clock] = u;
}

void init(int n){
    dfs_clock = 0;
    for(int i = 1;i <= n;i++) G[i].clear();
}

struct segmentTree{
    int maxv[maxn << 3],addv[maxn << 3];
    
    void pushup(int o){
        maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
    }
    
    void pushdown(int o){
        if(addv[o] != 0){
            addv[o * 2] += addv[o];
            addv[o * 2 + 1] += addv[o];
            maxv[o * 2] += addv[o];
            maxv[o * 2 + 1] += addv[o];
            addv[o] = 0;
        }
    }
    
    void build(int o,int l,int r){
        addv[o] = 0;
        if(l == r){
            maxv[o] = a[id[l]];
            return;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(o);
    }
    
    int query(int o,int l,int r,int p){
        if(l == r){
            return maxv[o];
        }
        pushdown(o);
        int m = (l + r) >> 1;
        int ans = 0;
        if(p <= m) ans = query(lson,p);
        else ans = query(rson,p);
        pushup(o);
        return ans;
    }
    
    void update(int o,int l,int r,int ql,int qr,int val){
        if(ql > qr) return;
        if(ql <= l && r <= qr){
            addv[o] += val;
            maxv[o] += val;
            return;
        }
        pushdown(o);
        int m = (l + r) >> 1;
        if(ql <= m) update(lson,ql,qr,val);
        if(qr > m) update(rson, ql,qr,val);
        pushup(o);
    }
}tree,tree2;

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) scanf("%d",a + i);
    init(n);
    for(int i = 1;i < n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Dfs(1,-1,0);
    tree.build(1,1,2 * n);
    tree2.build(1,1,2 * n);
    for(int i = 1;i <= m;i++){
        int type;
        scanf("%d",&type);
        if(type == 1){
            int x,val;
            scanf("%d%d",&x,&val);
            if(depth[x] & 1){
                tree.update(1, 1, 2 * n, pre[x], suf[x], val);
                tree2.update(1, 1, 2 * n, pre[x], suf[x],-val);
            }else{
                tree2.update(1, 1, 2 * n, pre[x], suf[x], val);
                tree.update(1, 1, 2 * n, pre[x], suf[x], -val);
            }
//            for(int j = 1;j <= n;j++){
//                if(depth[j] & 1){
//                    printf("%d\n",tree.query(1, 1, 2 * n, pre[j]));
//                }
//                else printf("%d\n",tree2.query(1, 1, 2 * n, pre[j]));
//            }
        }else{
            int x;
            scanf("%d",&x);
            if( depth[x] & 1)
                printf("%d\n",tree.query(1, 1, 2 * n, pre[x]));
            else printf("%d\n",tree2.query(1, 1, 2 * n, pre[x]));
        }
    }
    return 0;
}