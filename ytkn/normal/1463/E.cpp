#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;


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

    private:
        void dfs(int v, int p, int d){
            parent[0][v] = p;
            depth[v] = d;
            for(int i = 0; i < G[v].size(); i++){
                if(G[v][i] != p) dfs(G[v][i], v, d+1); 
            }
        }
};

bool topological_sort(vector<vector<int>> g, vector<int> &order){
    int n = g.size();
    order.clear();
    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int v){
        used[v] = true;
        for(int to : g[v]){
            if(!used[to]) dfs(to);
        }
        order.push_back(v);
    };
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    reverse(order.begin(), order.end());
    vector<int> inv_order(n);
    for(int i = 0; i < n; i++) inv_order[order[i]] = i;
    for(int v = 0; v < n; v++){
        for(int u : g[v]){
            if(inv_order[v] > inv_order[u]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector<int> p(n);
    int root = -1;
    vector<vector<int>> g(n);
    vector<vector<int>> h(n);
    for(int i = 0; i < n; i++){
        cin >> p[i]; p[i]--;
        if(p[i] == -1){
            root = i;
        }else{
            h[p[i]].push_back(i);
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
    }
    vector<bool> used_x(n), used_y(n);
    vector<int> x(k), y(k);
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i]; x[i]--; y[i]--;
        if(used_x[x[i]] || used_y[y[i]]){
            cout << 0 << endl;
            return 0;
        }
        h[x[i]].push_back(y[i]);
        used_x[x[i]] = true;
        used_y[y[i]] = true;
    }
    vector<int> buf;
    if(!topological_sort(h, buf)){
        cout << 0 << endl;
        return 0;
    }
    Lca lca(g, root);
    lca.init();
    vector<int> nx(n, -1);
    vector<int> pre(n, -1);
    vector<int> path_root(n, -1);
    for(int i = 0; i < k; i++){
        int lc = lca.lca(x[i], y[i]);
        nx[x[i]] = y[i];
        pre[y[i]] = x[i];
        if(x[i] == p[y[i]]) continue;
        if(x[i] == lc || y[i] == lc){
            cout << 0 << endl;
            return 0;
        }
    }
    map<int, int> compress;
    vector<int> inv_compress;
    int cnt = 0;
    int passed = 0;
    vector<int> depth(n);
    for(int i = 0; i < n; i++){
        if(pre[i] == -1){
            compress[i] = cnt;
            inv_compress.push_back(i);
            cnt++;
            depth[i] = 0;
            int d = 1;
            path_root[i] = i;
            int cur = i;
            passed++;
            while(nx[cur] != -1){
                cur = nx[cur];
                passed++;
                path_root[cur] = i;
                depth[cur] = d;
                d++;
            }
        }
    }
    if(passed != n){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> g_compress(cnt);
    for(int i = 0; i < n; i++){
        if(i != root){
            int v = compress[path_root[i]];
            int par = compress[path_root[p[i]]];
            g_compress[par].push_back(v);
        }
    }
    vector<int> ord;
    if(!topological_sort(g_compress, ord)){
        cout << 0 << endl;
        return 0;
    }
    for(int v : ord){
        int cur = inv_compress[v];
        while(cur != -1){
            cout << cur+1 << ' ';
            cur = nx[cur];
        }
    }
    cout << endl;
}