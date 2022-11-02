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
#include <random>

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

vector<vector<int>> gen_tree(int n){
    random_device rnd;
    mt19937 mt(rnd());
    UnionFind uf(n);
    vector<vector<int>> tree(n);
    auto add_edge = [&](int u, int v){
        if(u == v) return;
        if(u > v) swap(u, v);
        if(uf.findSet(u, v)) return;
        tree[u].push_back(v);
        tree[v].push_back(u);
        uf.unionSet(u, v);
    };
    while(uf.size(0) != n){
        int u = mt()%n;  
        int v = mt()%n;
        if(u == v) continue;
        add_edge(u, v);
    }
    return tree;
}

// #define DEBUG
using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
#ifdef DEBUG
    auto g = gen_tree(n);
#else
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
#endif
    if(n == 1){
        cout << 1 << endl;
        cout << 1 << ' ' << 0 << endl;
        return 0;
    }
    vector<int> deg(n);
    for(int i = 0; i < n; i++) deg[i] = g[i].size();
    int max_deg = *max_element(deg.begin(), deg.end());
    vector<P> ans;
    int t = 0;
    function<void(int, int)> dfs = [&](int v, int par){
        ans.push_back(P(v, t));
        int in = t;
        if(t == max_deg){
            t -= deg[v];
            ans.push_back(P(v, t));
        }
        for(int to: g[v]){
            if(to == par) continue;
            t++;
            dfs(to, v);
            t++;
            ans.push_back(P(v, t));
            if(v != 0 && t == max_deg){
                t -= deg[v];
                ans.push_back(P(v, t));
            }
        }
        if(v != 0){
            if(t != in-1){
                assert(t > in-1);
                t = in-1;
                ans.push_back(P(v, t));
            }
        }
    };
    dfs(0, -1);
    set<P> st;
    
    cout << ans.size() << '\n';
    for(auto [v, t]: ans) {
        st.insert(P(v, t));
        cout << v+1 << ' ' << t << '\n';
        assert(t <= max_deg);
    }
    assert(st.size() == ans.size());
}