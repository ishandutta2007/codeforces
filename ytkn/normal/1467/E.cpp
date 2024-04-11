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

vector<map<int, int>*> mp;

vector<vector<int>> g;
vector<bool> used;
vector<int> par;
vector<int> a;
map<int, int> all_cnt;

vector<int> imos;

void dfs(int v){
    used[v] = true;
    (*mp[v])[a[v]] = 1;
    bool ng_par = false;
    for(int to : g[v]){
        if(used[to]) continue;
        par[to] = v;
        dfs(to);
        if(mp[to]->count(a[v])) {
            imos[0]++;
            imos[to]--;
        }
        auto pl = mp[to]->size() > mp[v]->size() ? mp[to] : mp[v];
        auto pr = mp[to]->size() > mp[v]->size() ? mp[v] : mp[to];
        for(auto [x, c]: *pr){
            if(pl->count(x) > 0) (*pl)[x] += c;
            else (*pl)[x] = c;
        }
        mp[v] = pl;
    }
    if((*mp[v])[a[v]] < all_cnt[a[v]]) {
        imos[v]++;
    }
}

void dfs_ng(int v){
    used[v] = true;
    for(int to : g[v]){
        if(!used[to]){
            imos[to] += imos[v];
            dfs_ng(to);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    a.resize(n);
    mp.resize(n);
    imos.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(all_cnt.count(a[i])) all_cnt[a[i]]++;
        else all_cnt[a[i]] = 1;
    }
    vector<map<int, int>> v(n);
    for(int i = 0; i <  n; i++){
        mp[i] = &v[i];
    }
    g.resize(n);
    par.assign(n, -1);
    used.resize(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for(int i = 0; i < n; i++) used[i] = false;
    dfs_ng(0);
    int ans = n;
    for(int i = 0; i < n; i++){
        // cout << imos[i] << ' ';
        if(imos[i] > 0) ans--;
        // else debug(i);
    }
    // cout << endl;
    cout << ans << endl;
}