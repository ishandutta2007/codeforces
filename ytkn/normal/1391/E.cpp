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

using P = pair<int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> tree(n);
    vector<bool> seen(n);
    vector<int> par(n, -1);
    vector<int> deg(n);
    function<void(int)> dfs = [&](int v){
        seen[v] = true;
        for(int to: g[v]){
            if(seen[to]) continue;
            tree[v].push_back(to);
            tree[to].push_back(v);
            par[to] = v;
            deg[v]++;
            dfs(to);
        }
    };
    dfs(0);
    auto diam = tree_diameter(tree);
    if(diam.size()*2 >= n){
        cout << "PATH" << "\n";
        cout << diam.size() << "\n";
        for(int v: diam) cout << v+1 << ' ';
        cout << "\n";
        return;
    }
    queue<int> que;
    for(int i = 0; i < n; i++){
        if(deg[i] == 0) que.push(i);
    }
    vector<P> ans;
    while(ans.size()*4 < n){
        assert(que.size() >= 2);
        int a = que.front(); que.pop();
        int b = que.front(); que.pop();
        ans.push_back(P(a, b));
        deg[par[a]]--;
        if(deg[par[a]] == 0) que.push(par[a]);
        deg[par[b]]--;
        if(deg[par[b]] == 0) que.push(par[b]);
    }
    cout << "PAIRING" << "\n";
    cout << ans.size() << "\n";
    for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}