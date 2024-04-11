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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; i++) cin >> k[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int e; cin >> e; e--;
            g[i].push_back(e);
        }
    }
    auto index = [&](int i, int x){
        return i*2520+x;
    };
    Scc scc(n*2520);
    for(int i = 0; i < n; i++){
        for(int x = 0; x < 2520; x++){
            int to = g[i][x%g[i].size()];
            int nx = (x+k[to])%2520;
            nx += 2520;
            nx %= 2520;
            scc.add_edge(index(i, x), index(to, nx));
        }
    }
    auto u = scc.scc();
    int sz = u.size();
    vector<int> dp(n*2520, 0);
    for(int i = sz-1; i >= 0; i--){
        if(u[i].size() >= 2) {
            set<int> st;
            for(int v: u[i]) {
                st.insert(v/2520);
            }
            for(int v: u[i]) {
                dp[v] = st.size();
            }
        }else{
            int v = u[i][0];
            int from = scc.G[v][0];
            assert(scc.G[v].size() == 1);
            if(v == from){
                dp[v] = 1;
            }else{
                dp[v] = dp[from];
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int x, c; cin >> x >> c; x--;
        c += k[x];
        c %= 2520;
        c += 2520;
        c %= 2520;
        int idx = index(x, c);
        cout << dp[idx] << endl;
    }
}