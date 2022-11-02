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
#include <tuple>

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

ll dp[3005][3005];
using P = pair<int, int>;
vector<vector<int>> g;
bool used[3005];
ll ch[3005];

ll cnt[3005][3005];
ll dst[3005][3005];
int rt[3005];

void clear(int n){
    for(int i = 0; i < n; i++){
        used[i] = false;
        ch[i] = 0;
    }
}

void dfs_cnt(int v, int root, int r, int d){
    // cout << "dfs_cnt(" << v << ", " << root << ", " << d << ")" << endl;
    used[v] = true;
    dst[root][v] = d;
    if(root == r){
        r = v;
    }
    rt[v] = r;
    
    ch[v] = 1;
    for(int to : g[v]){
        if(!used[to]){
            dfs_cnt(to, root, r, d+1);
            ch[v] += ch[to];
        }
    }
}

void preprocess(int root, int n){
    clear(n);
    dfs_cnt(root, root, root, 0);
    for(int v = 0; v < n; v++){
        cnt[root][v] = (n-ch[rt[v]])*ch[v];
    }
}

void dfs(int v){
    used[v] = true;
    ch[v] = 1;
    for(int to : g[v]){
        if(!used[to]){
            dfs(to);
            ch[v] += ch[to];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = 0;
    vector<vector<P>> p(n);
    auto dist = [&](int i, int j){
        // cout << "dist(" << i << ", " << j << ") = " << dst[i][j] << endl;
        return dst[i][j];
    };

    for(int i = 0; i < n; i++){
        preprocess(i, n);
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            p[dist(i, j)].push_back(P(i, j));
        }
    }

    

    auto calc = [&](int u, int v){
        // cout << "calc(" << u << ", " << v << ") = " << cnt[u][v] << endl;
        return cnt[u][v];
    };
    
    for(int d = 0; d < n; d++){
        for(auto [u, v] : p[d]){
            // cout << d << ": " << u << ',' << v << endl;
            for(int to : g[u]){
                if(dist(to, v) == d+1){
                    chmax(dp[min(to, v)][max(to, v)], dp[u][v]+calc(to, v));
                }
            }

            for(int to : g[v]){
                if(dist(to, u) == d+1){
                    chmax(dp[min(to, u)][max(to, u)], dp[u][v]+calc(to, u));                    
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}