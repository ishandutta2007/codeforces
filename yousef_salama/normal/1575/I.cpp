#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

long long tree[MAXN];
vector <int> g[MAXN];
int curtime, ltime[MAXN], rtime[MAXN], par[20][MAXN], depth[MAXN];

void dfs(int u, int parent = -1){
    par[0][u] = parent;
    for(int j = 1; j < 20; j++){
        if(par[j - 1][u] == -1)par[j][u] = -1;
        else par[j][u] = par[j - 1][par[j - 1][u]];
    }

    ltime[u] = curtime++;
    rtime[u] = ltime[u];

    for(int v : g[u]){
        if(v == parent)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);

        rtime[u] = rtime[v];
    }
}
int lca(int u, int v){
    if(depth[u] < depth[v])swap(u, v);

    int d = depth[u] - depth[v];
    for(int j = 0; j < 20; j++)if(d & (1 << j)){
        u = par[j][u];
    }

    if(u == v)return u;

    for(int j = 19; j >= 0; j--)if(par[j][u] != par[j][v]){
        u = par[j][u];
        v = par[j][v];
    }
    return par[0][u];
}

void add(int u, long long val){
    u++;
    while(u < MAXN){
        tree[u] += val;
        u += u & (-u);
    }
}
long long sum(int u){
    u++;
    long long ret = 0;
    while(u > 0){
        ret += tree[u];
        u -= u & (-u);
    }
    return ret;
}


int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    vector <int> a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] = abs(a[i]);
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    for(int i = 0; i < n; i++){
        add(ltime[i], a[i]);
        add(rtime[i] + 1, -a[i]);
    }

    auto calc = [&](int u, int v){
        long long cur = sum(ltime[u]) + sum(ltime[v]);
        int l = lca(u, v);
        cur -= sum(ltime[l]);
        if(par[0][l] != -1)cur -= sum(ltime[par[0][l]]);
        
        return cur;
    };


    while(q--){
        int type;
        scanf("%d", &type);

        if(type == 1){
            int u, c;
            scanf("%d %d", &u, &c);
            u--;
            c = abs(c);

            add(ltime[u], c - a[u]);
            add(rtime[u] + 1, a[u] - c);
            a[u] = c;
        }else{
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            
            if(u == v){
                printf("0\n");
                continue;
            }

            long long cur = 2LL * calc(u, v);
            cur -= sum(ltime[u]);
            if(par[0][u] != -1)cur += sum(ltime[par[0][u]]);

            cur -= sum(ltime[v]);
            if(par[0][v] != -1)cur += sum(ltime[par[0][v]]);

            printf("%lld\n", cur);
        }
    }

    return 0;
}