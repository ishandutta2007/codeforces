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

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

const ll INF = 1e+15;

typedef pair<ll, int> P;

struct edge{
    int to;
    ll cost;
};

vector<ll> dijkstra(int s, vector<vector<edge>> G){
    priority_queue<P, vector<P>, greater<P>> que;
    int n = G.size();
    vector<ll> d(n, INF);
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
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    int sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy; sx; sy; fx; fy;
    vector<int> x(m), y(m);
    vector<int> v = {sx, sy, fx, fy};
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    auto cp = Compress<int>(v);
    int mm = cp.size();
    int s = 0;
    auto row_index = [&](int i){ return i+1; };
    auto col_index = [&](int i){ return i+mm+1; };
    auto spot_index = [&](int i){ return i+2*mm+1; };
    int t = spot_index(m-1)+1;
    vector<vector<edge>> g(t+1);
    auto add_edge = [&](int u, int v, ll cost){
        g[u].push_back(edge{v, cost});
        g[v].push_back(edge{u, cost});
    };
    auto dist = [&](int x1, int y1, int x2, int y2){
        return abs(x2-x1)+abs(y2-y1);
    };
    add_edge(s, row_index(cp[sx]), 0);
    add_edge(s, col_index(cp[sy]), 0);
    add_edge(s, t, dist(sx, sy, fx, fy));
    for(int i = 0; i+1 < mm; i++){
        add_edge(row_index(i), row_index(i+1), cp.data[i+1]-cp.data[i]);
        add_edge(col_index(i), col_index(i+1), cp.data[i+1]-cp.data[i]);
    }
    for(int i = 0; i < m; i++){
        int ri = row_index(cp[x[i]]);
        int ci = col_index(cp[y[i]]);
        add_edge(spot_index(i), ri, 0);
        add_edge(spot_index(i), ci, 0);
        add_edge(spot_index(i), t, dist(x[i], y[i], fx, fy));
    }
    auto d = dijkstra(s, g);
    cout << d[t] << endl;
}