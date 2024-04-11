#include <bits/stdc++.h>
using namespace std;


const int maxn = 2e5 + 5;
int u[maxn], v[maxn];
int n, m;
int deg[maxn];
int dp[2][maxn];
vector<int> G[2][maxn];

bool toposort(){
    queue<int> q;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(deg[i] == 0){
            q.push(i);
            cnt++;
        }
    }
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto to : G[0][p]){
            deg[to]--;
            if(deg[to] == 0){
                q.push(to);
                cnt++;
            }
        }
    }
    if(cnt == n){
        return true;
    }else{
        return false;
    }
}

string ans;

bool vis[maxn];

void dfs(int u, int id){
    vis[u] = true;
    dp[id][u] = u;
    for(auto v : G[id][u]){
        if(!vis[v]){
            dfs(v, id);
        }
        dp[id][u] = min(dp[id][u], dp[id][v]);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> u[i] >> v[i];
        G[0][u[i]].push_back(v[i]);
        deg[v[i]]++;
        G[1][v[i]].push_back(u[i]);
    } 
    if(!toposort()){
        cout << -1 << endl;
    }else{
        int cnt = 0;
        string ans;
        for(int i = 1;i <= n;i++){
            ans.push_back('E');
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                dfs(i, 0);
            }
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                dfs(i, 1);
            }
        }
        for(int i = 1;i <= n;i++){
            if(dp[0][i] == i and dp[1][i] == i){
                cnt++;
                ans[i - 1] = 'A';
            }
        }
        cout << cnt << endl;
        cout << ans << endl;
    }
    return 0;
}