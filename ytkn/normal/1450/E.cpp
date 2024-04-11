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

const int inf = 1e+9;

struct edge{
    int from, to, cost;
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
};

bool bellmanford(vector<edge> es, vector<int> &d, int s){
    int n = d.size();
    d.assign(n, inf);
    d[s] = 0;
    int cnt_loop = 0;
    while(true){
        cnt_loop++;
        bool update = false;
        for(int i = 0; i < es.size(); i++){
            edge e = es[i];
            if(d[e.from] != inf && d[e.from]+e.cost < d[e.to]){
                d[e.to] = d[e.from]+e.cost;
                update = true;
            }
        }
        if(!update) return true;
        else if(cnt_loop >= n) return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m), b(m);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> b[i];
        u[i]--; v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    vector<bool> seen(n);
    vector<int> col(n);
    function<bool(int, int)> is_bipartite = [&](int v, int c){
        seen[v] = true;
        col[v] = c;
        for(int to: g[v]){
            if(seen[to]){
                if(col[v] == col[to]) return false;
            }else{
                if(!is_bipartite(to, c^1)) return false;
            }
        }
        return true;
    };
    if(!is_bipartite(0, 0)){
        cout << "NO" << endl;
        return 0;
    }
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        if(col[u[i]] == 0){
            if(b[i] == 1){
                edges.push_back(edge(u[i], v[i], 0));
                edges.push_back(edge(v[i], u[i], 0));
            }else{
                edges.push_back(edge(u[i], v[i], 0));
                edges.push_back(edge(v[i], u[i], 1));
            }
        }else{
            if(b[i] == 1){
                edges.push_back(edge(u[i], v[i], 1));
                edges.push_back(edge(v[i], u[i], -1));
            }else{
                edges.push_back(edge(u[i], v[i], 1));
                edges.push_back(edge(v[i], u[i], 0));
            }
        }
    }
    int ans = -1;
    vector<int> ans_dist(n);
    for(int i = 0; i < n; i++){
        vector<int> dist(n);
        if(bellmanford(edges, dist, i)){
            int max_v = -inf, min_v = inf;
            for(int j = 0; j < n; j++){
                chmax(max_v, dist[j]*2+col[j]);
                chmin(min_v, dist[j]*2+col[j]);
            }
            if(chmax(ans, max_v-min_v)){
                for(int j = 0; j < n; j++) ans_dist[j] = dist[j]*2+col[j]-min_v;
            }
        }
    }
    if(ans == -1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        cout << ans << endl;
        print_vector(ans_dist);
    }
}