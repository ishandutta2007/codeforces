#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
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


int n, m;
int a[200000], b[200000];

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
}

vector<int> G[200000];
vector<int> G_[200000];
bool used[200000];
bool used_[200000];

void dfs(int v){
    used[v] = true;
    for(int to: G[v]){
        if(!used[to]) dfs(to);
    }
}

void dfs_(int v){
    used_[v] = true;
    for(int to: G_[v]){
        if(!used_[to]) dfs_(to);
    }
}

void solve(){
    Scc scc1(n);
    for(int i = 0; i < m; i++){
        scc1.add_edge(a[i], b[i]);
        G[a[i]].push_back(b[i]);
        G_[b[i]].push_back(a[i]);
    }
    auto v = scc1.scc();
    for(auto u : v){
        if(u.size() > 1){
            cout << -1 << endl;
            return;
        }
    }
    string ans;
    vector<vector<int>> G_inv(n);
    for(int i = 0; i < m; i++){
        int l = min(a[i], b[i]);
        int r = max(a[i], b[i]);
        G_inv[r].push_back(l);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(G_inv[i].size() == 0 && !used[i] && !used_[i]) {
            ans += 'A';
            cnt++;
        } 
        else ans += 'E';
        dfs(i);
        dfs_(i);
    }
    cout << cnt << endl;
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}