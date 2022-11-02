#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

const ll INF = 1e+18;

typedef pair<ll, int> P;

struct edge{
    int from, to;
    ll cost;
    edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
};

vector<int> bfs(int s, vector<vector<int>> G){
    queue<int> que;
    int n = G.size();
    const int inf = 1e9;
    vector<int> d(n, inf);
    auto set_dist = [&](int v, int dist){
        if(d[v] == inf){
            d[v] = dist;
            que.push(v);
        }
    };
    d[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();que.pop();
        for(int to: G[v]){
            set_dist(to, d[v]+1);
        }
    }
    return d;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<edge> edges;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back(edge(u, v, w));
    }
    auto to_idx = [&](int i, int j){
        if(i > j) swap(i, j);
        return n*i+j;
    };
    vector<int> dist(n*n, -1);
    queue<int> que;
    auto set_dist = [&](int idx, int d){
        if(dist[idx] == -1){
            que.push(idx);
            dist[idx] = d;
        }else{
            assert(d >= dist[idx]);
        }
    };
    set_dist(to_idx(0, n-1), 0);
    // set_dist(to_idx(1, 4), 0);
 
    while(!que.empty()){
        auto idx = que.front(); que.pop();
        int u = idx/n, v = idx%n;
        for(int to: g[v]) set_dist(to_idx(to, u), dist[idx]+1);
        for(int to: g[u]) set_dist(to_idx(to, v), dist[idx]+1);
        if(u == v){
            for(int j = 0; j < n; j++) set_dist(to_idx(v, j), dist[idx]+1);
        }
        
    }
    ll ans = INF;
    for(auto e: edges){
        chmin(ans, e.cost*(dist[to_idx(e.to, e.from)]+1));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}