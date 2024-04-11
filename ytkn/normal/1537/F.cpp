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

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> v(n), t(n), c(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++) {
        c[i] = t[i]-v[i];
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> used(n);
    vector<int> col(n);
    bool bip = true;

    function<void(int, int, int)> dfs = [&](int x, int par, int cl){
        used[x] = true;
        col[x] = cl;
        for(int to : g[x]){
            if(!used[to]) dfs(to, x, cl^1);
            else {
                if(col[to] == cl) bip = false;
            }
        }
        if(par != -1) {
            c[par] -= c[x];
            c[x] = 0;
        }
    };
    for(int i = 0; i < n; i++){
        if(!used[i]){
            dfs(i, -1, 0);
        }
    }

    if(bip){
        for(int i = 0; i < n; i++){
            if(c[i] != 0){
                cout << "NO" << endl;
                return;
            }
        }
    }
    if(accumulate(c.begin(), c.end(), 0ll)%2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}