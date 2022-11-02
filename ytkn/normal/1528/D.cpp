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

using P = pair<int, int>;
const ll inf = 1e18;

struct edge{
    int to;
    ll cost;
    edge(int to, ll cost): to(to), cost(cost) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(edge(b, c));
    }
    auto dist = vec2d(n, n, inf);
    for(int v = 0; v < n; v++){
        vector<bool> seen(n);
        for(edge e: g[v]){
            chmin(dist[v][e.to], e.cost);
        }
        for(int j = 0; j < n; j++){
            int u = -1;
            ll min_dist = inf;
            for(int k = 0; k < n; k++){
                if(seen[k]) continue;
                if(chmin(min_dist, dist[v][k])) u = k;
            }
            assert(u != -1);
            // debug_value(u)
            // cout << v << "->" << u << ':' << dist[v][u] << endl;
            seen[u] = true;
            for(edge e: g[u]){
                int rem = dist[v][u]%n;
                int to = (e.to+rem)%n;
                chmin(dist[v][to], dist[v][u]+e.cost);
            }
            chmin(dist[v][(u+1)%n], dist[v][u]+1);
        }
    }
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < n; i++) print_vector(dist[i]);
}