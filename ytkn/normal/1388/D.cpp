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

/**
 * gDAG: ordertrue
 * gDAG: false
 * 
 * verified(DAG): https://atcoder.jp/contests/dp/tasks/dp_g
 * verified(DAG): https://yukicoder.me/submissions/614434
 */ 
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
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] != -1){
            b[i]--;
            g[b[i]].push_back(i);
        }
    }
    vector<vector<int>> h(n);
    vector<ll> mx(n);
    function<void(int)> dfs = [&](int v){
        mx[v] = a[v];
        for(int to: g[v]){
            dfs(to);
            if(mx[to] < 0){
                h[v].push_back(to);
            }else{
                h[to].push_back(v);
                mx[v] += mx[to];
            }
        }
    };
    for(int i = 0; i < n; i++){
        if(b[i] != -1) continue;
        dfs(i);
    }
    vector<int> ord;
    assert(topological_sort(h, ord));
    ll ans = accumulate(mx.begin(), mx.end(), 0ll);
    cout << ans << endl;
    for(int x: ord) cout << x+1 << ' ';
    cout << endl;
}