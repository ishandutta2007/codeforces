#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
typedef pair<int, int> pi;

int n;
vector<int> G[maxn];
int deg[maxn];
int L[maxn], R[maxn];
vector<pi> ans;

void dfs(int u, int fa, int val){
    if(val >= deg[u]){
        L[u] = val - deg[u];
        R[u] = val;
    }else{
        L[u] = 0;
        R[u] = deg[u];
    }
    ans.emplace_back(u, val); 
    deg[u]--;
    int cur = val;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        if(cur == R[u]){
            cur = L[u];
            ans.emplace_back(u, cur);
            deg[u]--;
        }
        dfs(v, u, cur + 1);
        ans.emplace_back(u, ++cur);
        deg[u]--;
    }
    if(deg[u] >= 0){
        if(cur == R[u]){
            cur = L[u];
        }else{
            cur = cur + 1;
        }
        ans.emplace_back(u, cur);
        deg[u]--;
    }
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
    dfs(1, 0, 0);
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}