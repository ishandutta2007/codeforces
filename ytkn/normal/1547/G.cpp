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


void solve(){
    int n, m; cin >> n >> m;
    vector<bool> loop(n, false);
    Scc scc(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        if(a == b) loop[a] = true;
        else scc.add_edge(a, b);
    }
    auto u = scc.scc();
    int sz = u.size();
    vector<int> ans(sz);
    for(int i = 0; i < sz; i++){
        auto v = u[i];
        if(i == scc.idx[0]){
            if(v.size() > 1 || loop[0]) ans[i] = 3;
            else ans[i] = 1;
        }
        if(ans[i] > 0){
            if(v.size() > 1) ans[i] = 3;
            for(int x: v) {
                if(loop[x]) ans[i] = 3;
            }
        }
        for(int x: v){
            for(int to: scc.G[x]){
                if(ans[scc.idx[to]] == 1 && ans[i] == 1) ans[scc.idx[to]] = 2;
                else chmax(ans[scc.idx[to]], ans[i]);
            }
        }
    }
    for(int i = 0; i < n; i++) cout << (ans[scc.idx[i]] == 3 ? -1 : ans[scc.idx[i]]) << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}