#include <bits/stdc++.h>
using namespace std;

int n, k;
const int maxn = 2e5 + 5;
vector<int> G[maxn];
int dep[maxn], sz[maxn];
int val[maxn];

void dfs(int u, int fa, int d){
    sz[u] = 1;
    dep[u] = d; 
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
    }
    val[u] = dep[u] - sz[u];
}

bool cmp(int i, int j){
    return val[i] < val[j];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0, 1);
    vector<int> id(n, 0);
    for(int i = 0;i < n;i++){
        id[i] = i;
    }
    sort(id.begin(), id.end(), cmp);
    long long ans = 0;
    for(int i = n - 1;i >= n - k;i--){
        ans += val[id[i]];
    }
    cout << ans << endl;
    return 0;
}