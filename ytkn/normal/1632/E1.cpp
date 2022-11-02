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

using P = pair<int, int>;
const int inf = 1e9;

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dist = vec2d(n, n, -1);
    for(int i = 0; i < n; i++){
        auto seen = vector(n, false);
        queue<int> que;
        auto push = [&](int v, int d){
            if(seen[v]) return;
            seen[v] = true;
            que.push(v);
            dist[i][v] = d;
        };
        push(i, 0);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int to: g[v]){
                push(to, dist[i][v]+1);
            }
        }
        // print_vector(dist[i]);
    }
    auto use_bridge = vec2d(n, n, false);
    vector<int> ans(n+1, n);
    for(int i = 0; i < n; i++){
        // debug_value(i)
        vector<vector<int>> no_bridge(n+1);
        vector<vector<int>> bridge(n+1);
        for(int v = 0; v < n; v++){
            if(dist[i][v]+1 < dist[0][v]){
                use_bridge[i][v] = true;
                int x = dist[0][v]-dist[i][v];
                bridge[x-1].push_back(v);
                no_bridge[x].push_back(v);
            }else{
                no_bridge[0].push_back(v);
            }
        }
        vector<int> mx_bridge(n+1, -inf);
        vector<int> mx_no_bridge(n+1, -inf);
        for(int x = 0; x <= n; x++){
            if(x != 0) chmax(mx_no_bridge[x], mx_no_bridge[x-1]);
            for(int v: no_bridge[x]){
                chmax(mx_no_bridge[x], dist[0][v]);
            }
        }
        for(int x = n; x >= 0; x--){
            if(x != n) chmax(mx_bridge[x], mx_bridge[x+1]);
            for(int v: bridge[x]){
                chmax(mx_bridge[x], dist[i][v]);
            }
        }
        // print_vector(mx_bridge);
        // print_vector(mx_no_bridge);
        for(int x = 1; x <= n; x++){
            int tmp = max(mx_no_bridge[x], mx_bridge[x]+x);
            chmin(ans[x], tmp);
        }
    }
    for(int x = 1; x <= n; x++){
        cout << ans[x] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}