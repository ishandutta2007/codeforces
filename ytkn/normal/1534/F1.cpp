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

class Scc{
    public:
        int N;
        vector<vector<int>> G;
        vector<vector<int>> G_inv;
        vector<int> idx;

        Scc(int n){
            N = n;
            G = vector<vector<int>>(n, vector<int>());
            G_inv = vector<vector<int>>(n, vector<int>());
            used = vector<bool>(n, false);
            idx = vector<int>(n);
        }

        void add_edge(int from, int to){
            // cerr << from << "," << to << endl;
            G[from].push_back(to);
            G_inv[to].push_back(from);
        }

        vector<vector<int>> scc(){
            vector<vector<int>> ans;
            for(int i = 0; i < N; i++){
                if(!used[i]) dfs1(i);
            }
            clear();
            int cur = 0;
            for(int i = vs.size()-1; i >= 0; i--){
                if(!used[vs[i]]) {
                    dfs2(vs[i], cur);
                    cur++;
                    ans.push_back(buf);
                    buf.clear();
                }
            }
            return ans;
        }

    private:
        vector<bool> used;
        vector<int> vs;
        vector<int> buf;
        void clear(){
            for(int i = 0; i < N; i++) used[i] = false;
        }

        void dfs1(int v){
            used[v] = true;
            for(int i = 0; i < G[v].size(); i++){
                if(!used[G[v][i]]) dfs1(G[v][i]);
            }
            vs.push_back(v);
        }

        void dfs2(int v, int k){
            used[v] = true;
            idx[v] = k;
            for(int i = 0; i < G_inv[v].size(); i++){
                if(!used[G_inv[v][i]]) dfs2(G_inv[v][i], k);
            }
            buf.push_back(v);
        }
};

void dfs(int v, vector<vector<int>> &g, vector<bool> &used){
    used[v] = true;
    for(int to : g[v]){
        if(!used[to]) dfs(to, g, used);
    }
}

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    auto to_idx = [&](int i, int j){ return i*m+j; };
    auto to_ij = [&](int idx){ return P(idx/m, idx%m); };
    auto is_in_field = [&](int i, int j){ return i >= 0 && i < n && j >= 0 && j < m; };
    Scc scc(n*m);

    auto add_edge = [&](int idx, int i, int j){
        if(is_in_field(i, j) && s[i][j] == '#'){
            scc.add_edge(idx, to_idx(i, j));
        }
    };
    
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(s[i][j] == '.') continue;
            int idx = to_idx(i, j);
            add_edge(idx, i-1, j);
            for(int k = i; k < n; k++){
                add_edge(idx, k, j-1);
                add_edge(idx, k, j+1);
                if(i != k && s[k][j] == '#') {
                    scc.add_edge(idx, to_idx(k, j));
                    break;
                }
            }
        }
    }

    vector<bool> used(n*m);
    auto v = scc.scc();
    int ans = 0;
    for(auto u : v){
        if(u.empty()) continue;
        if(!used[u[0]]){
            auto [i, j] = to_ij(u[0]);
            if(s[i][j] == '#'){
                // cout << i << ' ' << j << endl;
                ans++;
                dfs(u[0], scc.G, used);
            }
        }
    }
    cout << ans << endl;
}