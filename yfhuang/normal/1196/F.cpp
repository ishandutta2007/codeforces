#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

int n, m, k;

typedef pair<int, int> pii;
typedef pair<int, pii > piii;
const int maxn = 2e5 + 5;
vector<pii> G[maxn];
piii edge[maxn];
int tot;
int node[maxn];
typedef long long LL;
LL dis[maxn];


void dijkstra(int start){
    for(int i = 1;i <= tot;i++){
        dis[node[i]] = 1e18;
    }
    dis[start] = 0;
    priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > pq;
    pq.push(make_pair(dis[start], start));
    while(!pq.empty()){
        pair<LL, int> p = pq.top();pq.pop();
        LL d = p.first;
        int u = p.second;
        for(auto x : G[u]){
            int v = x.first;
            int len = x.second;
            if(dis[v] > dis[u] + len){
                dis[v] = dis[u] + len;
                pq.push(make_pair(dis[v], v));
            }
        }
    }  
  //  for(int i = 1;i <= tot;i++){
 //       cout << node[i] << " " << dis[node[i]] << endl;
   // }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = make_pair(w, make_pair(u, v));
    }
    int N = min(m, k);
    sort(edge + 1, edge + 1 + m);
    for(int i = 1;i <= N;i++){
        int w = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
        node[++tot] = u;
        node[++tot] = v;
    }
    sort(node + 1, node + 1 + tot);
    tot = unique(node + 1, node + 1 + tot) - node - 1;
    vector<LL> ans;
    for(int i = 1;i <= tot;i++){
        dijkstra(node[i]);
//        cout << node[i] << endl;
        for(int j = i + 1;j <= tot;j++){
            if(dis[node[j]] != 1e18){
//                cout << node[i] << " " << node[j] << endl;
                ans.push_back(dis[node[j]]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[k - 1] << endl;
    return 0;
}