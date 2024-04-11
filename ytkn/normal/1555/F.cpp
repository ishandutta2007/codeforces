#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

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
    bool is_root(int x) {
        return root(x) == x;
    }
    int size(int x) {
        return -data[root(x)];
    }
};

class Lca{
    public:
        vector<int> depth;
        vector<vector<int>> parent;
        vector<vector<int>> G;
        int root;
        int n;
        const int N_LOG_MAX = 20;
        bool initialized = false;

        Lca(vector<vector<int>> g, int _root){
            n = g.size();
            G = g;
            root = _root;
            parent = vector<vector<int>>(N_LOG_MAX, vector<int>(n));
            depth = vector<int>(n, 0);
        }

        void init(){
            initialized = true;
            dfs(root, -1, 0);
            for(int i = 0; i < N_LOG_MAX-1; i++){
                for(int v = 0; v < n; v++){
                    if(parent[i][v] < 0) parent[i+1][v] = -1;
                    else parent[i+1][v] = parent[i][parent[i][v]];
                }
            }
        }

        int lca(int u, int v){
            assert(initialized);
            if(depth[u] > depth[v]) swap(u, v);
            for(int i = 0; i < N_LOG_MAX; i++){
                if((depth[v] - depth[u]) >> i & 1){
                    v = parent[i][v];
                }
            }
            if(u == v) return u;
            for(int i = N_LOG_MAX-1; i >= 0; i--){
                if(parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }
            return parent[0][u];
        }

        int dist(int u, int v){
            int l = lca(u, v);
            return depth[u]+depth[v]-2*depth[l];
        }

    private:
        void dfs(int v, int p, int d){
            parent[0][v] = p;
            depth[v] = d;
            for(int i = 0; i < G[v].size(); i++){
                if(G[v][i] != p) dfs(G[v][i], v, d+1); 
            }
        }
};

class EulerTour{
    public:
    vector<vector<int>> g;
    int root;
    int n;
    vector<int> ord;
    vector<int> in, out;
    EulerTour(vector<vector<int>> g, int root): g(g), root(root){
        n = g.size();
        in.resize(n);
        out.resize(n);
        build();
    }
    private:
    void build(){
        vector<bool> seen(n, false);
        dfs(0, seen);
    }
    void dfs(int v, vector<bool> &seen){
        seen[v] = true;
        in[v] = ord.size();
        ord.push_back(v);
        int cnt = 0;
        for(int to: g[v]){
            if(seen[to]) continue;
            dfs(to, seen);
            cnt++;
        }
        if(cnt > 0) {
            out[v] = ord.size();
            ord.push_back(v);
        }else{
            out[v] = ord.size()-1;
        }
    }
};

struct edge{
    int to, x;
};

vector<edge> h[300001];
bool used[300001];
int xo[300001];

void dfs(int v, int x){
    used[v] = true;
    xo[v] = x;
    for(edge e: h[v]){
        if(used[e.to]) continue;
        dfs(e.to, x^e.x);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<int> u(q), v(q), x(q);
    UnionFind uf(n+1);
    vector<vector<int>> g(n+1);
    vector<bool> ans(q);
    for(int i = 0; i < q; i++){
        cin >> u[i] >> v[i] >> x[i];
        if(!uf.findSet(u[i], v[i])){
            uf.unionSet(u[i], v[i]);
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
            h[u[i]].push_back(edge{v[i], x[i]});
            h[v[i]].push_back(edge{u[i], x[i]});
            ans[i] = true;
        }
    }
    for(int i = 1; i <= n; i++){
        if(uf.is_root(i)){
            g[0].push_back(i);
            g[i].push_back(0);
            h[i].push_back(edge{0, 0});
            h[0].push_back(edge{i, 0});
        }
    }
    dfs(0, 0);
    auto lc = Lca(g, 0);
    auto et = EulerTour(g, 0);
    bit<int> bt(et.ord.size());
    auto get_current_depth = [&](int v){
        assert(bt.sum(et.in[v]) == bt.sum(et.out[v]));
        return bt.sum(et.in[v]);
    };
    for(int i = 1; i+1 < et.ord.size(); i++){
        int v = et.ord[i];
        if(et.in[v] == i) bt.add(i, 1);
        if(et.out[v] == i) bt.add(i+1, -1);
    }
    auto concat_with_parent = [&](int v){
        bt.add(et.in[v], -1);
        bt.add(et.out[v]+1, 1);
    };
    auto remaining_all_path = [&](int v, int ansestor){
        int pre_dist = lc.depth[v] - lc.depth[ansestor];
        int cur_dist = get_current_depth(v)-get_current_depth(ansestor);
        return pre_dist == cur_dist;
    };
    auto concat_to_ansestor = [&](int v, int ansestor){
        while(v != ansestor){
            concat_with_parent(v);
            v = lc.parent[0][v];
        }
    };
    lc.init();
    for(int i = 0; i < q; i++){
        if(ans[i]) continue;
        int lca = lc.lca(u[i], v[i]);
        auto ok = [&]() -> bool{
            if(xo[u[i]]^xo[v[i]]^x[i] == 0) return false;
            return remaining_all_path(u[i], lca) && remaining_all_path(v[i], lca);
        };
        if(ok()){
            ans[i] = true;
            concat_to_ansestor(v[i], lca);
            concat_to_ansestor(u[i], lca);
        }
    }
    for(int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << endl;
}