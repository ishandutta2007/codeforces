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

void dfs_depth(int v, vector<vector<int>> &g, vector<int> &depth, vector<int> &par, int d){
    depth[v] = d;
    for(int to: g[v]){
        if(depth[to] == -1) {
            par[to] = v;
            dfs_depth(to, g, depth, par, d+1);
        }
    }
}

const ll inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        int v; cin >> v; v--;
        g[i].push_back(v);
        g[v].push_back(i);
    }
    vector<ll> a(n);
    for(int i = 1; i < n; i++) cin >> a[i];
    vector<int> depth(n, -1);
    vector<int> par(n, -1);
    dfs_depth(0, g, depth, par, 0);
    int max_d = *max_element(depth.begin(), depth.end());
    vector<vector<int>> vs(max_d+1);
    vector<vector<int>> as(max_d+1);
    for(int i = 0; i < n; i++) {
        vs[depth[i]].push_back(i);
        as[depth[i]].push_back(a[i]);
    }
    ll deepest_max = *max_element(as[max_d].begin(), as[max_d].end());
    ll deepest_min = *min_element(as[max_d].begin(), as[max_d].end());
    vector<ll> dp(n, -inf); 
    for(int v: vs[max_d]){
        chmax(dp[v], a[v]-deepest_min);
        chmax(dp[v], deepest_max-a[v]);
    }
    ll max_plus = -inf, max_minus = -inf;
    for(int d = max_d; d > 0; d--){
        max_plus = -inf, max_minus = -inf;
        ll next_max = *max_element(as[d-1].begin(), as[d-1].end());
        ll next_min = *min_element(as[d-1].begin(), as[d-1].end());
        for(int v: vs[d]){
            chmax(dp[par[v]], dp[v]+a[par[v]]-next_min);
            chmax(dp[par[v]], dp[v]-a[par[v]]+next_max);

            chmax(max_plus, dp[v]+a[par[v]]);
            chmax(max_minus, dp[v]-a[par[v]]);
        }
        for(int x: vs[d-1]){
            chmax(dp[x], max_plus-a[x]);
            chmax(dp[x], max_minus+a[x]);
        }
    }
    cout << dp[0] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}