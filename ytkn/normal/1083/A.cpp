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

struct edge{
    int to;
    ll cost;
    edge(int to, ll cost): to(to), cost(cost){}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<vector<edge>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v, c; cin >> u >> v >> c; u--; v--;
        g[u].push_back(edge(v, c));
        g[v].push_back(edge(u, c));
    }
    vector<vector<ll>> dp(n);
    vector<ll> mx(n);
    function<void(int, int)> dfs1 = [&](int v, int par){
        dp[v].resize(g[v].size()+1);
        dp[v].back() = w[v];
        for(int i = 0; i < g[v].size(); i++){
            edge e = g[v][i];
            if(e.to == par) continue;
            dfs1(e.to, v);
            chmax(dp[v][i], mx[e.to]+w[v]-e.cost);
        }
        mx[v] = *max_element(dp[v].begin(), dp[v].end());
    };
    dfs1(0, -1);
    vector<ll> ans = mx;
    function<void(int, int, ll)> dfs2 = [&](int v, int par, ll from_par){
        chmax(ans[v], from_par+w[v]);
        multiset<ll> st;
        for(int i = 0; i < g[v].size(); i++){
            edge e = g[v][i];
            if(e.to == par) {
                continue;
            }
            st.insert(dp[v][i]);
        }
        for(int i = 0; i < g[v].size(); i++){
            edge e = g[v][i];
            if(e.to == par) continue;
            st.erase(st.find(dp[v][i]));
            ll x = max(w[v]-e.cost, from_par+w[v]-e.cost);
            if(!st.empty()) chmax(x, *prev(st.end()) - e.cost);
            chmax(ans[v], x);
            dfs2(e.to, v, x);
            st.insert(dp[v][i]);
        }
    };
    dfs2(0, -1, 0);
    cout << *max_element(ans.begin(), ans.end()) << endl;
}