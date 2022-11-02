#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

struct edge {
    edge(int to, ll cost): to(to), cost(cost){};
    int to;
    ll cost;
};

const ll INF = 1e17;
typedef tuple<ll, int, int> T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    vector<vector<ll>> dist(n, vector<ll>(4, INF));
    dist[0][0] = 0;
    priority_queue<T, vector<T>, greater<T>> que;
    que.push(T(0, 0, 0));
    auto update = [&](int v, int s, ll d){
        if(dist[v][s] > d){
            dist[v][s] = d;
            que.push(T(d, v, s));
        }
    };
    while(!que.empty()){
        auto [d, v, s] = que.top(); que.pop();
        if(d > dist[v][s]) continue;
        for(edge e : g[v]){
            update(e.to, s, dist[v][s]+e.cost);
            if(!(s&1)) update(e.to, s+1, dist[v][s]);
            if(!(s&2)) update(e.to, s+2, dist[v][s]+2*e.cost);
            if(!(s&3)) update(e.to, s+3, dist[v][s]+e.cost);
        }
    }
    for(int i = 1; i < n; i++) cout << dist[i][3] << ' ';
    cout << endl;
}