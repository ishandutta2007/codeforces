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

int n, m, k;
const int maxn = 2e5 + 5;
int dis[2][maxn];
bool vis[2][maxn];
vector<int> G[maxn];
const int INF = 1e9;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > pq;

void D(int s, int t){
    while(!pq.empty()){
        pq.pop();
    }
    for(int i = 1;i <= n;i++){
        dis[t][i] = INF;
        vis[t][i] = false;
    }
    dis[t][s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        int u = p.second;
        if(vis[t][u])
            continue;
        vis[t][u] = true;
        for(auto v : G[u]){
            if(dis[t][v] > dis[t][u] + 1){
                dis[t][v] = dis[t][u] + 1;
                pq.push(make_pair(dis[t][v], v));
            }
        }
    } 
}

int a[maxn];

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    D(1, 0);
    D(n, 1);
    vector<pii> x, y;
    for(int i = 1;i <= k;i++){
        x.emplace_back(dis[0][a[i]], a[i]);
        y.emplace_back(dis[1][a[i]], a[i]);
    }
    sort(x.begin(), x.end());
    int ans = 0;
    for(int i = 0;i < k - 1;i++){
        int u = x[i].second;
        int v = x[i + 1].second;
        int tmp = min(dis[0][u] + 1 + dis[1][v], dis[1][u] + 1 + dis[0][v]);
        ans = max(ans, tmp);
    }
    cout << min(ans, dis[0][n]) << endl;
    return 0;
}