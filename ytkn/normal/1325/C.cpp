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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    map<P, int> indices;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        indices[P(u, v)] = i;
        indices[P(v, u)] = i;
    }
    if(n == 2){
        cout << 0 << endl;
        return 0;
    }
    auto diam = tree_diameter(g);
    int m = diam.size();
    vector<bool> used(n-1, false);
    vector<int> ans(n-1, -1);
    int idx1 = indices[P(diam[0], diam[1])];
    int idx2 = indices[P(diam[m-2], diam[m-1])];
    auto set_val = [&](int idx, int v){
        assert(used[idx] == false);
        assert(ans[idx] == -1);
        ans[idx] = v;
        used[idx] = true;
    };
    set_val(idx1, 0);
    set_val(idx2, 1);
    int cur = n-2;
    for(int i = 1; i <= m-3; i++){
        int idx = indices[P(diam[i], diam[i+1])];
        set_val(idx, cur);
        cur--;
    }
    cur = 2;
    for(int i = 0; i < n-1; i++){
        if(!used[i]){
            set_val(i, cur);
            cur++;
        }
    }
    print_vector(ans, '\n');
}