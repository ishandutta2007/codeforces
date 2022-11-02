#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;

const int maxn = 2e5 + 5;
int x[maxn];
vector<int> G[maxn];
bool mark[maxn];

int dis[maxn], dep[maxn];

const int INF = 1e9;

void dfs(int u, int fa, int d){
    if(mark[u])
        dis[u] = 0;
    else
        dis[u] = INF;
    dep[u] = d;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        dfs(v, u, d + 1);
        dis[u] = min(dis[u], dis[v] + 1);
    }
}

bool dfs2(int u, int fa){
    if(u != 1 and G[u].size() == 1){
        return true;
    }
    bool flag = false;
    for(auto v : G[u]){
        if(v == fa)
            continue;
        if(dis[v] <= dep[v])
            continue;
        else
            flag |= dfs2(v, u);
    }
    return flag;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        for(int i = 1;i <= k;i++){
            cin >> x[i];
            mark[x[i]] = 1;
        }
        for(int i = 1;i < n;i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 1, 0);
        bool flag = dfs2(1, 1);
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        for(int i = 1;i <= n;i++){
            G[i].clear();
        }
        for(int i = 1;i <= k;i++){
            mark[x[i]] = 0;
        }
    }
    return 0;
}