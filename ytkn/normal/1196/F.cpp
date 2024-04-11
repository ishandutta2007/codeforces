#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll INF = 1e+15;

typedef pair<ll, int> P;

struct edge{
    int to;
    ll cost;
};

int n, m, k;

set<int> st;
int x[200000], y[200000], w[200000];
P p[200000];

ll d[200000];
vector<edge> G[200000];
vector<ll> dist;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    for(int v : st) d[v] = INF;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[v] + e.cost < d[e.to]){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> w[i];
        x[i]--; y[i]--;
        p[i] = P(w[i], i);
    }
    sort(p, p+m);
    for(int i = 0; i < min(k, m); i++){
        int idx = p[i].second;
        G[x[idx]].push_back((edge){y[idx], w[idx]});
        G[y[idx]].push_back((edge){x[idx], w[idx]});
        st.insert(x[idx]);
        st.insert(y[idx]);
    }
    for(int v : st){
        // cout << v << endl;
        dijkstra(v);
        for(int u: st){
            if(u > v){
                dist.push_back(d[u]);
            }
        }
    }
    sort(dist.begin(), dist.end());
    cout << dist[k-1] << endl;
}