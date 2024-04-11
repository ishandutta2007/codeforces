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

bool topological_sort(vector<vector<int>> g, vector<int> &order){
    int n = g.size();
    order.clear();
    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int v){
        used[v] = true;
        for(int to : g[v]){
            if(!used[to]) dfs(to);
        }
        order.push_back(v);
    };
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    reverse(order.begin(), order.end());
    vector<int> inv_order(n);
    for(int i = 0; i < n; i++) inv_order[order[i]] = i;
    for(int v = 0; v < n; v++){
        for(int u : g[v]){
            if(inv_order[v] > inv_order[u]) return false;
        }
    }
    return true;
}

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> g_inv(n);
    vector<int> in(n), out(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g_inv[v].push_back(u);
        in[v]++;
        out[u]++;
    }
    vector<int> ord;
    topological_sort(g, ord);
    auto dp = vec2d(n, 3, -inf);
    auto ok_start = [&](int i){
        return out[i] >= 2;
    };
    auto ok_middle = [&](int i){
        return out[i] >= 2 && in[i] >= 2;
    };
    auto ok_end = [&](int i){
        return in[i] >= 2;
    };
    for(int i: ord){
        if(ok_start(i)){
            dp[i][0] = 1;
        }
        for(int from: g_inv[i]){
            if(ok_middle(i)){
                chmax(dp[i][1], dp[from][0]+1);
                chmax(dp[i][1], dp[from][1]+1);
            }
            if(ok_end(i)){
                chmax(dp[i][2], dp[from][1]+1);
                chmax(dp[i][2], dp[from][0]+1);
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < n; i++) chmax(ans, dp[i][2]);
    cout << ans << endl;
}