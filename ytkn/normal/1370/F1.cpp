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

class Lca{
    public:
        vector<int> depth;
        vector<vector<int>> parent;
        vector<vector<int>> G;
        int root;
        int n;
        const int N_LOG_MAX = 25;
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

using P = pair<int, int>;

class Simulator{
    public:
    int n;
    vector<vector<int>> g;
    Lca lca;
    Simulator(int n, vector<vector<int>> g): n(n), g(g), lca(Lca(g, 0)) {
        assert(g.size() == n);
        n_asked = 0;
        lca.init();
        random_device rnd;
        mt19937 mt(rnd());
        u = mt()%n;
        v = mt()%n;
        while(u == v) v = mt()%n;
        if(u > v) swap(u, v);
    }
    P ask(vector<int> vs){
        n_asked++;
        vector<P> dist_sum;
        for(int x: vs){
            dist_sum.push_back(P(lca.dist(x, u)+lca.dist(x, v), x));
        }
        sort(dist_sum.begin(), dist_sum.end());
        auto [d, x] = dist_sum[0];
        return P(x, d);
    }
    void verify(int uu, int vv){
        if(uu > vv) swap(uu, vv);
        cout << u << ' ' << v << ' ' << uu << ' ' << vv << ' ' << n_asked << endl;
        assert(u == uu);
        assert(v == vv);
    }

    private:
    int u, v;
    int n_asked;
};

void dfs(int v, vector<vector<int>> &g, vector<int> &depth, int d){
    depth[v] = d;
    for(int to: g[v]){
        if(depth[to] == -1){
            dfs(to, g, depth, d+1);
        }
    }
}


// #define DEBUG

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
#ifdef DEBUG
    g = gen_tree(n);
    auto sim = Simulator(n, g);
#else
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
#endif
    auto ask = [&](const vector<int> &v){
#ifdef DEBUG
        return sim.ask(v);
#else
        assert(!v.empty());
        cout << "? " << v.size() << ' ';
        for(int x: v) cout << x+1 << ' ';
        cout << endl;
        int u, d; cin >> u >> d; u--;
        return make_pair(u, d);
#endif
    };
    vector<int> all_v(n);
    iota(all_v.begin(), all_v.end(), 0);
    auto [r, d] = ask(all_v);
    vector<int> depth(n, -1);
    dfs(r, g, depth, 0);
    Lca lca(g, r);
    lca.init();
    int max_depth = *max_element(depth.begin(), depth.end());
    vector<P> memo(max_depth+1, P(-1, -1));
    memo[0] = P(r, d);
    auto ask_depth = [&](int d){
        if(memo[d] != P(-1, -1)){
            return memo[d];
        }
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(depth[i] >= d) v.push_back(i);
        }
        memo[d] = ask(v);
        return memo[d];
    };
    auto verify = [&](int u, int v){
#ifdef DEBUG
        sim.verify(u, v);
#else
        cout << "! " << u+1 << ' ' << v+1 << endl;
        string ans; cin >> ans;
        assert(ans == "Correct");
#endif
    };
    int u = -1, u_depth = -1;
    if(ask_depth(max_depth).second == d){
        u_depth = max_depth;
        u = memo[u_depth].first;
    }else{
        int l = 0, r = max_depth;
        while(r-l > 1){
            int x = (l+r)/2;
            if(ask_depth(x).second == d){
                l = x;
            }else{
                r = x;
            }
        }
        u_depth = l;
        u = memo[u_depth].first;
    }
    int v = -1, v_depth = d-u_depth;
    if(v_depth == 0){
        v = r;
    }else{
        vector<int> query;
        for(int i = 0; i < n; i++){
            if(i == u) continue;
            if(lca.lca(u, i) == i) continue;
            if(depth[i] == v_depth) query.push_back(i);
        }
        auto [vv, vd] = ask(query);
        assert(vd == d);
        v = vv;
        assert(v_depth == depth[v]);
    }
    
    verify(u, v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}