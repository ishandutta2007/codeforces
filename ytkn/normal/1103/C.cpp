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

/**
 * verified: https://atcoder.jp/contests/typical90/submissions/21934380
 */ 
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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> seen(n);
    vector<int> depth(n);
    vector<int> par(n, -1);
    vector<vector<int>> tree(n);
    function<void(int, int)> dfs = [&](int v, int d){
        seen[v] = true;
        depth[v] = d;
        for(int to: g[v]){
            if(seen[to]) continue;
            tree[to].push_back(v);
            tree[v].push_back(to);
            par[to] = v;
            dfs(to, d+1);
        }
    };
    dfs(0, 0);
    auto diam = tree_diameter(tree);
    if((ll)diam.size()*k >= n){
        cout << "PATH" << endl;
        cout << diam.size() << endl;
        for(int v: diam) cout << v+1 << ' ';
        cout << endl;
        return 0;
    }
    vector<vector<int>> ans;
    for(int v = 0; v < n; v++){
        if(v == 0) continue;
        if(tree[v].size() > 1) continue;
        vector<P> vp;
        for(int a: g[v]){
            if(a == par[v]) continue;
            vp.push_back(P(depth[a], a));
        }
        sort(vp.begin(), vp.end(), greater<P>());
        if(vp.size() < 2) return 0;
        int a0 = vp[0].second;
        int a1 = vp[1].second;
      
        // assert(depth[a0] < depth[v]);
        // assert(depth[a1] < depth[v]);
        vector<int> path;
        if((depth[a0]+2)%3 != depth[v]%3){
            int cur = v;
            while(true){
                path.push_back(cur);
                if(cur == a0) break;
                if(cur == 0) return 0;
                cur = par[cur];
            }
        }else if((depth[a1]+2)%3 != depth[v]%3){
            int cur = v;
            while(true){
                path.push_back(cur);
                if(cur == a1) break;
                cur = par[cur];
            }
        }else{
            path.push_back(v);
            int cur = a0;
            while(true){
                path.push_back(cur);
                if(cur == a1) break;
                cur = par[cur];
            }
        }
        ans.push_back(path);
        if(ans.size() == k) break;
    }
    // assert(ans.size() == k);
    cout << "CYCLES" << endl;
    for(auto cycle: ans){
        cout << cycle.size() << endl;
        for(int v: cycle) cout << v+1 << ' ';
        cout << endl;
    }
}