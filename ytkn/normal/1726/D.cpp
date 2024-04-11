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


struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

struct edge{
    int idx, to;
    edge(int idx, int to): idx(idx), to(to) {}
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
        if(u[i] > v[i]) swap(u[i], v[i]);
        g[u[i]].push_back(edge(i, v[i]));
        g[v[i]].push_back(edge(i, u[i]));
    }
    vector<bool> seen(n);
    vector<int> par(n);
    vector<bool> conn(m);
    vector<int> depth(n);
    function<void(int, int, int)> dfs = [&](int v, int p, int d){
        seen[v] = true;
        par[v] = p;
        depth[v] = d;
        for(edge e: g[v]){
            if(e.to == p) continue;
            if(seen[e.to]){
                conn[e.idx] = true;
            }else{
                dfs(e.to, v, d+1);
            }
        }
    };
    dfs(0, -1, 0);
    if(m == n+2){
        set<int> st;
        for(int i = 0; i < m; i++){
            if(conn[i]){
                st.insert(u[i]);
                st.insert(v[i]);
            }
        }
        if(st.size() == 3){
            int max_depth = -1;
            int s = -1;
            for(int v: st){
                if(chmax(max_depth, depth[v])) s = v;
            }
            int t = -1;
            for(int v: st){
                if(v == s) continue;
                t = v;
                break;
            }
            vector<int> col(m);
            for(int i = 0; i < m; i++){
                if(u[i] == s && v[i] == t) continue;
                if(v[i] == s && u[i] == t) continue;
                if(st.count(u[i]) && st.count(v[i])) col[i] = 1;
                if(u[i] == s && v[i] == par[s]) col[i] = 1;
                if(v[i] == s && u[i] == par[s]) col[i] = 1;
            }
            for(int i = 0; i < m; i++) cout << col[i];
            cout << '\n';
            return;
        }
    }
    for(int i = 0; i < m; i++){
        if(conn[i]) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}