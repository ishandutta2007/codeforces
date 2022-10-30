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

vector<int> ga[300000];
vector<int> gb[300000];
int ord_b[300000];
int inv_ord_b[300000];
int ans;

void clear(int n){
    ans = 0;
    for(int i = 0; i < n; i++){
        ga[i].clear();
        gb[i].clear();
        ord_b[i] = 0;
        inv_ord_b[i] = 0;
    }
}

void dfs_b(int v, int &i){
    ord_b[v] = i;
    inv_ord_b[i] = v;
    i++;
    for(int to : gb[v]){
        dfs_b(to, i);
    }
}

void dfs_a(int v, set<int> &st, Lca &lca){
    int poped = -1, pushed = -1;
    if(st.empty()){
        st.insert(ord_b[v]);
        pushed = v;
    }else{
        auto p = st.upper_bound(ord_b[v]);
        if(p != st.begin()){
            p--;
            int u = inv_ord_b[*p];
            // cout << v << ' ' << u << endl;
            bool u_is_parent = (lca.lca(u, v) == u);
            if(u_is_parent){
                st.erase(ord_b[u]);
                poped = u;
            }
            p++;
        }
        p = st.upper_bound(ord_b[v]);
        if(p != st.end()){
            int u = inv_ord_b[*p];
            bool u_is_child = (lca.lca(u, v) == v);
            if(!u_is_child){
                st.insert(ord_b[v]);
                pushed = v;
            }
        }else{
            st.insert(ord_b[v]);
            pushed = v;
        }
    }
    // cout << v << ':';
    // for(int x : st) cout << inv_ord_b[x] << ' ';
    // cout << endl;
    chmax(ans, (int)st.size());
    for(int to : ga[v]){
        dfs_a(to, st, lca);
    }
    if(poped != -1) st.insert(ord_b[poped]);
    if(pushed != -1) st.erase(ord_b[pushed]);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 1; i < n; i++){
        cin >> a[i]; a[i]--;
        ga[a[i]].push_back(i);
    }
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        cin >> b[i]; b[i]--;
        gb[b[i]].push_back(i);

        g[b[i]].push_back(i);
        g[i].push_back(b[i]);
    }
    Lca lca(g, 0);
    lca.init();
    int i = 0;
    dfs_b(0, i);
    set<int> st;
    dfs_a(0, st, lca);
    cout << ans << endl;
    clear(n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}