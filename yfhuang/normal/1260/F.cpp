#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int sumv[maxn << 2];
int addv[maxn << 2]; 

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

const int mod = 1e9 + 7;

void pushup(int o){
    sumv[o] = (sumv[o*2] + sumv[o*2+1]) % mod;
}

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void sub(int &a, int b){
    a -= b;
    if(a < 0)
        a += mod;
}

void pushdown(int o, int l, int r){
    if(addv[o]){
        int mid = (l + r) / 2;
        add(addv[o*2], addv[o]);
        add(addv[o*2+1], addv[o]);
        add(sumv[o*2], 1LL * (mid - l + 1) * addv[o] % mod);
        add(sumv[o*2+1], 1LL * (r - mid) * addv[o] % mod);
        addv[o] = 0;
    }
}

void build(int o, int l, int r){
    sumv[o] = 0;
    addv[o] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
}

void update(int o, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        add(addv[o], v);
        add(sumv[o], 1LL * (r - l + 1) * v % mod);
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o, l, r);
    if(ql <= mid)
        update(lson, ql, qr, v);
    if(qr > mid)
        update(rson, ql, qr, v);
    pushup(o);
}

int query(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sumv[o];
    }
    int mid = (l + r) / 2;
    int ans = 0;
    pushdown(o, l, r);
    if(ql <= mid)
        add(ans, query(lson, ql, qr));
    if(qr > mid)
        add(ans, query(rson, ql, qr));
    return ans;
}

int dep[maxn], sz[maxn], f[maxn], son[maxn];
int top[maxn], id[maxn], Rank[maxn];
int tot;
vector<int> G[maxn];

void dfs1(int fa, int u, int d){
    dep[u] = d; sz[u] = 1; f[u] = fa; son[u] = -1;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs1(u, v, d + 1);
        if(son[u] == -1 or sz[v] > sz[son[u]])
            son[u] = v;
        sz[u] += sz[v];
    }
}

void dfs2(int u, int tp){
    top[u] = tp;
    id[u] = ++tot;
    Rank[id[u]] = u;
    if(son[u] == -1)
        return;
    dfs2(son[u], tp);
    for(auto v : G[u]){
        if(v == f[u] or v == son[u]) continue;
        dfs2(v, v);
    }
}

int qpow(int a, int n){
    int res = 1;
    while(n > 0){
        if(n & 1){
            res = (1LL * res * a) % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return res;
}

void modify(int u, int v){
    while(u){
        update(1, 1, n, id[top[u]], id[u], v);
        u = f[top[u]];
    }
}

int cal(int u){
    int ans = 0;
    sub(ans, query(1, 1, n, 1, 1));
    while(u){
        add(ans, query(1, 1, n, id[top[u]], id[u]));
        u = f[top[u]];
    }
    return ans;
}

vector<int> in[maxn], out[maxn];
int g[maxn];
int main(){
    tot = 0;
    cin >> n;
    int color = 0;
    int P = 1;
    for(int i = 1;i <= n;i++){
        int l, r;
        scanf("%d%d", &l, &r);
        in[l].push_back(i);
        out[r + 1].push_back(i);color = max(color, r);
        g[i] = qpow(r - l + 1, mod - 2);
        P = 1LL * P * (r - l + 1) % mod;
    }
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(0, 1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    int ans = 0;
    int cur = 0;
    int d1 = 0, d2 = 0, d3 = 0;
    for(int i = 1;i <= color;i++){
        for(auto u : out[i]){
            sub(d1, 1LL * dep[u] * g[u] % mod);
            sub(d2, g[u]);
            sub(d3, 1LL * dep[u] * g[u] % mod * g[u] % mod);
            modify(u, mod - g[u]);
            sub(cur, 1LL * g[u] * cal(u) % mod);
        }
        for(auto u : in[i]){
            add(d1, 1LL * dep[u] * g[u] % mod);
            add(d2, g[u]);
            add(d3, 1LL * dep[u] * g[u] % mod * g[u] % mod);
            add(cur, 1LL * g[u] * cal(u) % mod);
            modify(u, g[u]);
        }
        ans = (ans + 1LL * d1 * d2 % mod - 2LL * cur - d3) % mod;
        ans = (ans + mod) % mod;
    }
    ans = 1LL * ans * P % mod; 
    cout << ans << endl;
    return 0;
}