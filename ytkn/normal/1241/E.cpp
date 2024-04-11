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
    edge(int to, ll cost): to(to), cost(cost) {}
};

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<edge>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; ll w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    auto dp = vec2d(n, 2, 0ll);
    vector<bool> seen(n);
    function<void(int)> dfs = [&](int v){
        seen[v] = true;
        ll min_sum = 0;
        vector<ll> gains;
        for(edge e: g[v]){
            if(seen[e.to]) continue;
            dfs(e.to);
            ll mn = dp[e.to][1];
            min_sum += mn;
            ll mx = max(dp[e.to][0]+e.cost, dp[e.to][1]);
            gains.push_back(mx-mn);
        }
        sort(gains.begin(), gains.end(), greater<ll>());
        dp[v][0] = min_sum;
        dp[v][1] = min_sum;
        ll sum = 0;
        for(int i = 0; i < gains.size(); i++){
            sum += gains[i];
            if(i+2 <= k){
                chmax(dp[v][0], min_sum+sum);
            }if(i+1 <= k){
                chmax(dp[v][1], min_sum+sum);
            }
        }
    };
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int q; cin >> q;
    while(q--){
        solve();
    }
}