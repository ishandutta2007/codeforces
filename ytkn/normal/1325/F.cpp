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

vector<vector<int>> gen_undirected(int n, int m, bool is_connected){
    vector<vector<int>> g(n);
    int rem = m;
    if(is_connected){
        assert(m >= n-1);
        g = gen_tree(n);
        rem -= n-1;
    }
    set<pair<int, int>> used;
    for(int i = 0; i < n; i++){
        for(int j: g[i]){
            if(i < j) used.insert(make_pair(i, j));
        }
    }
    auto add_edge = [&](int u, int v){
        if(u == v) return;
        if(u > v) swap(u, v);
        if(used.count(make_pair(u, v))) return;
        g[u].push_back(v);
        g[v].push_back(u);
        used.insert(make_pair(u, v));
        rem--;
    };
    random_device rnd;
    mt19937 mt(rnd());
    while(rem){
        int u = mt()%n;  
        int v = mt()%n;
        if(u == v) continue;
        add_edge(u, v);
    }
    return g;
}

int n;
int depth[100000];
bool seen[100000];
vector<vector<int>> g;
vector<int> par;

vector<int> ord;

void dfs(int v, int d){
    seen[v] = true;
    depth[v] = d;
    for(int to: g[v]){
        if(!seen[to]){
            par[to] = v;
            dfs(to, d+1);
        }else{
            if(v == 0) continue;
            int cnt = depth[v]-depth[to]+1;
            if(cnt < 0) continue;
            if(cnt*cnt < n) continue;
            vector<int> ans;
            int cur = v;
            bool ng = false;
            while(cur != to){
                assert(cur != -1);
                ans.push_back(cur);
                cur = par[cur];
            }
            ans.push_back(cur);
            cout << 2 << endl;
            cout << ans.size() << endl;
            for(int x: ans) cout << x+1 << ' ';
            cout << endl;
            exit(0);
        }
    }
    ord.push_back(v);
}

using P = pair<int, int>;
bool ng[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int m; cin >> n >> m;
    g.resize(n);
    par.assign(n, -1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    vector<int> ans;
    for(int v: ord){
        int x = ans.size();
        if(x*x >= n) break;
        if(!ng[v]){
            ans.push_back(v);
            for(int to: g[v]){
                ng[to] = true;
            }
        }
    }
    int x = ans.size();
    assert(x*x >= n);
    assert((x-1)*(x-1) < n);
    cout << 1 << endl;
    for(int x: ans) cout << x+1 << ' ';
    cout << endl;
}