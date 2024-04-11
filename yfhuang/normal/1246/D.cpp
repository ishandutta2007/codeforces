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

const int maxn = 1e5 + 5;

vector<int> G[maxn];
vector<pair<int, int> > g[maxn];
int n;
int dfn[maxn];
int dep[maxn], dep1[maxn];
int tot;
int sz[maxn];
int fa[maxn];

void dfs(int u, int d){
    dep[u] = d;
    sz[u] = 0;
    for(auto v : G[u]){
        dfs(v, d + 1);
        sz[u] = max(sz[v] + 1, sz[u]);
    }
}
int id[maxn];
int tid[maxn];

void dfs1(int u){
    //cout << u << endl;
    id[u] = tot;
    tid[tot] = u;
    ++tot;
    for(auto v : g[u]){
        dfs1(v.second);
    }
}

vector<int> op;

void dfs2(int u){
    if(fa[u] == u){
        dep1[u] = 0;
    }else{
        dep1[u] = dep1[fa[u]] + 1;
    }
    while(dep1[u] != dep[u]){
        fa[u] = fa[fa[u]];
        dep1[u] = dep1[fa[u]] + 1;
        op.push_back(u);
    }
    for(auto v : g[u]){
        dfs2(v.second);            
    }
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int par;
        scanf("%d", &par);
        G[par].push_back(i);
    }
    dfs(0, 0);
    tot = 0;
    for(int i = 0;i < n;i++){
        for(auto v : G[i]){
            g[i].push_back(make_pair(sz[v], v));
        }
        sort(g[i].begin(), g[i].end());
    }
    dfs1(0);
    fa[0] = 0;
    for(int i = 0;i < n;i++){
        dep1[i] = id[i];
    }
    for(int i = 1;i < n;i++){
        fa[tid[i]] = tid[i - 1];    
    }
    dfs2(0);
    for(int i = 0;i < n;i++){
        printf("%d%c", tid[i], i == n - 1 ? '\n' : ' ');
    }
    cout << op.size() << endl;
    for(int i = 0;i < op.size();i++){
        printf("%d%c", op[i], i == op.size() - 1 ? '\n' : ' ');
    }
    return 0;
}