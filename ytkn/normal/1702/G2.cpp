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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Lca lca(g, 0);
    lca.init();
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        vector<int> p(k);
        for(int i = 0; i < k; i++) {
            cin >> p[i]; p[i]--;
        }
        if(k <= 2){
            cout << "YES" << '\n';
            continue;
        }
        int min_depth = 2*n;
        int r = -1;
        int max_depth = -1;
        int s = -1;
        for(int v: p){
            if(chmax(max_depth, lca.depth[v])){
                s = v;
            }
            if(chmin(min_depth, lca.depth[v])){
                r = v;
            }
        }
        vector<bool> is_same_side(k);
        max_depth = -1;
        int t = -1;
        for(int i = 0; i < k; i++){
            int la = lca.lca(s, p[i]);
            if(la == p[i]) is_same_side[i] = true;
            else{
                is_same_side[i] = false;
                if(chmax(max_depth, lca.depth[p[i]])){
                    t = p[i];
                }
            }
        }
        if(t == -1){
            cout << "YES" << '\n';
            continue;
        }
        bool ok = true;
        for(int i = 0; i < k; i++){
            if(is_same_side[i]) continue;
            if(lca.lca(t, p[i]) != p[i]){
                ok = false;
                break;
            }
        }
        int rr = lca.lca(s, t);
        if(lca.depth[rr] > min_depth) ok = false;
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}