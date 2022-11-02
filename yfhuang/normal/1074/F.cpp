#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, q;
const int maxn = 2e5 + 5;
const int maxk = 20;
int L[maxn], R[maxn], tot;

int fa[maxn][maxk], dep[maxn];
vector<int> G[maxn];

void dfs(int u, int par, int d){
    fa[u][0] = par;
    dep[u] = d;
    L[u] = ++tot;
    for(auto v : G[u]){
        if(v == par)
            continue;
        dfs(v, u, d + 1);
    }
    R[u] = tot;
}

int getfather(int u, int len){
    for(int i = 0;i < maxk;i++){
        if(len & (1 << i)){
            u = fa[u][i]; 
        }
    }
    return u;
}

void init_lca(){
    for(int i = 1;i < 20;i++){
        for(int j = 1;j <= n;j++){
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
}

int lca(int u, int v){
    if(dep[u] > dep[v]){
        swap(u, v);
    }
    if(dep[u] != dep[v]){
        v = getfather(v, dep[v] - dep[u]);
    }
    if(u == v){
        return u;
    }
    for(int i = 19;i >= 0;i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}


int maxv[maxn << 2];
int cntv[maxn << 2];
int addv[maxn << 2];
#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

void pushup(int o){
    maxv[o] = max(maxv[o*2],maxv[o*2+1]);
    cntv[o] = (maxv[o*2] == maxv[o] ? cntv[o*2] : 0) + (maxv[o*2+1] == maxv[o] ? cntv[o*2+1] : 0);
}

void pushdown(int o){
    if(addv[o]){
        addv[o*2] += addv[o];
        addv[o*2+1] += addv[o];
        maxv[o*2] += addv[o];
        maxv[o*2+1] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    addv[o] = 0;
    if(l == r){
        maxv[o] = 0;
        cntv[o] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}

void update(int o, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        maxv[o] += v;
        addv[o] += v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

pair<int, int> querymax(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return make_pair(maxv[o], cntv[o]);
    }
    int mid = (l + r) / 2;
    pushdown(o);
    if(qr <= mid)
        return querymax(lson, ql, qr);
    if(ql > mid)
        return querymax(rson, ql, qr);
    pair<int, int> p1 = querymax(lson, ql, qr);
    pair<int, int> p2 = querymax(rson, ql, qr);
    int mx = max(p1.first, p2.first);
    int cnt = (p1.first == mx ? p1.second : 0) + (p2.first == mx ? p2.second : 0);
    return make_pair(mx, cnt);
}

void modify(int u, int v, int val){
    if(dep[u] > dep[v])
        swap(u, v);
    int father = lca(u, v);
    if(u == father){
        int x = getfather(v, dep[v] - dep[u] - 1);
        update(1, 1, n, L[v], R[v], val);
        if(L[x] > 1)
            update(1, 1, n, 1, L[x] - 1, val);
        if(R[x] < n)
            update(1, 1, n, R[x] + 1, n, val);
    }else{
        update(1, 1, n, L[u], R[u], val);
        update(1, 1, n, L[v], R[v], val);
    }
}

void addedge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}


set<pair<int, int> > edges;

int main(){
    cin >> n >> q;
    tot = 0;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    dfs(1, 1, 0);
    init_lca();
    build(1, 1, n);
    for(int i = 1;i <= q;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(u > v)
            swap(u, v);
        if(edges.count(make_pair(u, v)) == 0){
            edges.insert(make_pair(u, v));
            modify(u, v, 1);
        }else{
            edges.erase(make_pair(u, v));
            modify(u, v, -1);
        }
        pair<int, int> ret = querymax(1, 1, n, 1, n);
        if(ret.first == edges.size())
            printf("%d\n", ret.second);
        else{
            printf("0\n");
        }
    }
    return 0;
}