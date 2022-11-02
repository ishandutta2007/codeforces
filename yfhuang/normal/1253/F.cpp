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

int n, m, k, q;

const int maxn = 3e5 + 5;

typedef long long LL;
typedef pair<LL, int> pii;
int u[maxn], v[maxn], w[maxn];
LL d[maxn];
bool vis[maxn];

int fa[maxn];
int pre[maxn];
vector<pair<int, LL> > G[maxn];

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 1;i <= k;i++){
        d[i] = 0;
        pre[i] = i;
        pq.push(make_pair(d[i], i));
        vis[i] = false;
    } 
    for(int i = k + 1;i <= n;i++){
        d[i] = 1e18;
        vis[i] = false;
    }
    while(!pq.empty()){
        pii p = pq.top();pq.pop();
        LL dis = p.first;
        int id = p.second;
        if(vis[id])
            continue;
        vis[id] = true;
        for(auto neigh : G[id]){
            int v = neigh.first;
            int len = neigh.second;
            if(dis + len < d[v]){
                d[v] = dis + len;
                pre[v] = pre[id];
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

void build_tree(){
    for(int i = 1;i <= k;i++){
        fa[i] = i;
        G[i].clear();
    }
    vector<pair<LL, pair<int, int> > > edges;
    for(int i = 1;i <= m;i++){
        LL cost = d[u[i]] + d[v[i]] + w[i];
        //cout << u[i] << " " << d[u[i]] << " " << v[i] << " " << d[v[i]] << " " << w[i] << endl;
        edges.push_back(make_pair(cost, make_pair(pre[u[i]], pre[v[i]])));
    }
    sort(edges.begin(), edges.end());
    for(auto edge: edges){
        LL cost = edge.first;
        int from = edge.second.first;
        int to = edge.second.second; 
        int fx = Find(from);
        int fy = Find(to);
        if(fx != fy){
            //cout << from << " " << to << " " << cost << endl;
            G[from].push_back(make_pair(to, cost));
            G[to].push_back(make_pair(from, cost));
            fa[fx] = fy;
        }
    }
}

int dep[maxn];
int par[maxn][20];
LL mx[maxn][20];

void dfs(int u, int f, int depth, LL weight){
    par[u][0] = f;
    mx[u][0] = weight;
    dep[u] = depth;
    for(auto v : G[u]){
        int to = v.first;
        if(to == f)
            continue;
        dfs(to, u, depth + 1, v.second); 
    } 
}

void init_lca(){
    for(int i = 1;i <= 19;i++){
        for(int j = 1;j <= k;j++){
            par[j][i] = par[par[j][i - 1]][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[par[j][i - 1]][i - 1]);
        }
    }
}

LL query(int u, int v){
    if(dep[u] > dep[v])
        swap(u, v);
    int diff = dep[v] - dep[u];
    LL ans = 0;
    for(int j = 0;j < 20;j++){
        if(diff & (1 << j)){
            ans = max(ans, mx[v][j]);
            v = par[v][j];
        }
    }
    if(u == v){
        return ans;
    }
    for(int j = 19;j >= 0;j--){
        if(par[u][j] != par[v][j]){
            ans = max(ans, mx[u][j]);
            ans = max(ans, mx[v][j]);
            u = par[u][j];
            v = par[v][j];
        }
    }
    ans = max(ans, mx[u][0]);
    ans = max(ans, mx[v][0]);
    return ans;
}

void querys(){
    init_lca();
    for(int i = 1;i <= q;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        LL ans = query(a, b);
        printf("%lld\n", ans);
    }
}

int main(){
    cin >> n >> m >> k >> q;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        G[u[i]].push_back(make_pair(v[i], w[i]));
        G[v[i]].push_back(make_pair(u[i], w[i]));
    }
    dijkstra();
    build_tree();
    dfs(1, 1, 1, 0);
    querys();
    return 0;
}