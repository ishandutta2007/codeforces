#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;

const int maxn = 2e5 + 5;
vector<int> G[maxn];
int dis[maxn];
int deg[maxn];

void bfs(){
    queue<int> q;
    q.push(1);
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto v : G[p]){
            if(dis[v] > dis[p] + 1){
                dis[v] = dis[p] + 1;
                q.push(v);
            }
        }
    }
}

vector<int> rG[maxn];
vector<int> tree[maxn];
int dp[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pi> edges;
        for(int i = 1;i <= n;i++){
            deg[i] = 0;
            dp[i] = 1e9;
        }
        for(int i = 1;i <= m;i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            edges.push_back(mp(u, v));
        }
        bfs();
        for(int i = 1;i <= n;i++){
            dp[i] = dis[i];
        }
        for(auto e : edges){
            if(dis[e.fi] < dis[e.se]){
                tree[e.fi].push_back(e.se);
                deg[e.fi]++;
                rG[e.se].push_back(e.fi);
            }else{
                dp[e.fi] = min(dp[e.fi], dis[e.se]);
            }
        }
        queue<int> q;
        for(int i = 1;i <= n;i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v : tree[u]){
                dp[u] = min(dp[u], dp[v]);
            }
            for(auto v : rG[u]){
                deg[v]--;
                if(deg[v] == 0){
                    q.push(v);
                }
            }
        }
        for(int i = 1;i <= n;i++){
            cout << dp[i] << ((i == n) ? '\n' : ' ');
            tree[i].clear();
            G[i].clear();
            rG[i].clear();
        }
    }
    return 0;
}