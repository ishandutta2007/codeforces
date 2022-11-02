#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int deg[maxn];
int dep[maxn];
bool isleaf[maxn];
int dp[maxn];

void dfs(int u, int fa, int d){
    dep[u] = d;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, d + 1);
    }
}

void dfs1(int u, int fa){
    bool haveleaf = false;
    dp[u] = 0;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        if(isleaf[v]){
            haveleaf = true;
        }else{
            dfs1(v, u); 
            dp[u] += (dp[v] + 1);
        }
    }
    if(haveleaf)
        dp[u]++;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    vector<int> leaf;
    int root = 0;
    for(int i = 1;i <= n;i++){
        if(deg[i] == 1){
            leaf.push_back(i); 
            isleaf[i] = true;
        }else{
            root = i;
        }
    }
    dfs(root, root, 0);
    bool odd = false, even = false;
    for(auto v : leaf){
        if(dep[v] & 1){
            odd = true;
        }else{
            even = true;
        }
    }
    int L, R;
    if(odd and even){
        L = 3;
    }else{
        L = 1;
    }
    dfs1(root, root);
    R = dp[root];
    cout << L << " " << R << endl;
    return 0;
}