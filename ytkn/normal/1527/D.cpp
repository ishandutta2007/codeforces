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

void dfs(int v, vector<vector<int>> &g, vector<bool> &used, vector<ll> &ch){
    used[v] = true;
    ch[v]++;
    for(int to : g[v]){
        if(used[to]) continue;
        dfs(to, g, used, ch);
        ch[v] += ch[to];
    }
}

void solve(){
    ll n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> ans(n+1);
    vector<ll> ch(n);
    vector<ll> ch1(n);
    vector<bool> used(n);
    dfs(0, g, used, ch);
    used.assign(n, false);
    dfs(1, g, used, ch1);
    Lca lca(g, 0);
    lca.init();

    auto dist = [&](int u, int v){
        int l = lca.lca(u, v);
        return lca.depth[u]+lca.depth[v]-2*lca.depth[l];
    };

    int s = 0, t = 0;
    ans[0] = (n*(n-1))/2;
    ans[1] = (n*(n-1))/2;
    for(int to : g[0]){
        ans[1] -= (ch[to]*(ch[to]-1))/2;
    }
    
    for(int u = 1; u < n; u++){
        int dst = dist(s, t);
        int dtu = dist(t, u);
        int dus = dist(u, s);
        int mx = max({dst, dtu, dus});
        if(dst+dtu+dus == 2*mx){
            if(dst == mx){

            }else if(dtu == mx){
                s = u;
            }else{
                t = u;
            }
            if(lca.depth[s] > lca.depth[t]) swap(s, t);
            if(s == 0){
                ans[u+1] = ch1[0]*ch[t];
            }else{
                ans[u+1] = ch[s]*ch[t];
            }
        }else{
            break;
        }
    }
    // for(int x : ans) cout << x << ' ';
    // cout << endl;
    for(int i = 0; i < n; i++) cout << ans[i]-ans[i+1] << ' ';
    cout << ans[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--){
        solve();
    }
}