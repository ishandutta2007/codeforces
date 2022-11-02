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

vector<int> tree_diameter(vector<vector<int>> g){
    int n = g.size();
    vector<bool> used(n, false);
    vector<int> dist(n);
    auto clear = [&](){
        for(int i = 0; i < n; i++) used[i] = false;
    };
    auto dfs = [&](auto&& f, int v, int d) -> void{
        used[v] = true;
        dist[v] = d;
        for(int to : g[v]){
            if(!used[to]) f(f, to, d+1);
        }
    };
    dfs(dfs, 0, 0);
    int s = 0;
    for(int i = 0; i < n; i++){
        if(dist[s] < dist[i]) s = i;
    }
    clear();
    dfs(dfs, s, 0);
    int t = 0;
    for(int i = 0; i < n; i++){
        if(dist[t] < dist[i]) t = i;
    }
    int v = t;
    vector<int> path;
    path.push_back(t);
    while(v != s){
        for(int to : g[v]){
            if(dist[to] == dist[v]-1) {
                v = to;
                break;
            }
        }
        path.push_back(v);
    }
    return path;
}

vector<int> calc_dist(vector<vector<int>> &g, int s){
    int n = g.size();
    vector<int> depth(n);
    function<void(int, int, int)> dfs = [&](int v, int par, int d){
        depth[v] = d;
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v, d+1);
        }
    };
    dfs(s, -1, 0);
    return depth;
}

ll comb2(ll n){
    return (n*(n-1))/2;
}

using T = tuple<int, int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto diam = tree_diameter(g);
    vector<bool> in_diam(n);
    for(int v: diam) in_diam[v] = true;
    int s = diam[0], t = diam.back();
    auto ds = calc_dist(g, s);
    auto dt = calc_dist(g, t);
    vector<T> ans;
    ll sum = comb2(diam.size());
    function<void(int, int)> dfs = [&](int v, int par){
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
        }
        if(!in_diam[v]){
            sum += max(ds[v], dt[v]);
            if(ds[v] < dt[v]){
                ans.push_back(T(v, t, v));
            }else{
                ans.push_back(T(v, s, v));
            }
        }
    };
    dfs(s, -1);
    for(int v: diam){
        if(v == t) continue;
        ans.push_back(T(v, t, v));
    }
    cout << sum << '\n';
    for(auto [a, b, c]: ans) cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
}