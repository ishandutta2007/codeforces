#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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

class CentrioidDecomposition{
    public:
    int n;
    vector<bool> used;
    vector<int> ch;
    vector<vector<int>> g;
    CentrioidDecomposition(int n, vector<vector<int>> g): n(n), g(g) {
        assert(g.size() == n);
        used.assign(n, false);
        ch.assign(n, 0);
    }

    /**
     * returns (root, balanced undirected tree)
     */ 
    pair<int, vector<vector<int>>> build_balanced_tree(){
        vector<vector<int>> tree(n);
        int centroid = find_centroid(0);
        for(int to : g[centroid]){
            if(!used[to]) sub_build(to, centroid, tree);
        }
        return make_pair(centroid, tree);
    }

    private:
    void dfs(int v, vector<int> &visited){
        used[v] = true;
        ch[v] = 1;
        visited.push_back(v);
        for(int to : g[v]){
            if(!used[to]){
                dfs(to, visited);
                ch[v] += ch[to];
            }
        }
    }

    int find_centroid(int r){
        vector<int> visited;
        dfs(r, visited);
        int m = visited.size();
        for(int v : visited) used[v] = false;
        int cur = r;
        int pre = -1;
        while(true){
            int nx = -1;
            int max_ch = -1;
            for(int to : g[cur]){
                if(!used[to] && to != pre){
                    if(ch[to]*2 > m && chmax(max_ch, ch[to])) nx = to;
                }
            }
            if(nx == -1) break;
            pre = cur;
            cur = nx;
        }
        return cur;
    }

    void sub_build(int r, int par, vector<vector<int>> &tree){
        int centroid = find_centroid(r);
        tree[par].push_back(centroid);
        tree[centroid].push_back(par);
        used[centroid] = true;
        for(int to : g[centroid]){
            if(!used[to]) sub_build(to, centroid, tree);
        }
    }
};

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

void dfs_par(int v, vector<vector<int>> &g, vector<bool> &used, vector<int> &par, int p){
    par[v] = p;
    used[v] = true;
    for(int to : g[v]){
        if(!used[to]) dfs_par(to, g, used, par, v);
    }
}

void dfs_depth(int v, vector<vector<int>> &g, vector<bool> &used, vector<int> &depth, int d){
    used[v] = true;
    depth[v] = d;
    for(int to : g[v]){
        if(!used[to]) dfs_depth(to, g, used, depth, d+1);
    }
}

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto cd = CentrioidDecomposition(n, g);
    auto [c, tree] = cd.build_balanced_tree();
    auto lca = Lca(g, c);
    lca.init();
    vector<int> par(n);
    vector<int> depth(n);
    vector<bool> used(n);
    dfs_par(c, tree, used, par, -1);
    used.assign(n, false);
    dfs_depth(0, g, used, depth, 0);
    vector<int> dist_red(n, INF);
    for(int i = 0; i < n; i++) dist_red[i] = depth[i];
    while(m--){
        int t, v; cin >> t >> v; v--;
        if(t == 1){
            int cur = v;
            while(cur != -1){
                chmin(dist_red[cur], lca.dist(cur, v));
                cur = par[cur];
            }
        }else{
            int ans = INF;
            int cur = v;
            while(cur != -1){
                chmin(ans, lca.dist(cur, v)+dist_red[cur]);
                cur = par[cur];
            }
            cout << ans << endl;
        }
    }
}