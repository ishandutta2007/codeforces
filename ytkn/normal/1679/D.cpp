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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; ll k; cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> u(m), v(m);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
    }
    auto ok = [&](int x){
        vector<vector<int>> g(n);
        for(int i = 0; i < m; i++){
            if(a[u[i]] <= x && a[v[i]] <= x){
                g[u[i]].push_back(v[i]);
            }
        }
        vector<int> ord;
        if(!topological_sort(g, ord)) return true;
        vector<int> dp(n, 0);
        for(int v: ord){
            if(a[v] <= x) chmax(dp[v], 1);
            else continue;
            for(int to: g[v]){
                chmax(dp[to], dp[v]+1);
            }
        }
        return *max_element(dp.begin(), dp.end()) >= k;
    };
    int l = 0, r = 1e9;
    if(!ok(r)){
        cout << -1 << endl;
        return 0;
    }
    while(r-l > 1){
        int x = (l+r)/2;
        if(ok(x)) r = x;
        else l = x;
    }
    cout << r << endl;
}