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

typedef pair<int, pair<int, int> > pii;

int n;
int m;
const int maxn = 5005;
pii q[maxn];
vector<pair<int, int> > G[maxn];
int dep[maxn];
int f[maxn];
int par[maxn];
int edge[maxn];
void dfs(int u, int fa, int d, int eid){
    dep[u] = d;
    par[u] = fa;
    edge[u] = eid;
    for(auto v : G[u]){
        if(v.first == fa)
            continue;
        dfs(v.first, u, d + 1, v.second);
    }
}

void lca(int u, int v, int g){
    if(dep[u] > dep[v]){
        swap(u, v);
    }
    //cout << u << " " << dep[u] << " " << v << " " << dep[v] << endl;
    while(dep[v] > dep[u]){
        //cout << v << " " << u << endl;
        f[edge[v]] = g;
        v = par[v];
    }
    while(v != u){
        f[edge[v]] = g;
        f[edge[u]] = g;
        v = par[v];
        u = par[u];
    }
}

int get(int u, int v){
    if(dep[u] > dep[v])
        swap(u, v);
    int ans = 1e9;
    while(dep[v] > dep[u]){
        ans = min(ans, f[edge[v]]);
        v = par[v];
    }
    while(v != u){
        ans = min(ans, f[edge[v]]);
        ans = min(ans, f[edge[u]]);
        v = par[v];
        u = par[u];
    }
    return ans;
}


int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d", &q[i].second.first, &q[i].second.second, &q[i].first);
    }
    sort(q + 1, q + 1 + m);
    memset(f, 0, sizeof(f));
    dfs(1, 1, 0, 0);
    for(int i = 1;i <= m;i++){
        //cout << q[i].second.first << " " << q[i].second.second << " " << q[i].first << endl;
        lca(q[i].second.first, q[i].second.second, q[i].first);
    }
    bool flag = true;
    for(int i = 1;i <= m;i++){
        if(get(q[i].second.first, q[i].second.second) != q[i].first)
            flag = false;
    }
    if(flag)
        for(int i = 1;i < n;i++){
            f[i] = max(1, f[i]);
            printf("%d%c", f[i], i == n ? '\n' : ' ');
        }
    else{
        cout << -1 << endl;
    }
    return 0;
}