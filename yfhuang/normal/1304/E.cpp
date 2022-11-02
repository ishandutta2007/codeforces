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

const int maxn = 2e5 + 5;
const int maxk = 20;
int n;
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

int dis(int a, int b){
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1, 0);
    init_lca();
    int Q;
    cin >> Q;
    for(int i = 1;i <= Q;i++){
        int x, y, a, b, k;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
        int dis1 = dis(a, b);
        bool flag = false;
        if(k >= dis1 and ((k - dis1) % 2 == 0)){
            flag = true;
        }
        int dis2 = dis(x, a) + 1 + dis(y, b);
        int dis3 = dis(x, b) + 1 + dis(y, a);
        if(k >= dis2 and ((k - dis2) % 2 == 0)){
            flag = true;
        }
        if(k >= dis3 and ((k - dis3) % 2 == 0)){
            flag = true;
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }    
    return 0;
}